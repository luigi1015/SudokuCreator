#include "SudokuGenerator.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <exception>
#include <stdexcept>
//#include <sstream>
#include <stack>
#include <stdlib.h> 
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

namespace Sudoku
{
	void SudokuGenerator::savePuzzleToFile( SudokuPuzzle puzzle, std::string filename )
	{//Save Sudoku puzzle puzzle to file filename.
		std::ofstream saveFile;
		std::string errorText;

		try
		{
			saveFile.open( filename.c_str() );
			for( int i = 0; i < 9; i++ )
			{//Go through each element and print them out to the file.
				for( int j = 0; j < 9; i++ )
				{
					saveFile << puzzle.getElementValue( i+1, j+1 ) << " ";
				}

				saveFile << "\n";
			}

			saveFile << "-----------------------------------------------\n";//To indicate the end of the puzzle.

			saveFile.close();
		}
		catch( std::exception e )
		{
			errorText = "In SudokuGenerator::savePuzzleToFile( SudokuPuzzle puzzle, std::string filename ), got an error trying to save to file ";
			errorText += filename;
			errorText += " : ";
			errorText += e.what();
			std::cerr << errorText;
		}
	}

	void SudokuGenerator::generatePuzzles( std::string filename, int max )
	{//Create all the puzzles it can and saves them to file filename.
		SudokuPuzzle puzzle;
		
		puzzleGenerator( puzzle, 1, 1, filename);
		//puzzleGeneratorNR( filename, max );
	}
	
	void SudokuGenerator::puzzleGenerator( SudokuPuzzle &puzzle, int x, int y, std::string &filename)
	{//Recursively generates Sudoku puzzles. x and y are the coordinates for this call to modify. x and y should both be between 1 and 9 inclusive. filename is the file to hold the puzzles.
		std::string errorText;
		std::vector<int> possibleValues;
		
		if( (x < 1) || (x > 9) )
		{//x is out of bounds, throw error.
			errorText = "In SudokuGenerator::puzzleGenerator( SudokuPuzzle &puzzle, int x, int y), x is out of bounds. x is ";
			errorText += x;
			errorText += " but should be between 1 and 9.\n";
			std::cerr << errorText;
			throw std::out_of_range( errorText.c_str() );
		}
		
		if( (y < 1) || (y > 9) )
		{//y is out of bounds, throw error.
			errorText = "In SudokuGenerator::puzzleGenerator( SudokuPuzzle &puzzle, int x, int y), y is out of bounds. y is ";
			errorText += y;
			errorText += " but should be between 1 and 9.\n";
			std::cerr << errorText;
			throw std::out_of_range( errorText.c_str() );
		}
		
		possibleValues = puzzle.getPossibleValues( x, y );
		
		for( unsigned int i = 0; i < possibleValues.size(); i++ )
		{//Go through each of the possible values and place them in the puzzle. Then go on to the next element, if there is one, using a recursive call.
			puzzle.setElementValue( x, y, possibleValues.at(i) );
			
			if( (x == 9) && (y == 9) )
			{//This is the last element, save the puzzle.
				savePuzzleToFile( puzzle, filename );
			}
			else
			{//Not the last element, go to the next element.
				if( x == 9 )
				{//Go to the next row since this is the last element of this row.
					puzzleGenerator( puzzle, 1, y+1, filename);
				}
				else
				{//Go to the element in this row.
					puzzleGenerator( puzzle, x+1, y, filename);
				}
			}
		}
	}
	
	void SudokuGenerator::puzzleGeneratorNR( std::string filename, int limit )
	{//Non-recursively generates Sudoku puzzles. filename is the file to hold the puzzles. limit is the max amout of puzzles to create.
		//std::vector<int> possibleValues;//Possible values for an element.
		//std::stack< std::vector<int> > pValues;//A stack to hold the previous possible values.
		//std::vector<int> usedValues[9][9];
		boost::numeric::ublas::matrix< std::vector<int> > usedValues(9, 9);//Create a 9x9 matrix of vectors filled with the used values as ints.
		std::vector<int> pValues;
		SudokuPuzzle puzzle;//The sudoku puzzle.
		int x = 1;
		int y = 1;
		int numPuzzles = 0;
		
		while( !((x == 9) && (y == 9)) && (numPuzzles < limit) )
		{
			pValues = puzzle.getPossibleValues( x, y );
			//if( pValues.size() > usedValues[x-1][y-1].size() )
			if( pValues.size() > usedValues(x-1, y-1).size() )
			{//If haven't used all the possible values, use the next one and move on.
				//puzzle.setElementValue( x, y, pValues.at( usedValues[x-1][y-1].size() ) );
				puzzle.setElementValue( x, y, pValues.at( usedValues(x-1, y-1).size() ) );
				//usedValues[x-1][y-1].push_back( puzzle.getElementValue( x, y ) );
				usedValues(x-1, y-1).push_back( puzzle.getElementValue( x, y ) );
				if( (x == 9) && (y == 9) )
				{//This is the last element, save the puzzle.
					savePuzzleToFile( puzzle, filename );
				}
				else
				{//Not the last element, go to the next element.
					if( x == 9 )
					{//Go to the next row since this is the last element of this row.
						x = 1;
						y++;
					}
					else
					{//Go to the next element in this row.
						x++;
					}
				}
			}
			else
			{//Used up all the possible values for this element. Go back to the last element and start using the remaining possible values.
				//usedValues[x-1][y-1].clear();
				usedValues(x-1, y-1).clear();
				
				if( (x == 1) && (y == 1) )
				{//This is the first element, should mean all possible Sudoku puzzles have been explored. Exit the method.
					numPuzzles = limit;//Will cause an exit of the while loop.
				}
				else
				{//Not the first element, go to the previous element.
					if( x == 1 )
					{//Go to the last row since this is the first element of this row.
						x = 9;
						y--;
					}
					else
					{//Go to the previous element in this row.
						x--;
					}
				}
			}
		}
	}
}

int main( int argc, char* argv[])
{
	if( (argc < 2) || (argc > 3) )
	{//Didn't include the right arguments, error out.
		std::cerr << "Usage: " << argv[0] << " filename [maxPuzzles]\n";
		std::cerr << "Where maxPuzzles is the maximum number of puzzles you want the program to generate.\n";
		return 1;
	}
	else
	{//Start the sudokuGenerator.
		Sudoku::SudokuGenerator gen;
		int max = 100;
		
		if( argc == 3 )
		{
			max = atoi(argv[2]);
		}
		
		gen.generatePuzzles( argv[1], max );
		
		return 0;
	}
}
