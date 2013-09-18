all: SudokuElement.o SudokuPuzzle.o Test

SudokuElement.o: SudokuElement.cpp SudokuElement.h
	g++ -Wall -c SudokuElement.cpp SudokuElement.h

SudokuPuzzle.o: SudokuPuzzle.cpp SudokuPuzzle.h
	g++ -Wall -c SudokuPuzzle.cpp SudokuPuzzle.h

Test: SudokuElement.o SudokuPuzzle.o test.cpp
	g++ -Wall -o Test test.cpp SudokuElement.o SudokuPuzzle.o

clean:
	rm Test *.o *~ *.gch
