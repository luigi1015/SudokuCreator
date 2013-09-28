#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCaller.h>
#include "SudokuElementTest.h"

int main( )
{
	CPPUNIT_TEST_SUITE_REGISTRATION( SudokuElementTest );
	CppUnit::TextUi::TestRunner runner;
	CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry( );
	runner.addTest( registry.makeTest( ) );
	if ( runner.run( ) )
	{//Runner had success.
		return 0;
	}
	else
	{//Runner failed.
		return 1;
	}
}
