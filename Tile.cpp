#include <iostream>
#include <string>
#include <fstream>
#include "Tile.h"

using namespace std;
//Constructor
Tile::Tile(char letter, int value)
{
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

void Tile::S_Tile_file()
{
	ifstream file;
	string buf;
	file.open("scrabbletiles.txt", ios::in|ios::binary);
	if (!file.is_open()) 
	{
		cout << "The file is opened fail" << endl;
		return;
	}
	while (getline(file,buf)){}
	file.close();
}

void Tile::S_Dictionary_file() {
	ifstream file;
	string buf;
	file.open("twl06.txt", ios::in | ios::binary);
	if (!file.is_open())
	{
		cout << "The file is opened fail" << endl;
  }
		return;
	}
	while (getline(file, buf)) {}
	file.close();
}
