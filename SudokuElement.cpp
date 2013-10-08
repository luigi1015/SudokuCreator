#include <stdexcept>
#include <vector>
#include "SudokuElement.h"

namespace Sudoku
{
	/*
	class SudokuElement
	{//A single element/number of the Sudoku puzzle.
		private:
			bool possibilities[9];//A representation of the different numbers the element could be according to the rules of Sudoku.
			int elementValue;//The value of the element.
		public:
			SudokuElement();//Sets the possibilities to all true and value to 0.
			bool getIfPossible( int value );//Returns true if the element could be value according to what the element has been told. Value should be between 1 and 9 inclusive. Generates an exception if value is out of range.
			void setPossible( int value );//Sets value to be possible. Value should be between 1 and 9 inclusive. Generates an exception if value is out of range.
			void setImpossible( int value );//Sets value to be impossible. Value should be between 1 and 9 inclusive. Generates an exception if value is out of range.
			int getNumPossibilities();//Returns the number of possiblities according to what the element has been told.
			void setValue( int num );//Sets the number of the element. Num should be between 1 and 9 inclusive. Generates an exception if num is impossible according to what the element has been told or if num is out of range.
			int getValue();//Returns the number of the element. Generates an exception if value has not been set.
			bool isSet();//Returns if the element has been set.
			void clear();//Clears the possibilities and the value.
			void clearValue();//Clears only the value.
	};
	*/
	
	SudokuElement::SudokuElement()
	{//Sets the possibilities to all true and value to 0.
		for( int i = 0; i < 9; i++ )
		{//Set possibilities to all true.
			possibilities[i] = true;
		}
		
		elementValue = 0;//Sets value to initial invalid number.
	}
	
	bool SudokuElement::getIfPossible( int value )
	{//Returns true if the element could be value according to what the element has been told. Value should be between 1 and 9 inclusive. Generates an exception if value is out of range.
		if( (value < 1) || (value > 9) )
		{//Value is out of range, throw an exception.
			throw std::out_of_range( "In SudokuElement::getIfPossible(), value parameter is out of range." );
		}
		else
		{
			return possibilities[value-1];
		}
	}
	
	void SudokuElement::setPossible( int value )
	{//Sets value to be possible. Value should be between 1 and 9 inclusive. Generates an exception if value is out of range.
		if( (value < 1) || (value > 9) )
		{//Value is out of range, throw an exception.
			throw std::out_of_range( "In SudokuElement::setPossible(), value parameter is out of range." );
		}
		else
		{
			possibilities[value-1] = true;
		}
	}
	
	void SudokuElement::setImpossible( int value )
	{//Sets value to be impossible. Value should be between 1 and 9 inclusive. Generates an exception if value is out of range.
		if( (value < 1) || (value > 9) )
		{//Value is out of range, throw an exception.
			throw std::out_of_range( "In SudokuElement::setImpossible(), value parameter is out of range." );
		}
		else
		{
			possibilities[value-1] = false;
		}
	}
	
	int SudokuElement::getNumPossibilities()
	{//Returns the number of possiblities according to what the element has been told.
		int numPossibilities = 0;
		for( int i = 0; i < 9; i++ )
		{//For every time it encounters true, increment numPossibilities.
			if( possibilities[i] )
			{
				numPossibilities++;
			}
		}
		
		return numPossibilities;
	}

	bool SudokuElement::isPossibleValue( int val )
	{//Returns true if, according to it's records, the element can be set to value val. val should be between 1 and 9 inclusive.
		if( (value < 1) || (value > 9) )
		{//Value is out of range, throw an exception.
			throw std::out_of_range( "In SudokuElement::isPossibleValue( int val ), value parameter is out of range." );
		}
		else
		{
			return possibilities[val-1];
	}
	
	void SudokuElement::setValue( int newValue )
	{//Sets the number of the element. Num should be between 1 and 9 inclusive. Generates an exception if num is impossible according to what the element has been told or if num is out of range.( int value )
		if( (newValue < 1) || (newValue > 9) )
		{//Value is out of range, throw an exception.
			throw std::out_of_range( "In SudokuElement::setValue(), newValue parameter is out of range." );
		}
		else
		{
			elementValue = newValue;
		}
	}
	
	int SudokuElement::getValue()
	{//Returns the number of the element. Generates an exception if value has not been set.
		if( !(isSet()) )
		{//If the element isn't set, throw exception.
			throw "In SudokuElement::getValue(), element isn't set.";
		}
		else
		{
			return elementValue;
		}
	}
	
	bool SudokuElement::isSet()
	{//Returns if the element has been set.
		return elementValue != 0;
	}
	
	void SudokuElement::clear()
	{//Clears the possibilities and the value.
		for( int i = 0; i < 9; i++ )
		{//Set every possibility to true.
			possibilities[i] = true;
		}
		
		elementValue = 0;//Sets value to initial invalid number.
	}
	
	void SudokuElement::clearValue()
	{//Clears only the value.
		elementValue = 0;//Sets value to initial invalid number.
	}

	std::vector<int> SudokuElement::possibleVals()
	{//Return the list of possible values according to the element's records.
		std::vector<int> values;
		for( int i = 0; i < 9; i++ )
		{//Go through the values and, if they're true, add them to the vector.
			if( possibilities[i] == true )
			{
				values.push_back( i+1 );
			}
		}

		return values;
	}
}
