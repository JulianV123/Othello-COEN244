#include "Board.h"
#include <iostream>
using namespace std;

Board::Board(string p) {
    this -> positions = p;
}

bool Board::setBoard() {
    bool tryAgain = true;
    Position black;
    Position white;
    Position empty;
    Position unplayable;
    int choice1;
    int choice2;

    black.setPiece(Position::BLACK);
    white.setPiece(Position::WHITE);
    empty.setPiece(Position::EMPTY);
    unplayable.setPiece(Position::UNPLAYABLE);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {    //Initialize the board with empty spaces
            board[i][j] = empty;
        }
    }

    for (int i = 2; i < 6; i++) {
        board[0][i] = unplayable;       //Set the unplayable positions at the top of the board
    }

    while(tryAgain) {

        cout << "Which starting position would you like to take?\n"
                "1. Offset starting position\n"
                "2. Four-by-Four starting position\n";

        cin >> choice1;

        switch (choice1) {

            case 1: {

                cout << "Which offset starting position would you like to take?\n"
                        "1. Top-left\n"
                        "2. Top-right\n"
                        "3. Bottom-left\n"
                        "4. Bottom-right\n";

                cin >> choice2;

                switch (choice2) {

                    case 1: {
                        board[2][2] = white;
                        board[2][3] = black;
                        board[3][2] = black;
                        board[3][3] = white;
                        return true;
                    }
                    case 2: {
                        board[2][4] = white;
                        board[2][5] = black;
                        board[3][4] = black;
                        board[3][5] = white;
                        return true;
                    }
                    case 3: {
                        board[4][2] = white;
                        board[4][3] = black;
                        board[5][2] = black;
                        board[5][3] = white;
                        return true;
                    }
                    case 4: {
                        board[4][4] = white;
                        board[4][5] = black;
                        board[5][4] = black;
                        board[5][5] = white;
                        return true;
                    }
                    default: {
                        cout << "Invalid number, please try again:" << endl;
                        tryAgain = true;
                        break;
                    }
                }
                break;
            }
            case 2: {
                board[2][2] = white;
                board[2][3] = white;
                board[3][2] = white;
                board[3][3] = white;
                board[2][4] = black;
                board[2][5] = black;
                board[3][4] = black;
                board[3][5] = black;
                board[4][2] = black;
                board[4][3] = black;
                board[5][2] = black;
                board[5][3] = black;
                board[4][4] = white;
                board[4][5] = white;
                board[5][4] = white;
                board[5][5] = white;
                return false;
            }
            default: {
                cout << "Invalid number, please try again:" << endl;
                tryAgain = true;
                break;
            }
        }
    }
}

void Board::drawBoard() {

    cout << "        0       1       2       3       4       5       6       7" << endl;
    for (int i = 0; i < 8; i++) {
        cout << i;
        for (int j = 0; j < 8; j++) {
            cout << "\t" << board[i][j].getPiece();
        }
        cout << endl;
    }

}