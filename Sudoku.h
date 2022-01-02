//
// Sudoku.h
// File contains Sudoku class 
//
// Created by Firas Siala 12/29/2021

#ifndef Sudoku_h
#define Sudoku_h

#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using string = std::string;

class Sudoku 
{

// PRIVATE DATA MEMBERS AND METHODS
private:
	json board;
	int N;
	bool numPossible(const int &row, const int &col, const int &num);
	bool emptySquare(int &row, int &col);	

// PUBLIC METHODS	
public:
	void readBoard(const string inputFileName);
	void writeToFile(string outputFileName);
	void printBoard();
	bool solve();
};

#endif

