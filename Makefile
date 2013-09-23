all: SudokuElement.o SudokuPuzzle.o Test

SudokuElement.o: SudokuElement.cpp SudokuElement.h
	g++ -Wall -c SudokuElement.cpp SudokuElement.h

SudokuPuzzle.o: SudokuPuzzle.cpp SudokuPuzzle.h
	g++ -Wall -c SudokuPuzzle.cpp SudokuPuzzle.h

Test: SudokuElement.o SudokuCreatorTest.cpp SudokuElementTest.h
	g++ -Wall -o Test SudokuCreatorTest.cpp SudokuElementTest.h SudokuElement.o -lcppunit

clean:
	rm Test *.o *~ *.gch
