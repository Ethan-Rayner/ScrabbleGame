
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
    int turnPass;
    int passCount1 = 0;
    int passCount2 = 0;
    std::string input;
    while(gameGoing){
    //player one turn
    turnPass = 0;
    cout << player1->getName() << "'s turn" << endl;
    printBoard();
    cout << "You may perform one of the following actions:" << endl << "Place | Pass | Replace" << endl << "You can also save the game at any time by typing 'Save'" << endl;
    cin >> input;
    turnPass = player1->startTurn(input);
    //checks if player has passed twice in a row
    if (turnPass == 0){
        passCount1 = 0;
    }
    passCount1 += turnPass;
    if (passCount1 == 2){
        saveBoard(false);
        break;
        }

    //player two turn
    if (gameGoing){
    turnPass = 0;
    cout << player2->getName() << "'s turn" << endl;
    printBoard();
    cout << "You may perform one of the following actions:" << endl << "Place | Pass | Replace" << endl << "You can also save the game at any time by typing 'Save'" << endl;
    cin >> input;
    turnPass = player2->startTurn(input);
    //Checks if player has passed twice in a row
    if (turnPass == 0){
        passCount2 = 0;
    }
    passCount2 += turnPass;
    if (passCount2 == 2)
    {break;
    saveBoard(true);
    }
    }
    
    }
}

void Game::saveBoard(bool turn){
std::ofstream outfile ("test.txt");

outfile << player1->getName() << " " <<  player1->getScore() << endl;
outfile << player2->getName() << " " << player2->getScore() << endl;
    //printing out column
        
char rowTag = CHAR;

//Printing out rows
for (int row = 0; row < ROWS; row++) {
        rowTag++;

        for (int column = 0; column < COLUMNS; column++) {
                outfile << board[row][column]; 
        } 
        outfile << endl; 
    }  

    outfile.close();
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