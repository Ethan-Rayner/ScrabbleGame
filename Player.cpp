#include "Player.h"


Player::Player(std::string name, int score){
    this->name = name;
    this->score = score;
    
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