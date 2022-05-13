
#include "Game.h"
#include <iostream>
#include <fstream>
#define EXIT_SUCCESS 0
#define COLUMNS      15
#define ROWS         15
#define CHAR    'A'

Game::Game(Player player1Initial, Player player2Initial, vector<vector<char>> board, LinkedList* tileBag){
    player1 = new Player(player1Initial);
    player2 = new Player(player2Initial);
    this->board = board;
    bag = tileBag;
    //drawPlayer(); //TODO make players draw up to 7 tiles

}

Game::~Game(){}

//TODO condense startGame into here 
// void Game::takeTurn(Player* player){
//     bool gameGoing = true;
//     int turnPass;
//     int passCount1 = 0;
//     int passCount2 = 0;
//     std::string input;
//     //player one turn
//     turnPass = 0;
//     cout << player->getName() << "'s turn" << endl;
//     printBoard();
//     cout << "You may perform one of the following actions:" << endl << "Place | Pass | Replace" << endl << "You can also save the game at any time by typing 'Save'" << endl;
//     cin >> input;
//     turnPass = player->startTurn(input);
//     //checks if player has passed twice in a row
//     if (turnPass == 0){
//         passCount1 = 0;
//     }
//     passCount1 += turnPass;
//     if (passCount1 == 2){
//         saveBoard(false);
//     }
// }

void Game::startGame(){

    bool gameGoing = true;
    int turnPass;
    int passCount1 = 0;
    int passCount2 = 0;
    std::string input;
    while(gameGoing){
    //player one turn
    drawPlayer(player1);

    turnPass = 0;
    cout << player1->getName() << "'s turn" << endl;
    printBoard();
    cout << "Hand:";
    for(int i = 0; i < player1->getHand()->size(); i++){
        cout << " " << player1->getHand()->get(i)->getLetter() << "-" << player1->getHand()->get(i)->getValue() << ",";
    }
    cout << endl << "You may perform one of the following actions:" << endl << "Place | Pass | Replace" << endl << "You can also save the game at any time by typing 'Save'" << endl << "> ";
    cin >> input;
    turnPass = getAction(input, player1);
    //checks if player has passed twice in a row
    if(turnPass == 2){
        saveBoard(false);
        break;
    }
    if (turnPass == 0){
        passCount1 = 0;
    }
    passCount1 += turnPass;
    if (passCount1 == 2){
        break;
        }

    //player two turn
    if (gameGoing){
    drawPlayer(player2);
    turnPass = 0;
    cout << player2->getName() << "'s turn" << endl;
    printBoard();
    cout << "Hand:";
        for(int i = 0; i < player2->getHand()->size(); i++){
        cout  << " " << player2->getHand()->get(i)->getLetter() << "-" << player2->getHand()->get(i)->getValue();
    }
    cout << endl << "You may perform one of the following actions:" << endl << "Place | Pass | Replace" << endl << "You can also save the game at any time by typing 'Save'" << endl << "> ";
    cin >> input;
    turnPass = getAction(input, player2);
    if(turnPass == 2){
        saveBoard(true);
        break;
    }
    //Checks if player has passed twice in a row
    if (turnPass == 0){
        passCount2 = 0;
    }
    passCount2 += turnPass;
    if (passCount2 == 2)
    {break;
    }
    }
    
    }
}

int Game::getAction(std::string input, Player* player){
        
    char addLetter = '0';
    string location;
    string isDone = "";
    string column = "0";
    int row =0;
    const int asciiConversion = 65;
    bool isTurn = true;
    while(isTurn){
    
    if (input == "Pass"){
        return 1;
    }
    else if (input == "Replace"){
        player->replaceTurn();
        isTurn = false;
        return 0;
    }
    else if (input == "Place"){
        while(isDone != "Done"){
        addLetter = player->placeTurn(addLetter);
        cout << "Please enter a row and column to place your tile in. (e.g. A1)" << endl << "> ";
        cin >> location;
        column = (location[1]);
        row = int(location[0]) - asciiConversion;
        board[row][stoi(column)] = addLetter;
        return 0;
        }
    }
    else if (input == "Save"){
        return 2; //make this 2 to end game immediately?
    }
    else{
        cout << "--Please enter a valid input--" << endl << endl;
        cout << "You may perform one of the following actions:" << endl << "Place | Pass | Replace" << endl << "You can also save the game at any time by typing 'Save'" << endl << "> ";
        cin >> input;
    }
    }
    return 0;
}

void Game::drawPlayer(Player* player){

    for (int i = 0; player->getHand()->size() < 7; i++){
        Tile* newTile = bag->get(i);
        player->getHand()->add(newTile);
        bag->remove(newTile);
        }
    }

void Game::saveBoard(bool turn){
string fileName;
cout << "Where would you like to save?";
cin >> fileName;

std::ofstream outfile (fileName);

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
                cout << board[row][column] << " ";  
            }
            cout << "|"; 
        } 
        cout << endl; 
    }  
     
}