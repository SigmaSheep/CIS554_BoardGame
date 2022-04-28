//main.cc

#include "othello.h"
#include "game.h"
#include "tictactoe.h"
#include "tic1.h"
#include "tic2.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <stdexcept>

int main() {
	try {
		std::string user_input;
		int board_size;
		bool bad_choice = true;
		game* my_game_ptr;
		bool exit_flag = 0;
		int piece_flag = 0;
		int theme_choice = 0; //0 for @vs#; 1 for XvsO
		game::who winner;

		std::cout << "/////////////////////////////////////////////\n"
			<< "Welcome to board game Othello and Tic Tac Toe\n";

		while(!exit_flag){
			std::cout<< "Enter 1 for othello, 2 for TicTacToe, F for exit\n";
			std::getline(std::cin, user_input);
			//place holder to avoid complier error of ptr may not be used
			my_game_ptr = new tictactoe(3); 
			//input board size
			while(bad_choice){
				if (user_input.find("1") == 0) {
					std::cout << "Enter board size\nothello board must be even and greater or equal to 4\n";
					bad_choice = false;
					//check if board size is a number 
					std::getline(std::cin, user_input);
					std::stringstream to_int(user_input);
					if ((to_int >> board_size).fail()) {
						std::cout << "board size must be a number\nPlease choose from the begining\n";
						bad_choice = true;
						continue;
					}
					my_game_ptr = new othello(board_size);
				}else if (user_input.find("2") == 0) {
					bad_choice = false;
					std::cout << "Choose theme: \n1:theme1 @ VS #\n2:theme2 X VS O\n";
					std::getline(std::cin, user_input);
					if (user_input.find("1") == 0) {
						my_game_ptr = new tic1(3);
					}else if (user_input.find("2") == 0) {
						my_game_ptr = new tic2(3);
						theme_choice = 1;
					}else {
						std::cout<<"bad choice for TTT theme\nPlease choose from the begining\n";
						bad_choice = true;
						continue;
					}
				}else if (user_input.find("F") == 0) {
					return (0);
				} else{
					std::cout << "invalid choice\n";
					std::cout << "Enter 1 for othello, 2 for TicTacToe, F for exit\n";
					std::getline(std::cin, user_input);
				}
			}
			if (piece_flag == 0) {
				std::cout << "this is two player game, player1 is @, player2 is #, and enters move when see your move \n";
			}else {
				std::cout << "this is two player game, player1 is X, player2 is O, and enters move when see your move \n";
			}
			//run game
			winner = my_game_ptr -> play();
			if (winner == 0){
				if (theme_choice==0){
					std::cout << "winner is player1(@) \n";
				}else {
					std::cout << "winner is player1(X) \n";
				}
			}else if (winner == 1) {
				if (theme_choice == 0) {
					std::cout << "winner is player2(#) \n";
				}else {
					std::cout << "winner is player2(O) \n";
				}
			}else {
				std::cout << "Draw! \n";
			}
			bad_choice = true;
			piece_flag = 0;
		}
		return (0);
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "exception: " << e.what() << std::endl;
		return (1);
	}
}
