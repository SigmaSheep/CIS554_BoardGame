//othello.cc

#include "othello.h"

othello::othello(int size) :game(size){
    if (size < 3) {
        throw invalid_argument("board size must be greater than or euqal to 4!\n");
    }else if(size % 2 == 1) {
        throw invalid_argument("board size must be even!\n");
    }
    int center = size / 2;
    board[center - 1][center - 1].set(2);
    board[center - 1][center].set(1);
    board[center][center - 1].set(1);
    board[center][center].set(2);
    empty_spot = size*size - 4;
}

bool othello::is_legal(const string& move)const {
    int row, col; //current location
    int i, j; //tmp
    piece p, p3; //p is current piece, p3 is empty piece
    int size = get_board_size(); //no move
    if (move == "XX") {
        return true;
    }
    col = int(toupper(move[0]) - 'A');
    row = int(toupper(move[1]) - '1');
    p3.set(3);

    if (last_mover() == FIRST_PLAYER) {
        p.set(2);
    }else {
        p.set(1);
    }

    if (col < 0 || row < 0 || col>size-1 || row>size-1) {
        return false;
    }
    if (board[row][col].get_status() != 3) {
        return false;
    }
    //right check
    if (col != size-1 && p != board[row][col + 1] && board[row][col + 1] != 3) {
        for (j = col + 1; j != size; j++) {
            if (p3 == board[row][j])
                break;
            if (p == board[row][j]) {
                return true;
            }
        }
    }
    //right down check
    if (col != size-1 && row != size-1 && p != board[row + 1][col + 1] && board[row + 1][col + 1] != 3) {
        j = col + 1;
        for (i = row + 1; i != size && j != size; i++) {
            if (p3 == board[i][j])
                break;
            if (p == board[i][j])
                return true;
            j++;
        }
    }
    //down check
    if (row != size-1 && p != board[row + 1][col] && board[row + 1][col] != 3) {
        for (i = row + 1; i != size; i++) {
            if (p3 == board[i][col])
                break;
            if (p == board[i][col])
                return true;
        }
    }
    //left down check
    if (row != size-1 && col != 0 && p != board[row + 1][col - 1] && board[row + 1][col - 1] != 3) {
        j = col - 1;
        for (i = row + 1; i != size && j != -1; i++) {
            if (p3 == board[i][j])
                break;
            if (p == board[i][j])
                return true;
            j--;
        }
    }
    //left check
    if (col != 0 && p != board[row][col - 1] && board[row][col - 1] != 3) {
        for (j = col - 1; j != -1; j--) {
            if (p3 == board[row][j])
                break;
            if (p == board[row][j])
                return true;
        }
    }
    //left up check
    if (col != 0 && row != 0 && p != board[row - 1][col - 1] && board[row - 1][col - 1] != 3) {
        j = col - 1;
        for (i = row - 1; i != -1 && j != -1; i--) {
            if (p3 == board[i][j])
                break;
            if (p == board[i][j])
                return true;
            j--;
        }
    }
    //up check
    if (row != 0 && p != board[row - 1][col] && board[row - 1][col] != 3) {
        for (i = row - 1; i != -1; i--) {
            if (p3 == board[i][col])
                break;
            if (p == board[i][col])
                return true;
        }
    }
    //right up check
    if (row != 0 && col != size-1 && p != board[row - 1][col + 1] && board[row - 1][col + 1] != 3) {
        j = col + 1;
        for (i = row - 1; i != -1 && j != size; i--) {
            if (p3 == board[i][j])
                break;
            if (p == board[i][j])
                return true;
            j++;
        }
    }
    return false;
}

void othello::make_move(const std::string& move) {
    int row, col;
    piece p;
    int size = get_board_size();
    col = int(toupper(move[0]) - 'A');
    row = int(toupper(move[1]) - '1');
    int i = row, j = col, k, l;

    if (last_mover() == FIRST_PLAYER) {
        p.set(2);
        board[row][col].set(2);
    }else {
        p.set(1);
        board[row][col].set(1);
    }
    empty_spot -= 1;

    //right check
    if (col != size-1 && p != board[row][col + 1] && board[row][col + 1] != 3) {
        for (j = col + 1; j != size; j++) {
            if (p == board[row][j]) {
                for (l = col + 1; l != j; l++) {
                    board[row][l].flip();
                }
                break;
            }
        }
    }
    //right down check
    if (col != size-1 && row != size-1 && p != board[row + 1][col + 1] && board[row + 1][col + 1] != 3) {
        j = col + 1;
        for (i = row + 1; i != size && j != size; i++) {
            if (p == board[i][j]) {
                for (k = row + 1, l = col + 1; k != i; k++, l++) {
                    board[k][l].flip();
                }
                break;
            }
            j++;
        }
    }
    //down check
    if (row != size-1 && p != board[row + 1][col] && board[row + 1][col] != 3) {
        for (i = row + 1; i != size; i++) {
            if (p == board[i][col]) {
                for (k = row + 1; k != i; k++) {
                    board[k][col].flip();
                }
                break;
            }
        }
    }
    //left down check
    if (row != size-1 && col != 0 && p != board[row + 1][col - 1] && board[row + 1][col - 1] != 3) {
        j = col - 1;
        for (i = row + 1; i != size && j != -1; i++) {
            if (p == board[i][j]) {
                for (k = row + 1, l = col - 1; k != i; k++, j--) {
                    board[k][l].flip();
                }
                break;
            }
            j--;
        }
    }
    //left check
    if (col != 0 && p != board[row][col - 1] && board[row][col - 1] != 3) {
        for (j = col - 1; j != -1; j--) {
            if (p == board[row][j]) {
                for (l = col - 1; l != j; l--) {
                    board[row][l].flip();
                }
                break;
            }
        }
    }
    //left up check
    if (col != 0 && row != 0 && p != board[row - 1][col - 1] && board[row - 1][col - 1] != 3) {
        j = col - 1;
        for (i = row - 1; i != -1 && j != -1; i--) {
            if (p == board[i][j]) {
                for (k = row - 1, l = col - 1; k != i; k--, l--) {
                    board[k][l].flip();
                }
                break;
            }
            j--;
        }
    }
    //up check
    if (row != 0 && p != board[row - 1][col] && board[row - 1][col] != 3) {
        for (i = row - 1; i != -1; i--) {
            if (p == board[i][col]) {
                for (k = row - 1; k != i; k--) {
                    board[k][col].flip();
                }
                break;
            }
        }
    }
    //right up check
    if (row != 0 && col != size-1 && p != board[row - 1][col + 1] && board[row - 1][col + 1] != 3) {
        j = col + 1;
        for (i = row - 1; i != -1 && j != size; i--) {
            if (p == board[i][j]) {
                for (k = row - 1, l = col + 1; k != i; k--, l++) {
                    board[k][l].flip();
                }
                break;
            }
            j++;
        }
    }
    game::make_move(move);
}

bool othello::is_game_over()const {
    if (empty_spot == 0)
        return true;
    else
        return false;
}

game::who othello::winning() const {
    int count = 0;
    int size = get_board_size();
    piece p;
    p.set(1);
    for (int m = 0; m != size; m++) {
        for (int n = 0; n != size; n++) {
            if (board[m][n] == p)
                count += 1;
        }
    }
    if (count > size*size/2){
        return FIRST_PLAYER;
    }else if (count < size * size / 2){
        return SECOND_PLAYER;
    }else{
        return NEUTRAL;
    }
}
