#include "tictactoe.h"

bool tictactoe::is_legal(const std::string& move) const {
    int row, col; //current location
    int size = get_board_size();
    col = int(toupper(move[0]) - 'A');
    row = int(toupper(move[1]) - '1');

    if (col < 0 || row < 0 || col>size - 1 || row>size - 1) {
        return false;
    }
    if (board[row][col].get_status() != 3) {
        return false;
    }
    return true;
}

void tictactoe::make_move(const std::string& move) {
    int row, col;
    int size = get_board_size();
    col = int(toupper(move[0]) - 'A');
    row = int(toupper(move[1]) - '1');

    if (last_mover() == FIRST_PLAYER) {
        board[row][col].set(2);
    } else {
        board[row][col].set(1);
    }
    game::make_move(move);
    empty_spot -= 1;
}

// Return true if the current game is finished:
bool tictactoe::is_game_over()const {
    int flag = check_winning();
    if (flag != 4) {
        return true;
    }else {
        return false;
    }

}

// Return who is winning
game::who tictactoe::winning() const {
    int flag = check_winning();
    
    if (flag == 1) {
        return FIRST_PLAYER;
    }
    else if (flag == 2) {
        return SECOND_PLAYER;
    }
    else {
        return NEUTRAL;
    }
}

//return 1 for first player win
//       2 for second player win
//       0 for draw
//       3 for not finished
int tictactoe::check_winning() const {
    int size = get_board_size();
    int row, col;
    //check row win
    for (row = 0; row < size; row++) {
        if (board[row][0].get_status() != 3) {
            for (col = 0; col < size; col++) {
                if (board[row][0] != board[row][col]) {
                    break;
                }
                //return winer
                if (col == size - 1) {
                    return board[row][col].get_status();
                }
            }
        }
    }
    //check column win
    for (col = 0; col < size; col++) {
        if (board[0][col].get_status() != 3) {
            for (row = 0; row < size; row++) {
                if (board[0][col] != board[row][col]) {
                    break;
                }
                if (row == size - 1) {
                    return board[row][col].get_status();
                }
            }
        }
    }
    //check diagonal win
    col = 0;
    if (board[0][0].get_status() != 3) {
        for (row = 0; row < size; row++) {
            if (board[0][0] != board[row][col]) {
                break;
            }
            if (row == size - 1) {
                return board[row][col].get_status();
            }
            col++;
        }
    }
    //check anti-diagonal win
    col = 0;
    if (board[size - 1][col].get_status() != 3) {
        for (row = size - 1; row == 0; row--) {
            if (board[size - 1][0] != board[row][col]) {
                break;
            }
            if (row == 0) {
                return board[row][col].get_status();
            }
        }
    }

    if (empty_spot == 0) {
        return 0; //draw
    }
    else {
        return 4; //not finished
    }
}