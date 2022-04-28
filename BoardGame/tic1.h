/******************************************************************************
Xin Liu
CIS 554 - M401 Object Oriented Programming in C++
Syracuse University
Final project
File : othello.h
Tic1 just theme of @ vs #
*******************************************************************************/

#ifndef TIC1_H
#define TIC1_H

#include "tictactoe.h"
#include <iostream>
using std::cout;

class tic1 : public tictactoe {
public:
	//constructor
	tic1(int size) :tictactoe(size) {}
	virtual ~tic1() = default; // Virtual destructor

	//print board
	virtual void display_status() const;
};

#endif