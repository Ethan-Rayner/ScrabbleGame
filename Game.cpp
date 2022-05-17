
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

Game::~Game(){
    delete player1;
    delete player2;
    delete bag;
}

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

void Game::loadGame(){
    //get file name
    string filename;
    cout << "Please enter a filename" << endl << "> ";
    cin >> filename;

    if ((!cin.eof())){

    //declare variables and load file
    bool isExist = true;
    ifstream loadFile;
    while (isExist){
        loadFile.open(filename);
        isExist = loadFile.fail();
        if (isExist){
            cout << "Invalid input, please enter the files full name including extensions" << endl;   
        }
    }

    int num1 = 0;
    int num2 = 0;
    int score = 0;
    string hand1;
    string hand2;
    vector<string> lines;
    string line;
    

    while (getline(loadFile, line)){
        lines.push_back(line);
    }


    //get player 1 input

    //name
    player1->setName(lines[0]);
    //score
    player1->setScore(stoi(lines[1]));
    //hand string
    hand1 = lines[2];
    loadFile.ignore(1, '\n');
    //add tiles to player hand
    //create player 1
    string nextWord;
    stringstream hand1SS(hand1);

    // adds tiles to a playerhand linked list
    while(hand1SS >> nextWord){
        string word = nextWord;
        if(nextWord.length() == 4){
            num1 =  (int((word[2])-'0')); //set grab both chars
            num2 = (int((word[3])-'0'));
            string value = to_string(num1) + to_string(num2);
            score = stoi(value);
        }
        else{
            num1 =  (int((word[2])-'0'));
            string value = to_string(num1);
            score = stoi(value);
        }
        Tile* newTile = new Tile(word[0], score);
        player1->getHand()->add(newTile); //broken
    }

        //name
    player2->setName(lines[3]);
    //score
    player2->setScore(stoi(lines[4]));
    //hand string
    hand2 = lines[5];
    loadFile.ignore(1, '\n');
    //add tiles to player hand
    //create player 2

    stringstream hand2SS(hand2);
    while(hand2SS >> nextWord){
        string word = nextWord;
        if(nextWord.length() == 4){
            num1 =  (int((word[2])-'0')); //set grab both chars
            num2 = (int((word[3])-'0'));
            string value = to_string(num1) + to_string(num2);
            score = stoi(value);
        }
        else{
            num1 =  (int((word[2])-'0'));
            string value = to_string(num1);
            score = stoi(value);
        }
        Tile* newTile = new Tile(word[0], score);
        player2->getHand()->add(newTile);
        
    }

    //create bag

    int offset = 6;
    int charOffset = 3;
    for(int i =0; i < COLUMNS; i++){
        string boardLine = lines[8 + i];
        for(int j = 0; j < ROWS; j++){ 
            int index = (offset + j) + (j*charOffset);
            char letter = boardLine[index];
            board[i][j] = letter;
        
        }
    }
    string newLine;

    newLine = lines[24];
    stringstream tileBagStream(newLine);
    //add tiles to player hand
    while(tileBagStream >> nextWord){
    string word = nextWord;
        if(nextWord.length() == 4){
            num1 =  (int((word[2])-'0')); //set grab both chars
            num2 = (int((word[3])-'0'));
            string value = to_string(num1) + to_string(num2);
            score = stoi(value);
        }
        else{
            num1 =  (int((word[2])-'0'));
            string value = to_string(num1);
            score = stoi(value);
        }
        Tile* newTile = new Tile(word[0], score);
        bag->add(newTile);
    }

    startGame();
    }

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

                            if ((!(thirdWord == fourthWord)) && (fourthWord.length() == 2) && (fourthWord[0] <= 'O' && fourthWord[0] >= 'A') && (isdigit(fourthWord[1]))){ // if row is a letter and col is a number
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
                                            }
                                            isValid = true;
                                            break;
                                    }
                                    else{
                                            isValid = false;
                                    }
                                    
                            }

                            else if ((!(thirdWord == fourthWord)) && (fourthWord.length() == 3) && (fourthWord[0] <= 'O' && fourthWord[0] >= 'A') && (isdigit(fourthWord[1])) && (isdigit(fourthWord[2]))){ // if row is a letter and col is a number
                                int row =  fourthWord[0] - 'A'; // set row
                                int col1 =  (int(fourthWord[1]) - '0'); //set col
                                int col2 = (int(fourthWord[2]) - '0');
                                string colTemp = to_string(col1) + to_string(col2);
                                int col = stoi(colTemp);
                                    for(int i = 0; i < player->getHand()->size(); i++) // loop through hand

                                        if (player->getHand()->get(i)->getLetter() == letter){ // check letter is in hand

                                            if(board[row][col] != 0){ // check tile isnt already on the board
                                                cout << "Space already taken by another tile.";
                                            }
                                            else{ //else if space is empty, place tile on space and add score to player
                                                board[row][col] = letter;
                                                player->setScore(player->getScore() + player->getHand()->get(i)->getValue());
                                                player->getHand()->remove(player->getHand()->get(i));
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
    int max = bag->size() -1 ;
    std::random_device engine;
    std::uniform_int_distribution<int> uniform_dist(min, max);
    
    return uniform_dist(engine);
}

void Game::drawPlayer(Player* player){


    //gets random tile  from bag and adds to player hand until player hand is full
    for (int i = 0; player->getHand()->size() < 7; i++){
        int num = genRand();
        Tile* newTile = bag->get(num);
        player->getHand()->add(newTile);
        bag->remove(newTile);
        }
    }

void Game::saveBoard(string fileName){

std::ofstream outfile(fileName);
//p1 hand output
outfile << player1->getName() << endl << player1->getScore() << endl;
for(int i =0; i< player1->getHand()->size(); i++){
    outfile << player1->getHand()->get(i)->getLetter() << "-" << player1->getHand()->get(i)->getValue() << " ";
}
//p2 hand output
outfile << endl <<  player2->getName() << endl << player2->getScore() << endl;
for(int i =0; i< player2->getHand()->size(); i++){
    outfile << player2->getHand()->get(i)->getLetter() << "-" << player2->getHand()->get(i)->getValue() << " ";
}


    //output column
outfile << endl;
char rowTag = CHAR;

//output rows
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

//output rows
for (int row = 0; row < ROWS; row++) {
        outfile << rowTag << "   " << "|";     
        rowTag++;

        for (int column = 0; column < COLUMNS; column++) {
            
            if (board[row][column] == 0) { 
                outfile <<" " << ' ' << " ";
            } else {
                outfile << " " << board[row][column] << " ";  
            }
            outfile << "|"; 
        } 
        outfile << endl; 
    }

//tile bag output
for(int i =0; i< bag->size(); i++){
    outfile << bag->get(i)->getLetter() << "-" << bag->get(i)->getValue() << " ";
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
            
            if (board[row][column] == 0 || board[row][column] == '0') { 
                cout << "   ";
            } else {
                cout << " " << board[row][column] << " ";  
            }
            cout << "|"; 
        } 
        cout << endl; 
    }  
     
}