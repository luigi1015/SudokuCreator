#ifndef SudokuElement_h
#define SudokuElement_h

namespace Sudoku
{
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
}

#endif /* SudokuElement_h */
