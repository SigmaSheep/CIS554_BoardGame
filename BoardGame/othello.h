/******************************************************************************
Xin Liu
CIS 554 - M401 Object Oriented Programming in C++
Syracuse University
Final project
File : othello.h
othello game 
*******************************************************************************/

#ifndef OTHELLO_H
#define OTHELLO_H

#include "game.h"
#include <cstdlib>
#include <iostream>
#include <stdexcept>
using std::cout;
using std::endl;
using std::string;
using std::invalid_argument;

class othello :public game {
public:
	//Constructor
	othello(int size);
	virtual ~othello() = default; // Virtual destructor 
	//return true if this move is legal
	bool is_legal(const std::string& move) const;
	//update this single move to the board
	// precondition: the move must be already legal
	// make the actual move, flip all the pieces in 
	//				  the middle of two same pieces
	void make_move(const std::string& move);
	//return true if the current game is finished
	// check the pravite variable empty_spot, return true
	//			if there is no empty spot on the board
	bool is_game_over()const;
	//return who is winning
	who winning() const;

private:
	//how many spot on the board are still empty
	int empty_spot;
};

#endif
