/******************************************************************************
Xin Liu
CIS 554 - M401 Object Oriented Programming in C++
Syracuse University
Final project
File : othello.h
Tic Tac Toe game
*******************************************************************************/

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "game.h"
#include <cstdlib>
#include <iostream>
#include <stdexcept>
using std::cout;
using std::endl;
using std::string;
using std::invalid_argument;

class tictactoe : public game {
public:
	//constructor a size*size board 
	tictactoe(int size) :game(size) { empty_spot = size * size; }
	virtual ~tictactoe() = default; // Virtual destructor
	//return true if the move is legal
	bool is_legal(const std::string& move) const;
	//update the move to the board
	// precondition: the move must be already legal
	void make_move(const std::string& move);
	//return true if the current game is finished
	//use private function check_winning() 
	bool is_game_over()const;
	//return who is winning
	//use private function check_winning() 
	who winning() const;

private:
	// return flags include one more case that game is not over
	// used for both is_game_over() and winning()
	int check_winning() const;
	//empty spot on the bboard
	int empty_spot;
};
#endif
