
#ifndef ASSIGN2_GAME_H
#define ASSIGN2_GAME_H

#include "Player.h"
#include <vector>

class Game
{

public:
    Game(Player player1, Player player2, vector<vector<int>> board);
    ~Game();
    void printBoard();
    void startGame();


private:
   Player* player1;
   Player* player2;
   vector<vector<int>> board;
};


#endif 