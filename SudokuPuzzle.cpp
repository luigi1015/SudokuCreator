#include <stdexcept>
#include <vector>
#include "SudokuPuzzle.h"

namespace Sudoku
{	
	int SudokuPuzzle::getGridByCoord( int i )
	{//Returns the grid number (0, 1 or 2) given a single coordinate. Use this twice for both x and y coordinates (use x to get horizontal grid number, y for vertical).
		if( (i < 1) || (i > 9) )
		{//i is out of range, throw an exception.
			throw std::out_of_range( "In SudokuPuzzle::getGridByCoord( int i ), i is out of range. i should be between 1 and 9 inclusive." );
		}
		else
		{//i is in range, return the grid number.
			return (i-1)/3;
		}
	}

	void SudokuPuzzle::removePossibilityFromGrid( int xGrid, int yGrid, int val )
	{//Removes val from the possibilities of the elements in the grid indicated by (xGrid, yGrid). Use getGridByCoord(...) to get xGrid and yGrid.
		if( (xGrid < 0) || (xGrid > 2) )
		{//xGrid is out of range, throw an exception.
			throw std::out_of_range( "In SudokuPuzzle::removePossibilityFromGrid( int xGrid, int yGrid, int val ), xGrid is out of range. xGrid should be between 0 and 2 inclusive." );
		}
		else
		{//xGrid is in range, condinue checking.
			if( (yGrid < 0) || (xGrid > 2) )
			{//yGrid is out of range, throw an exception.
				throw std::out_of_range( "In SudokuPuzzle::removePossibilityFromGrid( int xGrid, int yGrid, int val ), yGrid is out of range. yGrid should be between 0 and 2 inclusive." );
			}
			else
			{//yGrid is in range, condinue checking.
				if( (val < 1) || (val > 9) )
				{//val is out of range, throw an exception.
					throw std::out_of_range( "In SudokuPuzzle::removePossibilityFromGrid( int xGrid, int yGrid, int val ), val is out of range. val should be between 1 and 9 inclusive." );
				}
				else
				{//val is in range, remove the possibilities.
					int x = getGridByCoord( xGrid );
					int y = getGridByCoord( yGrid );

					for( int i = 0; i < 3; i++ )
					{//Go through the x coords.
						for( int j = 0; j < 3; j++ )
						{//Go through the y coords.
							elements[i][j].setImpossible( val );
						}
					}
				}
			}
		}
	}

	void SudokuPuzzle::addPossibilityToGrid( int xGrid, int yGrid, int val )
	{//Add val to the possibilities of the elements in the grid indicated by (xGrid, yGrid). Use getGridByCoord(...) to get xGrid and yGrid.
		if( (xGrid < 0) || (xGrid > 2) )
		{//xGrid is out of range, throw an exception.
			throw std::out_of_range( "In SudokuPuzzle::addPossibilityFromGrid( int xGrid, int yGrid, int val ), xGrid is out of range. xGrid should be between 0 and 2 inclusive." );
		}
		else
		{//xGrid is in range, condinue checking.
			if( (yGrid < 0) || (xGrid > 2) )
			{//yGrid is out of range, throw an exception.
				throw std::out_of_range( "In SudokuPuzzle::addPossibilityFromGrid( int xGrid, int yGrid, int val ), yGrid is out of range. yGrid should be between 0 and 2 inclusive." );
			}
			else
			{//yGrid is in range, condinue checking.
				if( (val < 1) || (val > 9) )
				{//val is out of range, throw an exception.
					throw std::out_of_range( "In SudokuPuzzle::addPossibilityFromGrid( int xGrid, int yGrid, int val ), val is out of range. val should be between 1 and 9 inclusive." );
				}
				else
				{//val is in range, remove the possibilities.
					int x = getGridByCoord( xGrid );
					int y = getGridByCoord( yGrid );

					for( int i = 0; i < 3; i++ )
					{//Go through the x coords.
						for( int j = 0; j < 3; j++ )
						{//Go through the y coords.
							elements[i][j].setPossible( val );
						}
					}
				}
			}
		}
	}

	void SudokuPuzzle::removePossibilityFromRow( int x, int val )
	{//Removes possibility val from elements along row x.
		if( (x < 1) || (x > 9) )
		{//x is out of range, throw an exception.
			throw std::out_of_range( "In SudokuPuzzle::removePossibilityFromRow( int x, int val ), x is out of range. x should be between 1 and 9 inclusive." );
		}
		else
		{//x is in range, continue checking.
			if( (val < 1) || (val > 9) )
			{//val is out of range, throw an exception.
				throw std::out_of_range( "In SudokuPuzzle::removePossibilityFromRow( int x, int val ), val is out of range. val should be between 1 and 9 inclusive." );
			}
			else
			{//val is in range, remove possibility.
				for( int j = 0; j < 9; j++ )
				{//Go through the elements in the row.
					elements[x][j].setImpossible( val );
				}
			}
		}
	}

	void SudokuPuzzle::addPossibilityToRow( int x, int val )
	{//Add possibility val to elements along row x.
		if( (x < 1) || (x > 9) )
		{//x is out of range, throw an exception.
			throw std::out_of_range( "In SudokuPuzzle::addPossibilityFromRow( int x, int val ), x is out of range. x should be between 1 and 9 inclusive." );
		}
		else
		{//x is in range, continue checking.
			if( (val < 1) || (val > 9) )
			{//val is out of range, throw an exception.
				throw std::out_of_range( "In SudokuPuzzle::addPossibilityFromRow( int x, int val ), val is out of range. val should be between 1 and 9 inclusive." );
			}
			else
			{//val is in range, add possibility.
				for( int j = 0; j < 9; j++ )
				{//Go through the elements in the row.
					elements[x][j].setPossible( val );
				}
			}
		}
	}

	void SudokuPuzzle::removePossibilityFromCol( int y, int val )
	{//Removes possibility val from elements along column y.
		if( (y < 1) || (y > 9) )
		{//y is out of range, throw an exception.
			throw std::out_of_range( "In SudokuPuzzle::removePossibilityFromCol( int y, int val ), y is out of range. y should be between 1 and 9 inclusive." );
		}
		else
		{//y is in range, continue checking.
			if( (val < 1) || (val > 9) )
			{//val is out of range, throw an exception.
				throw std::out_of_range( "In SudokuPuzzle::removePossibilityFromCol( int y, int val ), val is out of range. val should be between 1 and 9 inclusive." );
			}
			else
			{//val is in range, remove possibility.
				for( int i = 0; i < 9; i++ )
				{//Go through the elements in the row.
					elements[i][y].setImpossible( val );
				}
			}
		}
	}

	void SudokuPuzzle::addPossibilityToCol( int y, int val )
	{//Add possibility val to elements along column y.
		if( (y < 1) || (y > 9) )
		{//y is out of range, throw an exception.
			throw std::out_of_range( "In SudokuPuzzle::addPossibilityFromCol( int y, int val ), y is out of range. y should be between 1 and 9 inclusive." );
		}
		else
		{//y is in range, continue checking.
			if( (val < 1) || (val > 9) )
			{//val is out of range, throw an exception.
				throw std::out_of_range( "In SudokuPuzzle::addPossibilityFromCol( int y, int val ), val is out of range. val should be between 1 and 9 inclusive." );
			}
			else
			{//val is in range, remove possibility.
				for( int i = 0; i < 9; i++ )
				{//Go through the elements in the row.
					elements[i][y].setPossible( val );
				}
			}
		}
	}

	//bool SudokuPuzzle::checkElement( int x, int y );//Checks an element to make sure it has a valid value.

	void SudokuPuzzle::setElementValue( int x, int y, int val )
	{//Sets the value of the element and removes that value from the possibilities of the appropriate elements according to Sudoku rules.
		if( (x < 1) || (x > 9) )
		{//x is out of range, throw an exception.
			throw std::out_of_range( "In SudokuPuzzle::setElementValue( int x, int y, int val ), x is out of range. x should be between 1 and 9 inclusive." );
		}
		else
		{//x is in range, continue checking.
			if( (y < 1) || (y > 9) )
			{//y is out of range, throw an exception.
				throw std::out_of_range( "In SudokuPuzzle::setElementValue( int x, int y, int val ), y is out of range. y should be between 1 and 9 inclusive." );
			}
			else
			{//y is in range, continue checking.
				if( (val < 1) || (val > 9) )
				{//val is out of range, throw an exception.
					throw std::out_of_range( "In SudokuPuzzle::setElementValue( int x, int y, int val ), val is out of range. val should be between 1 and 9 inclusive." );
				}
				else
				{//val is in range, set value.
					elements[x][y].setValue( val );
					removePossibilityFromCol( y, val );
					removePossibilityFromRow( x, val );
					removePossibilityFromGrid( getGridByCoord(x), getGridByCoord(y), val )
				}
			}
		}
	}

	bool SudokuPuzzle::isPossibleValue( int x, int y, int val )
	{//Returns true if, according to it's records, the element at (x,y) can be set to value val. val, x, and y all should be between 1 and 9 inclusive.
		if( (x < 1) || (x > 9) )
		{//x is out of range, throw an exception.
			throw std::out_of_range( "In SudokuPuzzle::setElementValue( int x, int y, int val ), x is out of range. x should be between 1 and 9 inclusive." );
		}
		else
		{//x is in range, continue checking.
			if( (y < 1) || (y > 9) )
			{//y is out of range, throw an exception.
				throw std::out_of_range( "In SudokuPuzzle::setElementValue( int x, int y, int val ), y is out of range. y should be between 1 and 9 inclusive." );
			}
			else
			{//y is in range, continue checking.
				if( (val < 1) || (val > 9) )
				{//val is out of range, throw an exception.
					throw std::out_of_range( "In SudokuPuzzle::setElementValue( int x, int y, int val ), val is out of range. val should be between 1 and 9 inclusive." );
				}
				else
				{//val is in range, return value.
					return elements[x][y].isPossibleValue( val );
				}
			}
		}

	std::vector<int> SudokuPuzzle::getPossibleValues( int x, int y )
	{//Returns a vector of the the possible values.
		if( (y < 1) || (y > 9) )
		{//y is out of range, throw an exception.
			throw std::out_of_range( "In SudokuPuzzle::getPossibleValues( int y, int val ), y is out of range. y should be between 1 and 9 inclusive." );
		}
		else
		{//y is in range, continue checking.
			if( (val < 1) || (val > 9) )
			{//val is out of range, throw an exception.
				throw std::out_of_range( "In SudokuPuzzle::getPossibleValues( int y, int val ), val is out of range. val should be between 1 and 9 inclusive." );
			}
			else
			{//val is in range, return the value.
				return elements[x][y].possibleVals();
			}
		}
	}

	int getElementValue( int x, int y )
	{//Returns the value of the element at coordinates x and y.
		if( (x < 1) || (x > 9) )
		{//x is out of range, throw an exception.
			throw std::out_of_range( "In SudokuPuzzle::getElementValue( int x, int y ), x is out of range. x should be between 1 and 9 inclusive." );
		}
		else
		{//x is in range, continue checking.
			if( (y < 1) || (y > 9) )
			{//y is out of range, throw an exception.
				throw std::out_of_range( "In SudokuPuzzle::getElementValue( int x, int y ), y is out of range. y should be between 1 and 9 inclusive." );
			}
			else
			{//y is in range, check if the element is set.
				if( elements[x][y].getValue() == 0 )
				{//The element isn't set, throw an exception.
					throw "In SudokuPuzzle::getElementValue( int x, int y ), the element at x,y isn't set.";
				}
				else
				{
					return elements[x][y].getValue();
				}
			}
		}
	}
}
