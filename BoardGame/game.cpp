// File: game.cpp

#include "game.h"

game::game(int size) {
	move_number = 0;
	board_size = size;
	board = new piece * [size];
	for (int i = 0; i < size; ++i) {
		board[i] = new piece[size];
	}
}

game::who game::play() {
	restart();
	while (!is_game_over() && could_cont()) {
		display_status();
		make_player_move();
	}
	display_status();
	return winning();
}

void game::make_player_move() {
	string move = "";
	//if no available move pass
	queue<string> possible;
	compute_moves(possible);
	if (possible.empty()) {
		cout << "you can't move, hit XX to pass: ";
		while (move != "XX" && move !="xx") {
			display_message("XX to pass\n");
			getline(cin, move);
		}
		game::make_move(move);
		if (no_moves.size() < 2) {
			no_moves.push(move_number);
		}else {
			no_moves.pop();
			no_moves.push(move_number);
		}
	}else {
		move = get_user_move();
		while (!is_legal(move))	{
			display_message("Illegal move.\n");
			move = get_user_move();
		}
		make_move(move);
	}
}

void game::display_message(const string& message) const {
	cout << message;
}

void game::display_status()const {
	char columns = 'A';
	int rows = 1;
	int size = get_board_size();
	cout << "  ";
	for (int i = 0; i < size; i++) {
		cout << " " << columns;
		columns++;
	}
	cout << std::endl;
	for (int i = 0; i < size; i++) {
		cout << " " << rows;
		rows++;
		for (int j = 0; j < size; j++) {
			if (board[i][j].get_status() == 1)
				cout << " @";
			else if (board[i][j].get_status() == 2)
				cout << " #";
			else
				cout << " .";
		}
		cout << std::endl;
	}
}

void game::compute_moves(std::queue<std::string>& moves)const {
	string tmp = "";
	char col = 'A', row = '1';
	int size = get_board_size();
	for (row = '1'; row != '0' + (size + 1); row++) {
		for (col = 'A'; col != 'I'; col++) {
			tmp = "";
			tmp += col;
			tmp += row;
			if (is_legal(tmp))
				moves.push(tmp);
		}
	}
}

string game::get_user_move() const {
	string answer,player;
	who name = last_mover();
	if (name == 1) { 
		player = "player1"; 
	}else { 
		player = "player2"; 
	}
	game::display_message(player+" Your move, please: ");
	getline(cin, answer);
	return answer;
}

bool game::could_cont() const {
	if (no_moves.size() == 2) {
		if (no_moves.back() - no_moves.front() == 1) {
			return false;
		}
	}
	return true;
}