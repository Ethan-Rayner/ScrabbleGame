
#include "Game.h"
#include <iostream>



#define EXIT_SUCCESS 0
#define COLUMNS      15
#define ROWS         15
#define CHAR    'A'

Game::Game(Player player1Initial, Player player2Initial, vector<vector<char>> board, LinkedList* tileBag){
    player1 = new Player(player1Initial);
    player2 = new Player(player2Initial);
    this->board = board;
    bag = tileBag;

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
    cin.ignore(1, '\n');

    while(gameGoing){
    //player one turn
        drawPlayer(player1);
        drawPlayer(player2);

        turnPass = 0;
        printBoard();
        cout << player1->getName() << "'s turn" << endl;
        cout << "Hand:";
        printHand(player1);
        turnPass = getAction(player1);

        //checks if player has passed twice in a row, saved or placed/replaced.
        //Save
        if(turnPass == 3){
            saveBoard("tester.txt");
            cout << "Game saved succesfully" << endl;
        }

        if(turnPass == -1){
                break;
            }

        // Place/Replace
        if (turnPass == 0){
            passCount1 = 0;
        }
        // Pass
        passCount1 += turnPass;
        if (passCount1 == 2){
            break;
            }

        //player two turn
        if (gameGoing){
            turnPass = 0;
            printBoard();
            cout << player2->getName() << "'s turn" << endl;
            cout << "Hand:";
            
            printHand(player2);
            turnPass = getAction(player2);
            
            if(turnPass == 3){
                saveBoard("tester.txt");
                cout << "Game saved succesfully" << endl;
            }

            if(turnPass == -1){
                break;
            }

            //checks if player has passed twice in a row, saved or placed/replaced.
            if (turnPass == 0){
                passCount2 = 0;
            }
            passCount2 += turnPass;
            if (passCount2 == 2){
                break;
            }
        }
    }

//     Game over
// Score for <player 1 name>: 000
// Score for <player 2 name>: 000
// Player <winniner player name> won!
// Goodbye
    if(passCount1 == 2 || passCount2 == 2){
        if ((player1->getScore() > player2->getScore())){
            printPostGame(player1);
        }
        else{
            printPostGame(player2);
        }
    }
}

void Game::printPostGame(Player* player){
    cout << "Game Over" << endl << "Score for " << player1->getName() << ": "<< player1->getScore() << endl << "Score for " << player2->getName() << ": " << player2->getScore() << endl;
    cout << player->getName() << " won!" << endl << "Goodbye" << endl;
}

bool Game::replaceTile(Player* player, char letter){

//TODO make this random

    for(int i = 0; i < player->getHand()->size(); i++){
        if(player->getHand()->get(i)->getLetter() == letter){
            Tile* newTile = player->getHand()->get(i);
            player->getHand()->remove(newTile);
            bag->add(newTile);
            break;
        }
    }

    return false;
}


void Game::printHand(Player* player){
            for(int i = 0; i < player->getHand()->size(); i++){
                cout  << " " << player->getHand()->get(i)->getLetter() << "-" << player->getHand()->get(i)->getValue();
            }
}

int Game::getAction(Player* player){
        string command;
        string firstWord; //action
        string secondWord; //instruction
        
        string thirdWord; //at
        string fourthWord; //row&col

        // int placedRow; //store the row the player is currently placing in
        // int placedcol; //store the col the player is currently placing in
        // bool rowPriority = false; // designate the row as the priority
        // bool colPriority = false;

        bool isValid = true;
        int passValue =0;
        //TODO (nextWord[0] <= 'O' && nextWord[0] >= 'A') = between O and A
        //Get action
        while(true){
            //check if entered command is a valid command
            if(!isValid){
                cout << "Invalid input, please try again."<< endl;
            }
            cout << endl <<"> ";
            getline(cin, command);
            if(!cin){
                passValue = -1;
                break;
            }
            stringstream commandStream(command);
            commandStream >> firstWord;

            if (firstWord == "replace"){
                    //check next "word" is a letter and not the same command as before
                    commandStream >> secondWord;
                    //checking != replace, is 1 character long, is a letter
                    if(bag->size() <= 7){
                        if ((!(secondWord == firstWord)) && (secondWord.length() == 1) && (secondWord[0] <= 'Z' && secondWord[0] >= 'A')){
                            replaceTile(player, secondWord[0]);
                            printHand(player);
                            break;
                            }
                            else{
                                isValid = false;
                            }
                    }
                    else{
                        cout << "There arent enough tiles in the bag";
                    }
            }
            else if (firstWord == "pass"){
                passValue = 1;
                break;
            }
            else if (firstWord == "place"){
                    //check next "word" is a letter and not the same command as before
                    commandStream >> secondWord;
                    //checking != replace, is 1 character long, is a letter
                    if ((!(secondWord == firstWord)) && (secondWord.length() == 1) && (secondWord[0] <= 'Z' && secondWord[0] >= 'A')){ // check for 
                        commandStream >> thirdWord; //create at
                        char letter = secondWord[0]; //create letter

                        if ((!(secondWord == thirdWord)) && (thirdWord== "at")){ // check for at
                            commandStream >> fourthWord; // create position

                            if ((!(thirdWord == fourthWord)) && (fourthWord.length() == 2) && (fourthWord[0] <= 'Z' && fourthWord[0] >= 'A') && (isdigit(fourthWord[1]))){ // if row is a letter and col is a number
                                int row =  fourthWord[0] - 'A'; // set row
                                int col =  int(fourthWord[1]) - '0'; //set col

                                    for(int i = 0; i < player->getHand()->size(); i++) // loop through hand

                                        if (player->getHand()->get(i)->getLetter() == letter){ // check letter is in hand

                                            if(board[row][col] != 0){ // check tile isnt already on the board
                                                cout << "Space already taken by another tile.";
                                            }
                                            else{ //else if space is empty, place tile on space and add score to player
                                                board[row][col] = letter;
                                                player->setScore(player->getScore() + player->getHand()->get(i)->getValue());
                                                player->getHand()->remove(player->getHand()->get(i));
                                                printHand(player);
                                            }
                                            isValid = true;
                                            break;
                                    }
                                    else{
                                            isValid = false;
                                    }
                                    
                            }
                            else{
                                isValid = false;
                            }

                            if (player->getHand()->size() == 0 && isValid){
                                        cout << "BINGO";
                                        player->setScore(player->getScore() + 50);
                                    }
                        }
                        else{
                            isValid = false;
                        }
                }
                else if((!(secondWord == firstWord)) && (secondWord == "Done")){
                    break;
                }

                else{
                    isValid = false;
                }
            }
            else if(firstWord == "save"){
                passValue = 3;
                commandStream >> secondWord;
                if (!(secondWord == firstWord)){
                saveBoard(secondWord);
                break;
                }
                else{
                    isValid = false;
                }
            }
            else{
                    isValid = false;
                }
        
    }
    return passValue;
}

int Game::genRand(){
    // randomises order drawn from tile bag
    int min = 1;
    int max = bag->size();

    std::random_device engine;
    std::uniform_int_distribution<int> uniform_dist(min, max);
    return uniform_dist(engine);
}

void Game::drawPlayer(Player* player){


    //gets random tile  from bag and adds to player hand until player hand is full
    for (int i = 0; player->getHand()->size() < 7; i++){
        Tile* newTile = bag->get(genRand());
        player->getHand()->add(newTile);
        bag->remove(newTile);
        }
    }

void Game::saveBoard(string fileName){

std::ofstream outfile(fileName);
//p1 hand
outfile << player1->getName() << endl << player1->getScore() << endl;
for(int i =0; i< player1->getHand()->size(); i++){
    outfile << player1->getHand()->get(i)->getLetter() << "-" << player1->getHand()->get(i)->getValue() << " ";
}
//p2 hand
outfile << endl <<  player2->getName() << endl << player2->getScore() << endl;
for(int i =0; i< player2->getHand()->size(); i++){
    outfile << player2->getHand()->get(i)->getLetter() << "-" << player2->getHand()->get(i)->getValue() << " ";
}
    //printing out column
outfile << endl;
char rowTag = CHAR;

//Printing out rows
  for(int column = 0; column < COLUMNS; column++){
     if(column > 9){
        outfile << column << "  " ;
     }
     else{
        outfile << column << "   " ;
     }
        
    }

        outfile << endl;
        outfile << "-----------------------------------------------------------------";
        outfile << endl;

//Printing out rows
for (int row = 0; row < ROWS; row++) {
        outfile << rowTag << "   " << "|";     
        rowTag++;

        for (int column = 0; column < COLUMNS; column++) {
            
            if (board[row][column] == 0) { 
                outfile <<" " << 0 << " ";
            } else {
                outfile << " " << board[row][column] << " ";  
            }
            outfile << "|"; 
        } 
        outfile << endl; 
    }
}



void Game::printBoard(){

cout << player1->getName() << " score: " << player1->getScore() << endl;
cout << player2->getName() << " score: " << player2->getScore() << endl << endl;
cout << "      ";
    //printing out column
  for(int column = 0; column < COLUMNS; column++){
     if(column > 9){
        cout << column << "  " ;
     }
     else{
        cout << column << "   " ;
     }
        
    }

        cout << endl;
        cout << "-----------------------------------------------------------------";
        cout << endl;

char rowTag = CHAR;

//Printing out rows
for (int row = 0; row < ROWS; row++) {
        cout << rowTag << "   " << "|";     
        rowTag++;

        for (int column = 0; column < COLUMNS; column++) {
            
            if (board[row][column] == 0) { 
                cout << "   ";
            } else {
                cout << " " << board[row][column] << " ";  
            }
            cout << "|"; 
        } 
        cout << endl; 
    }  
     
}