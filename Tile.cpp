#include <iostream>
#include <string>
#include <fstream>
#include "Tiles.h"
using namespace std;

Tile::Tile()
{
}

Tile::~Tile()
{
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
