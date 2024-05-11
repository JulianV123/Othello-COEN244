#include "Position.h"
#include "PlayablePosition.h"
#include "Player.h"
#include <string>
#ifndef COEN244_ASSIGNMENT2_BOARD_H
#define COEN244_ASSIGNMENT2_BOARD_H
using namespace std;

class Board {

private:
    Position board[8][8]; //Store all board positions in this 2D array of positions
    string positions; //Added this to make the constructor for Board work.

public:
    Board(string positions);
    bool setBoard(); //Added this to set the board in one of the 4 starting positions
    void drawBoard();

    void setBoardPosition(int i, int j, Position p) {
        board[i][j] = p;
    }

    char getBoardPosition(int i, int j) {
        return board[i][j].getPiece();
    }

};

#endif //COEN244_ASSIGNMENT2_BOARD_H
