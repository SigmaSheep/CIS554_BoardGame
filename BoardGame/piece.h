/******************************************************************************
Xin Liu
CIS 554 - M401 Object Oriented Programming in C++
Syracuse University
Final project
File : piece.h
piece class is used to store one piece information of board,
a piece has three status, 1, 2, and empty. The piece class
can be compared by operator == and != with the same or different status.
*******************************************************************************/

#ifndef PIECE_H
#define PIECE_H

#include <iostream>
using std::cout;

class piece {
public:
	// default constructor make piece to the status
	piece(int status = 3) {	piece_status = status; }
	// flip the piece, turn 1 to 2, or turn 2 to 1
	void flip();
	// return the status
	int get_status()const { return piece_status; }
	// set status to p
	void set(int p) { piece_status = p; }
private:
	//	1, 2, or 3. 1 is FIRST_PLAYER, 2 is SECOND_PLAYER,
	//	3 is empty spot and default option.
	int piece_status;
};
//overload the operator to compare the pieces
bool operator == (const piece& p1, const piece& p2);
bool operator != (const piece& p1, const piece& p2);
#endif
