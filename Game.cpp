
#include "Game.h"
#define EXIT_SUCCESS 0
#define COLUMNS      26
#define ROWS         26
#define CHAR    'A'

Game::Game(Player player1Initial, Player player2Initial, vector<vector<int>> board){
    player1 = new Player(player1Initial);
    player2 = new Player(player2Initial);
    this->board = board;
}

Game::~Game(){}

void Game::printBoard(){

cout << player1->getName() << " score: " << player1->getScore() << endl;
cout << player2->getName() << " score: " << player2->getScore() << endl << endl;
cout << "    ";
    //printing out column
  for(int column = 0; column < COLUMNS; column++){
     if(column > 9){
        cout << column << " ";
     }
     else{
        cout << column << "  ";
     }
        
    }

        cout << endl;
        cout << "------------------------";
        cout << "------------------------";
        cout << endl;

char rowTag = CHAR;

//Printing out rows
for (int row = 0; row < ROWS; row++) {
        cout << rowTag << "  " << "|";     
        rowTag++;

        for (int column = 0; column < COLUMNS; column++) {
            
            if (board[row][column] == 0) { 
                cout << "  ";
            } else {
                cout << board[row][column];  
            }
            cout << "|"; 
        } 
        cout << endl; 
    }  
     
}