#ifndef ASSIGN2_PLAYER_H

#include "LinkedList.h"

class Player
{

public:
    Player(std::string name, int score, LinkedList hand);
    ~Player();
    std::string getName();
    int getScore();
    void setScore(int score);
    void setName(std::string name);
    void placeTile(char letter);
    std::string name;
    int startTurn(std::string input);
    void replaceTurn();
    void placeTurn();
    void printHand();
    void drawTile(Tile *newTile);
    LinkedList* getHand();
    
private:
   
   int score;
   LinkedList* playerHand;

};




#endif // ASSIGN2_PLAYER_H
