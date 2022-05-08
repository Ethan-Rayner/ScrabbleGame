#ifndef ASSIGN2_PLAYER_H

#include "LinkedList.h"

class Player
{

public:
    Player(std::string name, int score);
    ~Player();
    std::string getName();
    int getScore();
    std::string setName();
    int setScore();

    

};




#endif // ASSIGN2_PLAYER_H
