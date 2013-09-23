#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "SudokuElement.h"
#include <vector>
#include <stdexcept>

class SudokuElementTest : public CppUnit::TestCase 
{
	private:
		//SudokuElement se;//Sudoku Element to test.
		
	public:
		//void setUp()
		//{//Set up the element for testing.
		//}
		
		//void tearDown()
		//{//Finishes off the element after testing.
		//}
		
		void testPossible()
		{//Tests the possible/impossible values
			Sudoku::SudokuElement se;
			
			//All the possibilities should be set to true after initialization. Test that.
			for( int i = 1; i < 10; i++ )
			{//Verify one by one that the elements are set to true.
				CPPUNIT_ASSERT( se.getIfPossible(i) == true );
			}
			
			//Go through each of the elements and set them to impossible. Verify as each element is set.
			for( int i = 1; i < 10; i++ )
			{//Go through each element one by one to set them to impossible and verify.
				se.setImpossible(i);
				
				for( int j = 1; j < 10; j++ )
				{//Check the elements.
					if( j <= i )
					{//All the elements up to and including i should be set to impossible.
						CPPUNIT_ASSERT( se.getIfPossible(j) == false );
					}
					else
					{//All the elements after i should be set to possible.
						CPPUNIT_ASSERT( se.getIfPossible(j) == true );
					}
				}
			}
		}
		
		void testPossibleOutOfRangeLower()
		{//Tests that Sudoku Element throws an exception if you give it an index below the valid range. ****Expected to throw an exception****
			Sudoku::SudokuElement se;
			se.getIfPossible(0);
		}
		
		void testPossibleOutOfRangeUpper()
		{//Tests that Sudoku Element throws an exception if you give it an index above the valid range. ****Expected to throw an exception****
			Sudoku::SudokuElement se;
			se.getIfPossible(10);
		}
		
		//Create the test suite using CPPUnit macros.
		CPPUNIT_TEST_SUITE( SudokuElementTest );
		CPPUNIT_TEST( testPossible );
		CPPUNIT_TEST_EXCEPTION( testPossibleOutOfRangeLower, std::out_of_range );
		CPPUNIT_TEST_EXCEPTION( testPossibleOutOfRangeUpper, std::out_of_range );
		CPPUNIT_TEST_SUITE_END( );
};


			
			
