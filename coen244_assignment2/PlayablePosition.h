#include "Position.h"
#ifndef COEN244_ASSIGNMENT2_PLAYABLEPOSITION_H
#define COEN244_ASSIGNMENT2_PLAYABLEPOSITION_H
using namespace std;

class PlayablePosition : public Position {

public:
    bool canPlay() override;
};

#endif //COEN244_ASSIGNMENT2_PLAYABLEPOSITION_H
