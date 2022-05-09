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

void placeTile(char letter){
    
}