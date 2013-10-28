#ifndef SudokuSolver_h
#define SudokuSolver_h

#include <string>

#include "SudokuPuzzle.h"

namespace Sudoku
{
	class SudokuSolver
	{//Solves a Sudoku puzzle.
		private:

		public:
			void solvePuzzle( SudokuPuzzle &puzzle );//Solves puzzle in-place.
	};
}

#endif /* SudokuSolver_h */
