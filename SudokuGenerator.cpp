#include "SudokuGenerator.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <exception>
#include <stdexcept>

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
		}
	}

	void SudokuGenerator::generatePuzzles( std::string filename )
	{//Create all the puzzles it can and saves them to file filename.
		SudokuPuzzle puzzle;
		
		puzzleGenerator( puzzle, 1, 1, filename);
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
			throw std::out_of_range( errorText.c_str() );
		}
		
		if( (y < 1) || (y > 9) )
		{//y is out of bounds, throw error.
			errorText = "In SudokuGenerator::puzzleGenerator( SudokuPuzzle &puzzle, int x, int y), y is out of bounds. x is ";
			errorText += y;
			errorText += " but should be between 1 and 9.\n";
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
			{//No the last element, go to the next element.
				if( x == 9 )
				{//Go to the next row since this is the last element of this row.
					puzzleGenerator( puzzle, 0, y+1, filename);
				}
				else
				{//Go to the element in this row.
					puzzleGenerator( puzzle, x+1, y, filename);
				}
			}
		}
	}
}

int main( int argc, char* argv[])
{
	if( argc != 2 )
	{//Didn't include the right arguments, error out.
		std::cerr << "Usage: " << argv[0] << " filename\n";
		return 1;
	}
	else
	{//Start the sudokuGenerator.
		Sudoku::SudokuGenerator gen;
		gen.generatePuzzles( argv[1] );
		return 0;
	}
}
