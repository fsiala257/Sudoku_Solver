//
// main.cpp
// File contains main program
//
// Created by Firas Siala 12/29/2021


#include "Sudoku.h"


int main()
{
	Sudoku sudoku;					// Create sudoku object from Sudoku class
	sudoku.readBoard("input.json");			// Get board from input file
	std::cout << std::endl;				
	std::cout<< "Initial board: " << std::endl;
	sudoku.printBoard();				// Print board
	sudoku.solve();					// Solve sudoku
	sudoku.writeToFile("output.json");		// Write results to file
	
	return 0;
}
