#ifndef ASSIGN2_PLAYER_H

#include "LinkedList.h"

class Player
{

public:
    Player(std::string name, int score);
    ~Player();
    std::string getName();
    int getScore();
    void setScore(int score);
    void setName(std::string name);
    


private:
   string name;
   int score;

};




#endif // ASSIGN2_PLAYER_H
