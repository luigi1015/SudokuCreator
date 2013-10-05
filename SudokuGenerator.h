#ifndef SudokuGenerator_h
#define SudokuGenerator_h

#include "SudokuPuzzle.h"

namespace Sudoku
{
	class SudokuGenerator
	{//Generates Sudoku Puzzles.
		private:
			void savePuzzleToFile( SudokuPuzzle puzzle, std::string filename );//Save Sudoku puzzle puzzle to file filename.

		public:
			void generatePuzzles( std::string filename );//Create all the puzzles it can and saves them to file filename.
	}
}

#endif /* SudokuGenerator_h */
