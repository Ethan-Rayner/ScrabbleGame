#include "Player.h"


Player::Player(std::string name, int score, LinkedList hand){
    this->name = name;
    this->score = score;
    playerHand = new LinkedList(hand);
}

//Deconstructor
Player::~Player(){
    
}

void Player::printHand(){
        for(int i = 0; i < playerHand->size(); i++){
         cout << playerHand->get(i)->getLetter();
         cout << playerHand->get(i)->getValue() << endl;
      }
}

std::string Player::getName(){
    return name;
}

LinkedList* Player::getHand(){
    return playerHand;
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


//TOGO
// int Player::startTurn(std::string input){
//    
//     string addLetter;
//
//     bool isTurn = true;
//     while(isTurn){
//  
//     if (input == "Pass"){
//         return 1;
//     }
//     else if (input == "Replace"){
//         replaceTurn();
//         isTurn = false;
//         return 0;
//     }
//     else if (input == "Place"){
//         addLetter = placeTurn();
//         return 0;
//     }
//     else if (input == "Save"){
//         return 2; //make this 2 to end game immediately?
//     }
//     else{
//         cout << "--Please enter a valid input--" << endl << endl;
//         cout << "You may perform one of the following actions:" << endl << "Place | Pass | Replace" << endl << "You can also save the game at any time by typing 'Save'" << endl;
//         cin >> input;
//     }
//     }
//     return 0;
// }


void Player::replaceTurn(){
    char tile;
    bool isLetter = true;
    while (isLetter){
        cout << "Please select the tile you want to replace" << endl << "> ";
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

char Player::placeTurn(char tile){
    bool isLetter = true;
    while (isLetter){
        cout << "Please select the tile you want to place" << endl << "> ";
        cin >> tile;
        for(int i = 0; i < playerHand->size(); i++){
        if(tile == playerHand->get(i)->getLetter()){
            setScore(getScore() + playerHand->get(i)->getValue());
            playerHand->remove(playerHand->get(i));
            isLetter = false;
            return tile;
        }
        }
    cout << "Please enter a valid tile." << endl;
    }
    tile = '0';
    return tile;
}
