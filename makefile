prog.o: main.o Sudoku.o
	 g++ -std=c++11 main.o Sudoku.o -o prog

main.o: main.cpp
	 g++ -std=c++11 -c main.cpp

Sudoku.o: Sudoku.cpp 
	 g++ -std=c++11 -c Sudoku.cpp

clean:
	rm *.o prog
