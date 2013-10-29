#include <stdexcept>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
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
		{//xGrid is in range, continue checking.
			if( (yGrid < 0) || (xGrid > 2) )
			{//yGrid is out of range, throw an exception.
				throw std::out_of_range( "In SudokuPuzzle::removePossibilityFromGrid( int xGrid, int yGrid, int val ), yGrid is out of range. yGrid should be between 0 and 2 inclusive." );
			}
			else
			{//yGrid is in range, continue checking.
				if( (val < 1) || (val > 9) )
				{//val is out of range, throw an exception.
					throw std::out_of_range( "In SudokuPuzzle::removePossibilityFromGrid( int xGrid, int yGrid, int val ), val is out of range. val should be between 1 and 9 inclusive." );
				}
				else
				{//val is in range, remove the possibilities.

					for( int i = 1; i <= 3; i++ )
					{//Go through the x coords.
						for( int j = 1; j <= 3; j++ )
						{//Go through the y coords.
							//elements[xGrid*3+i][yGrid*3+j].setImpossible( val );
							at(xGrid*3+i, yGrid*3+j).setImpossible( val );
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
		{//xGrid is in range, continue checking.
			if( (yGrid < 0) || (xGrid > 2) )
			{//yGrid is out of range, throw an exception.
				throw std::out_of_range( "In SudokuPuzzle::addPossibilityFromGrid( int xGrid, int yGrid, int val ), yGrid is out of range. yGrid should be between 0 and 2 inclusive." );
			}
			else
			{//yGrid is in range, continue checking.
				if( (val < 1) || (val > 9) )
				{//val is out of range, throw an exception.
					throw std::out_of_range( "In SudokuPuzzle::addPossibilityFromGrid( int xGrid, int yGrid, int val ), val is out of range. val should be between 1 and 9 inclusive." );
				}
				else
				{//val is in range, remove the possibilities.
					//int x = getGridByCoord( xGrid );
					//int y = getGridByCoord( yGrid );

					for( int i = 1; i <= 3; i++ )
					{//Go through the x coords.
						for( int j = 1; j <= 3; j++ )
						{//Go through the y coords.
							//elements[i*3+x][j*3+y].setPossible( val );
							at(xGrid*3+i, yGrid*3+j).setPossible( val );
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
				for( int j = 1; j <= 9; j++ )
				{//Go through the elements in the row.
					//elements[x-1][j].setImpossible( val );
					at(x, j).setImpossible( val );
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
				for( int j = 1; j <= 9; j++ )
				{//Go through the elements in the row.
					//elements[x-1][j].setPossible( val );
					at(x, j).setPossible( val );
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
				for( int i = 1; i <= 9; i++ )
				{//Go through the elements in the row.
					//elements[i][y-1].setImpossible( val );
					at(i, y).setImpossible( val );
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
				for( int i = 1; i <= 9; i++ )
				{//Go through the elements in the row.
					//elements[i][y-1].setPossible( val );
					at(i, y).setPossible( val );
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
					if( !(isPossibleValue(x,y,val)) )
					{//If the value isn't possible according to the records, throw an exception.
						//std::cerr << toString();
						throw std::out_of_range( "In SudokuPuzzle::setElementValue( int x, int y, int val ), val is out of the range of possible values according to the records." );
					}
					else
					{//The element can be set to val, set value.
						//elements[x-1][y-1].setValue( val );
						at(x, y).setValue( val );
						removePossibilityFromCol( y, val );
						removePossibilityFromRow( x, val );
						removePossibilityFromGrid( getGridByCoord(x), getGridByCoord(y), val );
					}
				}
			}
		}
	}

	void SudokuPuzzle::removeElementValue( int x, int y )
	{//Deletes the value of the element and adds that value back to the possibilities of the appropriate elements according to Sudoku rules.
		int val = 0;
		
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
			{//y is in range, remove value.
				if( at(x,y).isSet() )
				{
					//val = elements[x-1][y-1].getValue();
					//elements[x-1][y-1].clear();
					val = at(x, y).getValue();
					//at(x, y).clear();
					at(x, y).clearValue();
					addPossibilityToCol( y, val );
					addPossibilityToRow( x, val );
					addPossibilityToGrid( getGridByCoord(x), getGridByCoord(y), val );
				}
			}
		}
	}

	bool SudokuPuzzle::isPossibleValue( int x, int y, int val )
	{//Returns true if, according to it's records, the element at (x,y) can be set to value val. val, x, and y all should be between 1 and 9 inclusive.
/*
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
					//return elements[x-1][y-1].isPossibleValue( val );
					return at(x, y).isPossibleValue( val );
				}
			}
		}
*/
		
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
					for( int i = 1; i <= 9; i++ )
					{//Go through the row to check if value is there.
						if( (x != i) && (at(i, y).isSet()) && (at(i, y).getValue() == val) )
						{//Found another value, making val invalid.
							return false;
						}
					}

					for( int j = 1; j <= 9; j++ )
					{//Go through the column to check if value is there.
						if( (y != j) && (at(x, j).isSet()) && (at(x, j).getValue() == val) )
						{//Found another value, making val invalid.
							return false;
						}
					}

					for( int i = getGridByCoord(x)*3+1; i <= getGridByCoord(x)*3+3; i++ )
					{//Go through the grid to check if value is there.
						for( int j = getGridByCoord(y)*3+1; j <= getGridByCoord(y)*3+3; j++ )
						{
							if( !((x == i) && (y == j)) && (at(i, j).isSet()) && (at(i, j).getValue() == val) )
							{//Found another value, making val invalid.
								return false;
							}
						}
					}
				}
			}
		}

		//Passed all the tests, it's possible.
		return true;
	}

	std::vector<int> SudokuPuzzle::getPossibleValues( int x, int y )
	{//Returns a vector of the the possible values.
/*
		if( (x < 1) || (x > 9) )
		{//y is out of range, throw an exception.
			throw std::out_of_range( "In SudokuPuzzle::getPossibleValues( int y, int val ), y is out of range. x should be between 1 and 9 inclusive." );
		}
		else
		{//y is in range, continue checking.
			if( (y < 1) || (y > 9) )
			{//val is out of range, throw an exception.
				throw std::out_of_range( "In SudokuPuzzle::getPossibleValues( int y, int val ), y is out of range. val should be between 1 and 9 inclusive." );
			}
			else
			{//val is in range, return the value.
				//return elements[x-1][y-1].possibleVals();
				return at(x, y).possibleVals();
			}
		}
*/
		std::vector<int> vals;

		if( (x < 1) || (x > 9) )
		{//y is out of range, throw an exception.
			throw std::out_of_range( "In SudokuPuzzle::getPossibleValues( int y, int val ), y is out of range. x should be between 1 and 9 inclusive." );
		}
		else
		{//y is in range, continue checking.
			if( (y < 1) || (y > 9) )
			{//val is out of range, throw an exception.
				throw std::out_of_range( "In SudokuPuzzle::getPossibleValues( int y, int val ), y is out of range. val should be between 1 and 9 inclusive." );
			}
			else
			{//val is in range, return the value.
				for( int i = 1; i <= 9; i++ )
				{//Go through all the values and test them. If they test ok, put them in the vector for return.
					if( isPossibleValue(x,y,i) )
					{
						vals.push_back( i );
					}
				}
			}
		}

		return vals;
	}

	int SudokuPuzzle::getNumValues( int x, int y )
	{//Returns a vector of the the possible values.
/*
		if( (x < 1) || (x > 9) )
		{//y is out of range, throw an exception.
			throw std::out_of_range( "In SudokuPuzzle::getPossibleValues( int y, int val ), y is out of range. x should be between 1 and 9 inclusive." );
		}
		else
		{//y is in range, continue checking.
			if( (y < 1) || (y > 9) )
			{//val is out of range, throw an exception.
				throw std::out_of_range( "In SudokuPuzzle::getPossibleValues( int y, int val ), y is out of range. val should be between 1 and 9 inclusive." );
			}
			else
			{//val is in range, return the value.
				//return elements[x-1][y-1].getNumPossibilities();
				return at(x, y).getNumPossibilities();
			}
		}
*/
		if( (x < 1) || (x > 9) )
		{//y is out of range, throw an exception.
			throw std::out_of_range( "In SudokuPuzzle::getPossibleValues( int y, int val ), y is out of range. x should be between 1 and 9 inclusive." );
		}
		else
		{//y is in range, continue checking.
			if( (y < 1) || (y > 9) )
			{//val is out of range, throw an exception.
				throw std::out_of_range( "In SudokuPuzzle::getPossibleValues( int y, int val ), y is out of range. val should be between 1 and 9 inclusive." );
			}
			else
			{//val is in range, return the value.
				return getPossibleValues(x,y).size();
			}
		}
	}

	int SudokuPuzzle::getElementValue( int x, int y )
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
				//if( !(elements[x-1][y-1].isSet()) )
				if( !(at(x, y).isSet()) )
				{//The element isn't set, throw an exception.
					throw std::runtime_error( "In SudokuPuzzle::getElementValue( int x, int y ), the element at x,y isn't set." );
				}
				else
				{
					//return elements[x-1][y-1].getValue();
					return at(x, y).getValue();
				}
			}
		}
	}

	std::ostream& operator<<( std::ostream &out, SudokuPuzzle &puzzle )
	{//Stream overloading to work with cout.
		/*
		for( int i = 1; i <= 9; i++ )
		{//Go through the rows.
			for( int j = 1; j <= 9; j++ )
			{//Go through the elements in the row.
				//if( puzzle.elements[j-1][i-1].isSet() )
				if( puzzle.at(j, i).isSet() )
				{//Since the element is set, output the value.
					out << puzzle.getElementValue( j, i );
				}
				else
				{//Since the element isn't set, output the value.
					out << "x";
				}

				if( j <= 8 )
				{//If this element isn't the last in the row, add a space for the next element in the row.
					out << " ";
				}
			}

			out << "\n";
		}
		*/
		std::string printVersion;

		out << puzzle.toString();

		return out;
	}

	bool SudokuPuzzle::isSolved()
	{//Returns whether the puzzle is solved.
		for( int i = 1; i <= 9; i++ )
		{//Go through the rows.
			for( int j = 1; j <= 9; j++ )
			{//Go through the elements in the row.
				//if( !(elements[i][j].isSet()) )
				if( !(at(j, i).isSet()) )
				{//If this element isn't set, the puzzle isn't solved.
					return false;
				}
			}
		}

		return true;
	}
	
	SudokuElement& SudokuPuzzle::at( int x, int y )
	{//Returns the element at coordinates x and y.
		if( (x < 1) || (x > 9) )
		{//x is out of range, throw an exception.
			throw std::out_of_range( "In SudokuPuzzle::at( int x, int y ), x is out of range. x should be between 1 and 9 inclusive." );
		}
		else
		{//x is in range, continue checking.
			if( (y < 1) || (y > 9) )
			{//y is out of range, throw an exception.
				throw std::out_of_range( "In SudokuPuzzle::at( int x, int y ), y is out of range. y should be between 1 and 9 inclusive." );
			}
			else
			{//y is in range, check if the element is set.
				return elements[y-1][x-1];
			}
		}
	}

	std::string SudokuPuzzle::toString()
	{//Return a string version of the puzzle meant for displaying as text or saving to a text file.
		std::stringstream printVersion;

		for( int i = 1; i <= 9; i++ )
		{//Go through the rows.
			for( int j = 1; j <= 9; j++ )
			{//Go through the elements in the row.
				//if( puzzle.elements[j-1][i-1].isSet() )
				if( at(j, i).isSet() )
				{//Since the element is set, output the value.
					printVersion << getElementValue( j, i );
				}
				else
				{//Since the element isn't set, output the value.
					printVersion << "x";
				}

				if( j%3 == 0 )
				{//If this element is at the edge of a grid, print a delimiter.
					printVersion << "| ";
				}

				if( j <= 8 )
				{//If this element isn't the last in the row, add a space for the next element in the row.
					printVersion << " ";
				}
			}

			if( i%3 == 0 )
			{//If this element is at the edge of a grid, print a delimiter line.
				printVersion << "\n----------------------";
			}

			printVersion << "\n";
		}

		return printVersion.str();
	}
	
	void SudokuPuzzle::saveToFile( std::string filename )
	{//Appends the output of toString() to a file indicated by filename.
		std::ofstream saveFile;
		std::string errorText;
		std::string printVersion;

		try
		{
			saveFile.open( filename.c_str(), std::ios::out | std::ios::app );//Open the file for output and appending to the end of the file.
			saveFile << toString();
			saveFile << "================================\n";//To indicate the end of the puzzle.
			saveFile.close();
		}
		catch( std::exception e )
		{
			errorText = "In SudokuPuzzle::saveToFile( std::string filename ), got an error trying to save to file ";
			errorText += filename;
			errorText += " : ";
			errorText += e.what();
			std::cerr << errorText;
		}
	}

	bool SudokuPuzzle::isValid()
	{//Returns whether the puzzle is valid.
		bool values[9];

		for( int k = 0; k < 9; k++ )
		{//Go through and make sure each value is set to false.
			values[k] = false;
		}

		//Go through each row.
		for( int i = 1; i <= 9; i++ )
		{//Go through the rows.
			for( int k = 0; k < 9; k++ )
			{//Go through and make sure each value is set to false.
				values[k] = false;
			}
			for( int j = 1; j <= 9; j++ )
			{//Go through the elements in the row.
				if( !(at(j,i).isSet()) || (values[getElementValue(j,i)-1] == true) )
				{//If this element isn't set or the value has already been seen, the puzzle isn't valid.
					//std::cout << "Row " << i << " is invalid at column " << j << std::endl;
					return false;
				}
				else
				{//The value is ok, set it.
					values[getElementValue(j,i)-1] = true;
				}
			}
		}

		//Go through each column.
		for( int j = 1; j <= 9; j++ )
		{//Go through the rows.
			for( int k = 0; k < 9; k++ )
			{//Go through and make sure each value is set to false.
				values[k] = false;
			}
			for( int i = 1; i <= 9; i++ )
			{//Go through the elements in the row.
				if( !(at(j,i).isSet()) || (values[getElementValue(j,i)-1] == true) )
				{//If this element isn't set or the value has already been seen, the puzzle isn't valid.
					//std::cout << "Column " << j << " is invalid at row " << i << std::endl;
					return false;
				}
				else
				{//The value is ok, set it for later.
					values[getElementValue(j,i)-1] = true;
				}
			}
		}

		//Go through each region.
		for( int x = 0; x < 3; x++ )
		{//Go through the rows of regions.
			for( int y = 0; y < 3; y++ )
			{//Go through the regions in the row.
				for( int k = 0; k < 9; k++ )
				{//Go through and make sure each value is set to false.
					values[k] = false;
				}
				for( int i = 3*x+1; i <= 3*x+3; i++ )
				{//Go through the rows in the region.
					for( int j = 3*y+1; j <= 3*y+3; j++ )
					{//Go through the elements in the row.
						if( !(at(j,i).isSet()) || (values[getElementValue(j,i)-1] == true) )
						{//If this element isn't set or the value has already been seen, the puzzle isn't valid.
							//std::cout << "Grid " << x << "by" << y <<" is invalid at " << i << "by" << j << std::endl;
							return false;
						}
						else
						{//The value is ok, set it for later.
							values[getElementValue(j,i)-1] = true;
						}
					}
				}
			}
		}

		return true;
	}
}
