//
// Sudoku.h
// File contains Sudoku class 
//
// Created by Firas Siala 12/28/2021


#ifndef Sudoku_h
#define Sudoku_h


#include <iostream>
#include <nlohmann/json.hpp>


class Sudoku 
{

// PRIVATE DATA MEMBERS AND METHODS
private:
	nlohmann::json board;
	int N;
	bool numPossible(const int &row, const int &col, const int &num);
	bool emptySquare(int &row, int &col);	

// PUBLIC METHODS	
public:
	void readBoard(const std::string inputFileName);
	void writeToFile(const std::string outputFileName);
	void printBoard();
	bool solve();
};


#endif

