#ifndef SudokuGenerator_h
#define SudokuGenerator_h

#include <string>

#include "SudokuPuzzle.h"

namespace Sudoku
{
	class SudokuGenerator
	{//Generates Sudoku Puzzles.
		private:
			void puzzleGenerator( SudokuPuzzle puzzle, int x, int y, std::string &filename);//Recursively generates Sudoku puzzles. x and y are the coordinates for this call to modify. x and y should both be between 1 and 9 inclusive. filename is the file to hold the puzzles.
			void puzzleGeneratorNR( std::string filename, int limit );//Non-recursively generates Sudoku puzzles. filename is the file to hold the puzzles. limit is the max amout of puzzles to create.

		public:
			void generatePuzzles( std::string filename, int max );//Create all the puzzles it can and saves them to file filename.
	};
}

#endif /* SudokuGenerator_h */
