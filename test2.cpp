#include "SudokuPuzzle.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <exception>
#include <stdexcept>
//#include <sstream>
#include <stack>
#include <stdlib.h> 

int main( int argc, char* argv[])
{
	Sudoku::SudokuPuzzle puz;

	puz.setElementValue( 1, 1, 8 );
	puz.setElementValue( 1, 2, 4 );
	puz.setElementValue( 1, 3, 7 );
	puz.setElementValue( 1, 4, 6 );
	puz.setElementValue( 1, 5, 9 );
	puz.setElementValue( 1, 6, 1 );
	puz.setElementValue( 1, 7, 2 );
	puz.setElementValue( 1, 8, 3 );
	puz.setElementValue( 1, 9, 5 );
	puz.setElementValue( 2, 1, 1 );
	puz.setElementValue( 2, 2, 2 );
	puz.setElementValue( 2, 3, 6 );
	puz.setElementValue( 2, 4, 3 );
	puz.setElementValue( 2, 5, 5 );
	puz.setElementValue( 2, 6, 4 );
	puz.setElementValue( 2, 7, 7 );
	puz.setElementValue( 2, 8, 9 );
	puz.setElementValue( 2, 9, 8 );
	puz.setElementValue( 3, 1, 3 );
	puz.setElementValue( 3, 2, 9 );
	puz.setElementValue( 3, 3, 5 );
	puz.setElementValue( 3, 4, 2 );
	puz.setElementValue( 3, 5, 8 );
	puz.setElementValue( 3, 6, 3 );
	puz.setElementValue( 3, 7, 6 );
	puz.setElementValue( 3, 8, 5 );
	puz.setElementValue( 3, 9, 4 );
	puz.setElementValue( 4, 1, 9 );
	puz.setElementValue( 4, 2, 7 );
	puz.setElementValue( 4, 3, 1 );
	puz.setElementValue( 4, 4, 2 );
	puz.setElementValue( 4, 5, 8 );
	puz.setElementValue( 4, 6, 3 );
	puz.setElementValue( 4, 7, 6 );
	puz.setElementValue( 4, 8, 5 );
	puz.setElementValue( 4, 9, 4 );
	puz.setElementValue( 5, 1, 5 );
	puz.setElementValue( 5, 2, 6 );
	puz.setElementValue( 5, 3, 2 );
	puz.setElementValue( 5, 4, 4 );
	puz.setElementValue( 5, 5, 7 );
	puz.setElementValue( 5, 6, 9 );
	puz.setElementValue( 5, 7, 8 );
	puz.setElementValue( 5, 8, 1 );
	puz.setElementValue( 5, 9, 3 );
	puz.setElementValue( 6, 1, 4 );
	puz.setElementValue( 6, 2, 3 );
	puz.setElementValue( 6, 3, 8 );
	puz.setElementValue( 6, 4, 1 );
	puz.setElementValue( 6, 5, 6 );
	puz.setElementValue( 6, 6, 5 );
	puz.setElementValue( 6, 7, 9 );
	puz.setElementValue( 6, 8, 2 );
	puz.setElementValue( 6, 9, 7 );
	puz.setElementValue( 7, 1, 2 );
	puz.setElementValue( 7, 2, 1 );
	puz.setElementValue( 7, 3, 4 );
	puz.setElementValue( 7, 4, 7 );
	puz.setElementValue( 7, 5, 3 );
	puz.setElementValue( 7, 6, 6 );
	puz.setElementValue( 7, 7, 5 );
	puz.setElementValue( 7, 8, 8 );
	puz.setElementValue( 7, 9, 9 );
	puz.setElementValue( 8, 1, 7 );
	puz.setElementValue( 8, 2, 8 );
	puz.setElementValue( 8, 3, 9 );
	puz.setElementValue( 8, 4, 5 );
	puz.setElementValue( 8, 5, 4 );
	puz.setElementValue( 8, 6, 2 );
	puz.setElementValue( 8, 7, 3 );
	puz.setElementValue( 8, 8, 6 );
	puz.setElementValue( 8, 9, 1 );
	puz.setElementValue( 9, 1, 6 );
	puz.setElementValue( 9, 2, 5 );
	puz.setElementValue( 9, 3, 3 );
	puz.setElementValue( 9, 4, 9 );
	puz.setElementValue( 9, 5, 1 );
	puz.setElementValue( 9, 6, 8 );
	puz.setElementValue( 9, 7, 4 );
	puz.setElementValue( 9, 8, 7 );
	puz.setElementValue( 9, 9, 2 );

	std::cout << "Test 0\n";
		
	std::cout << puz;

	std::cout << "Test 2\n";

	//return 0;
	exit(0);
}
