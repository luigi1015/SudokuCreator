#include "SudokuSolver.h"
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
	/*
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
	*/

	void SudokuSolver::solvePuzzle( SudokuPuzzle &puzzle )
	{//Solves puzzle in-place.
		int numPasses = 0;//The number of passes the method had gone through.
		//int maxPasses = 1000;//The max number of passes to try.
		int numSet = 0;//The number of elements set in a given pass.
		
		do
		{//While the puzzle isn't solved yet.
			numSet = 0;
			
			for( int i = 1; i <= 9; i++ )
			{//Go through the rows.
				for( int j = 1; j <= 9; j++ )
				{//Go through the elements in the row.
					if( !(puzzle.at(j, i).isSet()) && puzzle.getNumValues(j,i) == 1 )
					{//There is only one possible value for element (i,j), set it to that value.
						std::cout << "Setting element (" << j << "," << i << ") to " << puzzle.getPossibleValues(j,i).at(0) << std::endl /*<< puzzle << std::endl*/ << std::endl;
						puzzle.setElementValue( j, i, puzzle.getPossibleValues(j,i).at(0) );
						numSet++;
					}
				}
			}
			
			numPasses++;
		} while( !(puzzle.isSolved()) && (numSet > 0) );
		
		if( puzzle.isSolved() )
		{//Puzzle is solved! output it!
			std::cout << "Solved the puzzle!" << std::endl << puzzle;
		}
		else
		{//Puzzle wasn't solved, output error.
			std::cerr << "Stumped at pass " << numPasses << "." << std::endl << puzzle;
		}
	}
}

int main( int argc, char* argv[])
{
/*
	if( (argc < 2) || (argc > 3) )
	{//Didn't include the right arguments, error out.
		std::cerr << "Usage: " << argv[0] << " filename [maxPuzzles]\n";
		std::cerr << "Where maxPuzzles is the maximum number of puzzles you want the program to generate.\n";
		return 1;
	}
	else
	{//Start the sudokuGenerator.
*/
		Sudoku::SudokuPuzzle puz;
		Sudoku::SudokuSolver sol;
/*
		puz.setElementValue( 1, 1, 8 );
		puz.setElementValue( 1, 2, 4 );
		puz.setElementValue( 1, 3, 7 );
		puz.setElementValue( 1, 4, 6 );
		puz.setElementValue( 1, 5, 9 );
		puz.setElementValue( 1, 6, 1 );
		puz.setElementValue( 1, 7, 2 );
		puz.setElementValue( 1, 8, 3 );
		puz.setElementValue( 1, 9, 5 );
		puz.setElementValue( 2, 1, 1 );
		puz.setElementValue( 2, 2, 2 );
		puz.setElementValue( 2, 3, 6 );
		puz.setElementValue( 2, 4, 3 );
		puz.setElementValue( 2, 5, 5 );
		puz.setElementValue( 2, 6, 4 );
		puz.setElementValue( 2, 7, 7 );
		puz.setElementValue( 2, 8, 9 );
		puz.setElementValue( 2, 9, 8 );
		puz.setElementValue( 3, 1, 3 );
		puz.setElementValue( 3, 2, 9 );
		puz.setElementValue( 3, 3, 5 );
		puz.setElementValue( 3, 4, 2 );
		puz.setElementValue( 3, 5, 8 );
		puz.setElementValue( 3, 6, 3 );
		puz.setElementValue( 3, 7, 6 );
		puz.setElementValue( 3, 8, 5 );
		puz.setElementValue( 3, 9, 4 );
		puz.setElementValue( 4, 1, 9 );
		puz.setElementValue( 4, 2, 7 );
		puz.setElementValue( 4, 3, 1 );
		puz.setElementValue( 4, 4, 2 );
		puz.setElementValue( 4, 5, 8 );
		puz.setElementValue( 4, 6, 3 );
		puz.setElementValue( 4, 7, 6 );
		puz.setElementValue( 4, 8, 5 );
		puz.setElementValue( 4, 9, 4 );
		puz.setElementValue( 5, 1, 5 );
		puz.setElementValue( 5, 2, 6 );
		puz.setElementValue( 5, 3, 2 );
		puz.setElementValue( 5, 4, 4 );
		puz.setElementValue( 5, 5, 7 );
		puz.setElementValue( 5, 6, 9 );
		puz.setElementValue( 5, 7, 8 );
		puz.setElementValue( 5, 8, 1 );
		puz.setElementValue( 5, 9, 3 );
		puz.setElementValue( 6, 1, 4 );
		puz.setElementValue( 6, 2, 3 );
		puz.setElementValue( 6, 3, 8 );
		puz.setElementValue( 6, 4, 1 );
		puz.setElementValue( 6, 5, 6 );
		puz.setElementValue( 6, 6, 5 );
		puz.setElementValue( 6, 7, 9 );
		puz.setElementValue( 6, 8, 2 );
		puz.setElementValue( 6, 9, 7 );
		puz.setElementValue( 7, 1, 2 );
		puz.setElementValue( 7, 2, 1 );
		puz.setElementValue( 7, 3, 4 );
		puz.setElementValue( 7, 4, 7 );
		puz.setElementValue( 7, 5, 3 );
		puz.setElementValue( 7, 6, 6 );
		puz.setElementValue( 7, 7, 5 );
		puz.setElementValue( 7, 8, 8 );
		puz.setElementValue( 7, 9, 9 );
		puz.setElementValue( 8, 1, 7 );
		puz.setElementValue( 8, 2, 8 );
		puz.setElementValue( 8, 3, 9 );
		puz.setElementValue( 8, 4, 5 );
		puz.setElementValue( 8, 5, 4 );
		puz.setElementValue( 8, 6, 2 );
		puz.setElementValue( 8, 7, 3 );
		puz.setElementValue( 8, 8, 6 );
		puz.setElementValue( 8, 9, 1 );
		puz.setElementValue( 9, 1, 6 );
		puz.setElementValue( 9, 2, 5 );
		puz.setElementValue( 9, 3, 3 );
		puz.setElementValue( 9, 4, 9 );
		puz.setElementValue( 9, 5, 1 );
		puz.setElementValue( 9, 6, 8 );
		puz.setElementValue( 9, 7, 4 );
		puz.setElementValue( 9, 8, 7 );
		//puz.setElementValue( 9, 9, 2 );
*/

		puz.setElementValue( 1, 1, 4 );
		puz.setElementValue( 2, 1, 5 );
		puz.setElementValue( 4, 1, 9 );
		puz.setElementValue( 7, 1, 8 );
		puz.setElementValue( 8, 1, 3 );
		puz.setElementValue( 1, 2, 3 );
		puz.setElementValue( 6, 2, 1 );
		puz.setElementValue( 1, 3, 9 );
		puz.setElementValue( 3, 3, 6 );
		puz.setElementValue( 4, 3, 8 );
		puz.setElementValue( 5, 3, 2 );
		puz.setElementValue( 9, 3, 4 );
		puz.setElementValue( 3, 4, 7 );
		puz.setElementValue( 4, 4, 1 );
		puz.setElementValue( 8, 4, 5 );
		puz.setElementValue( 2, 5, 1 );
		puz.setElementValue( 4, 5, 2 );
		puz.setElementValue( 6, 5, 5 );
		puz.setElementValue( 8, 5, 8 );
		puz.setElementValue( 2, 6, 4 );
		puz.setElementValue( 6, 6, 7 );
		puz.setElementValue( 7, 6, 1 );
		puz.setElementValue( 1, 7, 5 );
		puz.setElementValue( 5, 7, 4 );
		puz.setElementValue( 6, 7, 8 );
		puz.setElementValue( 7, 7, 7 );
		puz.setElementValue( 9, 7, 1 );
		puz.setElementValue( 4, 8, 7 );
		puz.setElementValue( 9, 8, 5 );
		puz.setElementValue( 2, 9, 3 );
		puz.setElementValue( 3, 9, 4 );
		puz.setElementValue( 6, 9, 9 );
		puz.setElementValue( 8, 9, 6 );
		puz.setElementValue( 9, 9, 8 );
		
		std::cout << puz;

		sol.solvePuzzle( puz );

		return 0;
/*
	}
*/
}
