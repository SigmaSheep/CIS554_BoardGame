//*******************************************************
//piece.cc
//Xin Liu
//piece class is used to store one piece information of 
//board game, a piece has three status, 1, 2, and empty.
//********************************************************

#include "piece.h"

void piece::flip() {
	if (piece_status == 1)
		piece_status = 2;
	else if (piece_status == 2)
		piece_status = 1;
	else
		cout << "cannot flip empty spot \n";
}

bool operator ==(const piece& p1, const piece& p2) {
	return (p1.get_status() == p2.get_status());
}

bool operator !=(const piece& p1, const piece& p2) {
	return (p1.get_status() != p2.get_status());
}
