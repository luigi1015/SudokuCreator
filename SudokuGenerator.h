#ifndef SudokuGenerator_h
#define SudokuGenerator_h

#include <string>

#include "SudokuPuzzle.h"

namespace Sudoku
{
	class SudokuGenerator
	{//Generates Sudoku Puzzles.
		private:
			void savePuzzleToFile( SudokuPuzzle puzzle, std::string filename );//Save Sudoku puzzle puzzle to file filename.
			void puzzleGenerator( SudokuPuzzle &puzzle, int x, int y, std::string &filename);//Recursively generates Sudoku puzzles. x and y are the coordinates for this call to modify. x and y should both be between 1 and 9 inclusive. filename is the file to hold the puzzles.

		public:
			void generatePuzzles( std::string filename );//Create all the puzzles it can and saves them to file filename.
	};
}

#endif /* SudokuGenerator_h */
