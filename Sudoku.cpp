//
// Sudoku.h
// File contains implementations of Sudoku class methods
//
// Created by Firas Siala 12/29/2021

#include "Sudoku.h"
#include <fstream> 

// METHOD: set method used to access and set private attribbutes (grid and N) from inputFileName
// PARAMS: inputFileName (string)
void Sudoku::readBoard(const string inputFileName)
{
	std::ifstream inputFile;
	inputFile.open("input_files/"+inputFileName);
	inputFile >> board;
	inputFile.close();
	N = board["values"].size();
}


// METHOD: prints sudoku grid to the console
void Sudoku::printBoard()
{
	for(auto const &col: board)
	{ 
		for(auto const &row : col)
		{
			std::cout << row << std::endl;
		}
		std::cout<<std::endl;	
	}
}


// METHOD: writes grid to a file
// PARAMS: output file name (string).
void Sudoku::writeToFile(const string outputFileName)
{
	std::ofstream outputFile;
	outputFile.open("output_files/"+outputFileName);
	outputFile << std::setw(4) << board;
	outputFile.close();
}


// METHOD: if cell is empty. if all cells are filled (i.e. not equal to 0), solver exists the loop
// PARAMS: row and column (passed by reference to be used by the rest of the solver algorithm)
bool Sudoku::emptySquare(int &row, int &col)
{
	for(row = 0; row<N; row++)
	{
		for(col = 0; col<N; col++)
		{
			if(board["values"][row][col] == 0)
				return true;
		}
	}
	return false;	
}


// METHOD: checks if number (num) can be positioned in location x,y in the board.
// PARAMS: x (integer) grid column, y (integer) grid row , num (integer, number to be checked)
// Method returns a boolean. If num location in location x and y is possible, function returns TRUE 
bool Sudoku::numPossible(const int &row, const int &col, const int &num)
{

	// If num exists in any of the columns, return false (i.e. number not possible)
	for(int x = 0; x < N; x++)
	{
		if(board["values"][row][x] == num)
			return false;
	}
	
	// If num exists in any of the rows, return false (i.e. number not possible)
	for(int y = 0; y < N; y++)
	{
		if(board["values"][y][col] == num)
			return false;
	}

	// If num exists in the square, return false (i.e. number not possible)
	for(int y = 0; y < int(sqrt(N)); y++) 
	{
		for(int x = 0; x < int(sqrt(N)); x++)
		{
			if (board["values"][y+(row-row%int(sqrt(N)))][x+(col-col%int(sqrt(N)))] == num)
				return false;
		}
	}

	return true;
}


// METHOD: solves sudoku board using backtracking method. Solver goes through each cell in the board 
// that has no pre-assigned number (defined as 0).Then function goes through possible numbers from
// 1 to N to see if they can eb inserted in that row and column (using numPossible method). 
// If numPossible returns as true, then num is inserted in that row and column. Solver method is 
// called again (recursive) to move to the next cell. If none of the numbers from 1 to N can be
// inserted in that row and column, the cell is left empty (assigned 0 by the solver method) and goes 
// back to the previous cell and increase num by 1. Process is repeated until all cells are filled
bool Sudoku::solve()
{
	int row, col;
	
	if(!emptySquare(row,col)) 
	{
		std::cout << "Solution: " << std::endl;
		printBoard();
		return true;
	}

	//count++;
	for(int num = 1; num <= N; num++)
	{
		if(numPossible(row,col,num))
		{
			board["values"][row][col] = num;
			if(solve())
				return true;
			board["values"][row][col] = 0;
		}
	}
	return false;
}
