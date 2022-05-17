#include <iostream>
#include <string>
#include <fstream>
#include "Tile.h"


using namespace std;
//Constructor
Tile::Tile(char letter, int value)
{
	//setters
	this->letter = letter;
	this->value = value;
}

Tile::~Tile()
{

}

// Getters
char Tile::getLetter(){
	return letter;
}

int Tile::getValue(){
	return value;
}
