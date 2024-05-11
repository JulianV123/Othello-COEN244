#include "Player.h"
#include "Board.h"
#ifndef COEN244_ASSIGNMENT2_GAME_H
#define COEN244_ASSIGNMENT2_GAME_H
using namespace std;

class Game {

private:
    Player first;
    Player *current = &first;
    Player second;
    Board board;
    void save();

public:
    Game(Player p1, Player p2);

    void start();
    Game load();
    void play(bool isSavedGame);
    bool makeMove();
    void flipPieces(Position piece1, int row, int column);
    void verifyWinner();
    void takeTurn();

};


#endif //COEN244_ASSIGNMENT2_GAME_H
