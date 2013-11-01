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
//#include <boost/numeric/ublas/matrix.hpp>
//#include <boost/numeric/ublas/io.hpp>
#include "Random/random.cpp"

namespace Sudoku
{
	void SudokuGenerator::generatePuzzles( std::string filename, long int max )
	{//Create up to max number of puzzles and saves them to file filename.
		SudokuPuzzle puzzle;
		int numPuzzles = 0;
		
		std::cout << "Creating " << max << " puzzles." << std::endl << std::endl;

		while( numPuzzles < max )
		{
			if( puzzleGenerator( puzzle, 1, 1, filename, max) )
			{//If generated a puzzle.
				numPuzzles++;
				std::cout << "Created puzzle number " << numPuzzles << "." << std::endl;
			}
		}
		//puzzleGeneratorNR( filename, max );
	}
	
	bool SudokuGenerator::puzzleGenerator( SudokuPuzzle puzzle, int x, int y, std::string &filename, long int max )
	{//Recursively generates Sudoku puzzles. x and y are the coordinates for this call to modify. x and y should both be between 1 and 9 inclusive. filename is the file to hold the puzzles. max is the maximum number of valid values for an element to go through before stopping.
/*
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
		if( possibleValues.size() == 0 )
		{
			std::cout << "Currently no possible values at element (" << x << ", " << y << ")." << std::endl << puzzle;
		}

		for( unsigned int i = 0; i < possibleValues.size(); i++ )
		{//Go through each of the possible values and place them in the puzzle. Then go on to the next element, if there is one, using a recursive call.
			//std::cout << "Setting value " << possibleValues.at(i) << " at element (" << x << ", " << y << ")." << std::endl;
			puzzle.setElementValue( x, y, possibleValues.at(i) );

			if( (x == 9) && (y == 9) )
			{//This is the last element, save the puzzle.
				puzzle.saveToFile( filename );
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

			puzzle.removeElementValue( x, y );
		}
*/
		std::string errorText;
		std::vector<int> possibleValues;
		int numValsTried = 0;//Number of valid values tried for this element.
		int numAttempts = 0;//Number of values attempted for this element.
		bool worked = false;//Whether a valid Sudoku puzzle has been found.
		//std::vector<int> possibleValues;

		//std::cout << "(" << x << "," << y << ")" << std::endl;

		if( (x < 1) || (x > 9) )
		{//x is out of bounds, throw error.
			errorText = "In SudokuGenerator::puzzleGenerator( SudokuPuzzle puzzle, int x, int y, std::string &filename, int max ), x is out of bounds. x is ";
			errorText += x;
			errorText += " but should be between 1 and 9.\n";
			std::cerr << errorText;
			throw std::out_of_range( errorText.c_str() );
		}

		if( (y < 1) || (y > 9) )
		{//y is out of bounds, throw error.
			errorText = "In SudokuGenerator::puzzleGenerator( SudokuPuzzle puzzle, int x, int y, std::string &filename, int max ), y is out of bounds. y is ";
			errorText += y;
			errorText += " but should be between 1 and 9.\n";
			std::cerr << errorText;
			throw std::out_of_range( errorText.c_str() );
		}
/*
		if( (max < 1) || (max > 9) )
		{//max is out of bounds, throw error.
			errorText = "In SudokuGenerator::puzzleGenerator( SudokuPuzzle puzzle, int x, int y, std::string &filename, int max ), max is out of bounds. max is ";
			errorText += max;
			errorText += " but should be between 1 and 9.\n";
			std::cerr << errorText;
			throw std::out_of_range( errorText.c_str() );
		}
*/
		//possibleValues = puzzle.getPossibleValues( x, y );
/*
		for( int i = 1; i <= 9; i++ )
		{
			if( puzzle.isPossibleValue(x, y, i) )
			{
				possibleValues.push_back(i);
			}
		}
*/

		//for( unsigned int i = 1; i <= 9; i++ )
		//for( unsigned int i = 1; (i <= 9) && (numValsTried < max); i++ )
		//while( (numValsTried < max) && (numAttempts < 3*puzzle.at(x,y).getNumPossibilities()) )
		//while( (numValsTried < max) && (numAttempts < 3*9) )
		//while( (numValsTried < 9) && (numAttempts < 3*9) && (worked == false) )
		//std::cout << "test 1: possibleValues.size() = " << possibleValues.size() << std::endl;
		//while( (possibleValues.size() > 0) && (worked == false) )
		while( (worked == false) && (puzzle.getNumValues(x,y) > 0) && (numAttempts <= puzzle.getNumValues(x,y)) )
		{//Randomly go through a possible value and place them in the puzzle. Then go on to the next element, if there is one, using a recursive call.
			//int i, j;
			int i;
			//int i = RNG::generateNumber<int>( 1, 9 );//Pick a random int between 1 and 9 inclusive.
			do
			{
/*
				//std::cout << "test 2" << std::endl;
				j = RNG::generateNumber<int>( 0, possibleValues.size()-1);
				//std::cout << "test 3" << std::endl;
				i = possibleValues.at(j);
				//std::cout << "test 4" << std::endl;
				possibleValues.erase( possibleValues.begin()+j-1 );
				//std::cout << "test 5" << std::endl;
*/
				i = RNG::generateNumber<int>( 1, 9);
			} while( !(puzzle.isPossibleValue(x,y,i)) );

			numAttempts++;
			
			//std::cout << "Generated random value " << i << " for element (" << x << ", " << y << ")." << std::endl;
			//std::cout << "Setting value " << i << " at element (" << x << ", " << y << ")." << std::endl;
			
			//if( puzzle.isPossibleValue(x,y,i) )
			//{
				//std::cout << "test 6" << std::endl;
				//std::cout << "Value works!" << std::endl << std::endl;
				numValsTried++;
				puzzle.setElementValue( x, y, i );
				//std::cout << "test 7" << std::endl;

				if( (x == 9) && (y == 9) )
				{//This is the last element, save the puzzle.
					//std::cout << puzzle << std::endl;
					//std::cout << "test 8a" << std::endl;

					if( puzzle.isValid() )
					{//It's a valid puzzle, save it.
						//std::cout << "Found valid puzzle!" << std::endl;
						puzzle.saveToFile( filename );
						//std::cout << "test 9a" << std::endl;
						return true;
					}
					else
					{
						//std::cout << "test 9b" << std::endl;
						return false;
					}
				}
				else
				{//Not the last element, go to the next element.
					//std::cout << "test 8b" << std::endl;
					if( x == 9 )
					{//Go to the next row since this is the last element of this row.
						//puzzleGenerator( puzzle, 1, y+1, filename, max);
						//std::cout << "test 9c" << std::endl;
						worked = puzzleGenerator( puzzle, 1, y+1, filename, max);
					}
					else
					{//Go to the element in this row.
						//std::cout << "test 9d" << std::endl;
						worked = puzzleGenerator( puzzle, x+1, y, filename, max);
					}
				}
				//std::cout << "test 10" << std::endl;

				puzzle.removeElementValue( x, y );
/*
			}
			else
			{
				//std::cout << "Value doesn't work. :(" << std::endl << std::endl;
			}
*/
		}
		//std::cout << "test 11" << std::endl;

		return worked;//Return whether it worked or not.
	}

	void SudokuGenerator::puzzleGeneratorNR( std::string filename, int limit )
	{//Non-recursively generates Sudoku puzzles. filename is the file to hold the puzzles. limit is the max amout of puzzles to create.
/*
		std::stack< std::vector<int> > previousValues;//A stack to hold the last previously used values on each of the previous elements.
		std::vector<int> pValues;
		SudokuPuzzle puzzle;//The sudoku puzzle.
		int x = 1;
		int y = 1;
		int currentValue = 1;
		int numPuzzles = 0;
		
		while( !((x == 9) && (y == 9)) && (numPuzzles < limit) )
		{
			if( pValues.size() > usedValues(x-1, y-1).size() )
			{//If haven't used all the possible values, use the next one and move on.
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
*/
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
		long int max = 2;
		
		if( argc == 3 )
		{
			max = atol(argv[2]);
		}
		
		gen.generatePuzzles( argv[1], max );
		
		return 0;
	}
}
