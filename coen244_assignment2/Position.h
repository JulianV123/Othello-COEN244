
#ifndef COEN244_ASSIGNMENT2_POSITION_H
#define COEN244_ASSIGNMENT2_POSITION_H
#include <string>

using namespace std;

class Position {

private:
    char piece;

public:
    virtual bool canPlay();
    static const char UNPLAYABLE = '*';
    static const char EMPTY = '-'; //Updated the character to visualize the empty spaces better
    static const char BLACK = 'B';
    static const char WHITE = 'W';

    char getPiece() {
        return piece;
    }

    void setPiece(char p) {
        piece = p;
    }

};

#endif //COEN244_ASSIGNMENT2_POSITION_H
