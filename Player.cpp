#include "Player.h"


Player::Player(std::string name, int score, LinkedList hand){
    this->name = name;
    this->score = score;
    playerHand = new LinkedList(hand);
}

//Deconstructor
Player::~Player(){

}
//printing hand
void Player::printHand(){
        for(int i = 0; i < playerHand->size(); i++){
         cout << playerHand->get(i)->getLetter();
         cout << playerHand->get(i)->getValue() << endl;
      }
}
//getters
std::string Player::getName(){
    return name;
}

LinkedList* Player::getHand(){
    return playerHand;
}

int Player::getScore(){
    return score;
}
//setters
void Player::setName(std::string name){
    this->name = name;
}

void Player::setScore(int score){
    this->score = score;
}


void Player::setHand(LinkedList hand){
    playerHand = new LinkedList(hand);

}




