
#ifndef ASSIGN2_GAME_H
#define ASSIGN2_GAME_H

#include "Player.h"
#include <vector>

class Game
{

public:
    Game(Player player1, Player player2, vector<vector<char>> board, LinkedList* tileBag);
    ~Game();
    void printBoard();
    void saveBoard(bool turn); //true is player1, false is player 2
    void startGame();
    bool takeTurn(Player* player);
    void drawPlayer(Player* player);
    int getAction(std::string input, Player* player);


private:
   Player* player1;
   Player* player2;
   vector<vector<char>> board;
   LinkedList* bag;
};


#endif 