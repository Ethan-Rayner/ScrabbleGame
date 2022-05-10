#include "Player.h"


Player::Player(std::string name, int score, LinkedList hand){
    this->name = name;
    this->score = score;
    playerHand = new LinkedList(hand);
}

//Deconstructor
Player::~Player(){
    
}

std::string Player::getName(){
    return name;
}

int Player::getScore(){
    return score;
}

void Player::setName(std::string name){
    this->name = name;
}

void Player::setScore(int score){
    this->score = score;
}

int Player::startTurn(std::string input){
    
    bool isTurn = true;
    while(isTurn){
    
    if (input == "Pass"){
        return 1;
    }
    else if (input == "Replace"){
        replaceTurn();
        isTurn = false;
        return 0;
    }
    else if (input == "Place"){
        placeTurn();
        return 0;
    }
    else if (input == "Save"){
        return 2; //make this 2 to end game immediately?
    }
    else{
        cout << "--Please enter a valid input--" << endl << endl;
        cout << "You may perform one of the following actions:" << endl << "Place | Pass | Replace" << endl << "You can also save the game at any time by typing 'Save'" << endl;
        cin >> input;
    }
    }
    return 0;
}


void Player::replaceTurn(){
    char tile;
    bool isLetter = true;
    while (isLetter){
        cout << "Please select the tile you want to replace" << endl;
        cin >> tile;
        if(isalpha(tile)){
            cout << "Replaced tile: " << tile << endl;
            isLetter = false;
        }
        else{
            cout << "Please enter a valid tile." << endl;
        }

    }
}

void Player::placeTurn(){
    char tile;
    bool isLetter = true;
    while (isLetter){
        cout << "Please select the tile you want to place" << endl;
        cin >> tile;
        if(isalpha(tile)){
            cout << "Placed tile: " << tile << endl;
            isLetter = false;
        }
        else{
            cout << "Please enter a valid tile." << endl;
        }

    }
}
