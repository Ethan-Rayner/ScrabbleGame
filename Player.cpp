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

bool Player::startTurn(){
    std::string input;
    bool isTurn = true;

    while(isTurn){
    cout << "You may perform one of the following actions:" << endl << "Place | Pass | Replace" << endl;
    cin >> input;
    if (input == "Pass"){
        isTurn = false;
        return true;
    }
    else if (input == "Replace"){
        replaceTurn();
        isTurn = false;
        return false;
    }
    else if (input == "Place"){
        placeTurn();
        isTurn = false;
        return false;
    }
    else if (input == "Save"){
        isTurn=false;
        return false; //make this 2 to end game immediately?
    }
    else{
        cout << "--Please enter a valid input--" << endl << endl;
        
    }
    }
    return false;
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
