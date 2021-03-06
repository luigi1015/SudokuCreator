#ifndef SudokuPuzzle_h
#define SudokuPuzzle_h

#include <vector>
#include <ostream>
#include <string>
#include "SudokuElement.h"

namespace Sudoku
{	
	class SudokuPuzzle
	{//A whole Sudoku puzzle
		private:
			SudokuElement elements[9][9];
			int getGridByCoord( int i );//Returns the grid number (0, 1 or 2) given a single coordinate. Use this twice for both x and y coordinates (use x to get horizontal grid number, y for vertical).
			void removePossibilityFromGrid( int xGrid, int yGrid, int val );//Removes val from the possibilities of the elements in the grid indicated by (xGrid, yGrid). Use getGridByCoord(...) to get xGrid and yGrid.
			void addPossibilityToGrid( int xGrid, int yGrid, int val );//Add val to the possibilities of the elements in the grid indicated by (xGrid, yGrid). Use getGridByCoord(...) to get xGrid and yGrid.
			void removePossibilityFromRow( int x, int val );//Removes possibility val from elements along row x.
			void addPossibilityToRow( int x, int val );//Add possibility val to elements along row x.
			void removePossibilityFromCol( int y, int val );//Removes possibility val from elements along column y.
			void addPossibilityToCol( int y, int val );//Add possibility val to elements along column y.
			
		public:
			//bool checkElement( int x, int y );//Checks an element to make sure it has a valid value.
			void setElementValue( int x, int y, int val );//Sets the value of the element and removes that value from the possibilities of the appropriate elements according to Sudoku rules.
			void removeElementValue( int x, int y );//Deletes the value of the element and adds that value back to the possibilities of the appropriate elements according to Sudoku rules.
			int getElementValue( int x, int y );//Returns the value of the element at coordinates x and y.
			bool isPossibleValue( int x, int y, int val );//Returns true if, according to it's records, the element at (x,y) can be set to value val. val, x, and y all should be between 1 and 9 inclusive.
			std::vector<int> getPossibleValues( int x, int y );//Returns a vector of the possible values at element (x, y).
			int getNumValues( int x, int y );//Returns the number of the possible values at element (x, y).
			friend std::ostream& operator<<( std::ostream &out, SudokuPuzzle &puzzle );//Stream overloading to work with cout.
			bool isSolved();//Returns whether the puzzle is solved.
			bool isValid();//Returns whether the puzzle is valid.
			SudokuElement& at( int x, int y );//Returns the element at coordinates x and y.
			std::string toString();//Return a string version of the puzzle meant for displaying as text or saving to a text file.
			void saveToFile( std::string filename );//Appends the output of toString() to a file indicated by filename.
	};
}

#endif /* SudokuPuzzle_h */
