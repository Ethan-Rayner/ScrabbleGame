
#ifndef ASSIGN2_GAME_H
#define ASSIGN2_GAME_H

#include "Player.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <random>

class Game
{

public:
    Game(Player player1, Player player2, vector<vector<char>> board, LinkedList* tileBag);
    ~Game();
    void printBoard();
    void saveBoard(string filename); //true is player1, false is player 2
    void startGame();
    bool takeTurn(Player* player);
    void drawPlayer(Player* player);
    int getAction(Player* player);
    bool placeTile(Player* player, char letter, int row, char col);
    bool replaceTile(Player* player, char letter);
    void printHand(Player* player);
    void printPostGame(Player* player);
    void loadGame();
    int genRand();


private:
   Player* player1;
   Player* player2;
   vector<vector<char>> board;
   LinkedList* bag;
};


#endif 