/******************************************************************************
Xin Liu
CIS 554-M401 Object Oriented Programming in C++
Syracuse University
Final project
File: game.h
base class of a board game
*******************************************************************************/

#ifndef MAIN_XIN_GAME
#define MAIN_XIN_GAME

#include "piece.h"
#include <iostream>   
#include <queue>      
#include <string>     

using std::string;
using std::queue;
using std::cout;
using std::cin;

class game {
public:
	enum who { FIRST_PLAYER, SECOND_PLAYER, NEUTRAL }; // outcomes
	game(int size); //constructor
	virtual ~game() { }

	//********************************************************
	// MUST NOT BE OVERRIDDEN
	//********************************************************
	// main logic of the program
	who play();
	//get board size
	const int get_board_size() const { return board_size; }
	//board (should be accessble by all children)
	piece** board;
	
	//********************************************************
	// OPTIONAL TO OVERRIDE
	//********************************************************
	//cout
	virtual void display_message(const std::string& message) const;
	//print board
	virtual void display_status() const;
	//update all possible moves
	virtual void compute_moves(std::queue<std::string>& moves) const;
	//getline from console for user move
	virtual std::string get_user_move() const;
	//get last mover
	virtual who last_mover() const	{
		return (move_number % 2 == 1 ? FIRST_PLAYER : SECOND_PLAYER);
	}
	//restart the game
	virtual void restart() { move_number = 0; }
	//if this game could countinue to play (might be no moves avliable)
	virtual bool could_cont() const;

	//********************************************************
	// MUST BE OVERRIDDEN && CALL THE ORIGINAL WHEN FINISH
	//********************************************************
	//move one step move on the board
	virtual void make_move(const std::string& move) { ++move_number; }
	
	//********************************************************
	// PURE VIRTUAL
	//********************************************************
	//if the game is over
	virtual bool is_game_over() const = 0;
	//if this move is legal
	virtual bool is_legal(const std::string& move) const = 0;
	//return who is winning
	virtual who winning() const = 0;

private:
	//the player activity of one step move
	void make_player_move();
	//moves so far
	int move_number;
	//size of the board
	int board_size;
	//log of no moves avaliable to end if both player no moves
	queue<int> no_moves;
};
#endif