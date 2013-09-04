all: Test SudokuPuzzle.o

SudokuPuzzle.o: SudokuPuzzle.cpp
	g++ -Wall -c SudokuPuzzle.cpp

Test: SudokuPuzzle.cpp test.cpp
	g++ -Wall -o Test test.cpp

clean:
	rm Test *.o *~
