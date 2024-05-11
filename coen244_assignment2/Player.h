#include <string>
#include "Position.h"

#ifndef COEN244_ASSIGNMENT2_PLAYER_H
#define COEN244_ASSIGNMENT2_PLAYER_H
using namespace std;

class Player {

private:
    string name;
    int pieceCount; //Added this to keep track of how many pieces the players have
    Position piece;

public:
    Player(string name);

    string getName() {
        return name;
    }

    void setName(string n) {
        name = n;
    }

    int getPieceCount() {
        return pieceCount;
    }

    void setPieceCount(int p) {
        pieceCount = p;
    }

    Position getPiece() {
        return piece;
    }

    void setPiece(Position p) {
        piece = p;
    }

};

#endif //COEN244_ASSIGNMENT2_PLAYER_H
