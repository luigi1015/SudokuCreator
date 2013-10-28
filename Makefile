all: SudokuElement.o SudokuGenerator.o SudokuPuzzle.o SudokuCreator SudokuSolver

SudokuElement.o: SudokuElement.cpp SudokuElement.h
#	g++ -g -Wall -c SudokuElement.cpp SudokuElement.h
	g++ -g -Wall -c SudokuElement.cpp

SudokuPuzzle.o: SudokuPuzzle.cpp SudokuPuzzle.h
#	g++ -g -Wall -c SudokuPuzzle.cpp SudokuPuzzle.h
	g++ -g -Wall -c SudokuPuzzle.cpp

SudokuGenerator.o: SudokuGenerator.cpp SudokuGenerator.h
#	g++ -g -Wall -c SudokuGenerator.cpp SudokuGenerator.h
	g++ -g -Wall -c SudokuGenerator.cpp

SudokuSolver.o: SudokuSolver.cpp SudokuSolver.h
	g++ -g -Wall -c SudokuSolver.cpp

Test: SudokuElement.o SudokuPuzzle.o SudokuCreatorTest.cpp SudokuElementTest.h
#	g++ -g -Wall -o Test SudokuCreatorTest.cpp SudokuElementTest.h SudokuPuzzle.o SudokuElement.o -lcppunit
	g++ -g -Wall -o Test SudokuCreatorTest.cpp SudokuPuzzle.o SudokuElement.o -lcppunit

Test2: SudokuElement.o SudokuPuzzle.o SudokuPuzzle.h test2.cpp
#	g++ -g -Wall -o Test2 SudokuPuzzle.o SudokuPuzzle.h SudokuElement.o test2.cpp
	g++ -g -Wall -o Test2 SudokuPuzzle.o SudokuElement.o test2.cpp

SudokuCreator: SudokuElement.o SudokuPuzzle.o SudokuGenerator.o
	g++ -g -Wall -o SudokuCreator SudokuGenerator.o SudokuPuzzle.o SudokuElement.o

SudokuSolver: SudokuElement.o SudokuPuzzle.o SudokuSolver.o
	g++ -g -Wall -o SudokuSolver SudokuSolver.o SudokuPuzzle.o SudokuElement.o

clean:
	rm Test SudokuCreator *.o *~ *.gch
