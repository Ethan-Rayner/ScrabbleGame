
#include "Game.h"
#include <iostream>
#include <fstream>
#define EXIT_SUCCESS 0
#define COLUMNS      15
#define ROWS         15
#define CHAR    'A'

Game::Game(Player player1Initial, Player player2Initial, vector<vector<int>> board){
    player1 = new Player(player1Initial);
    player2 = new Player(player2Initial);
    this->board = board;
}

Game::~Game(){}

void Game::startGame(){

    bool gameGoing = true;
    bool turnPass;
    int passCount1 = 0;
    int passCount2 = 0;
    while(gameGoing){
    //player one turn
    turnPass = false;
    cout << player1->getName() << "'s turn" << endl;
    printBoard();
    turnPass = player1->startTurn();
    //checks if player has passed twice in a row
    if (turnPass){
        passCount1 += 1;
    }
    else{
        passCount1 = 0;
    }
    if (passCount1 == 2){break;}


    //player two turn
    if (gameGoing){
    turnPass = false;
    cout << player2->getName() << "'s turn" << endl;
    printBoard();
    turnPass = player2->startTurn();
    //Checks if player has passed twice in a row
    if (turnPass){
        passCount2 += 1;
    }
    else{
        passCount2 = 0;
    }
    if (passCount2 == 2){break;}
    }

    }
}


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