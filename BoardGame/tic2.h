/******************************************************************************
Xin Liu
CIS 554 - M401 Object Oriented Programming in C++
Syracuse University
Final project
File : othello.h
Tic2 just theme of X vs O
*******************************************************************************/

#ifndef TIC2_H
#define TIC2_H

#include "tictactoe.h"
#include <iostream>
using std::cout;

class tic2 : public tictactoe {
public:
	//constructor
	tic2(int size) :tictactoe(size) {}
	virtual ~tic2() = default; // Virtual destructor

	//print board
	virtual void display_status() const;
};

#endif