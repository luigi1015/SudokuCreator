#include "SudokuGenerator.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <exception>

namespace Sudoku
{
	void SudokuGenerator::savePuzzleToFile( SudokuPuzzle puzzle, std::string filename )
	{//Save Sudoku puzzle puzzle to file filename.
		std::ofstream saveFile;
		std::string errorText;

		try
		{
			saveFile.open( filename );
			for( int i = 0; i < 9; i++ )
			{//Go through each element and print them out to the file.
				for( int j = 0; j < 9; i++ )
				{
					saveFile << puzzle.getElementValue( i+1, j+1 ) << " ";
				}

				saveFile << "\n";
			}

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
	}
}
