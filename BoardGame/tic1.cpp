#include "tic1.h"

void tic1::display_status()const {
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