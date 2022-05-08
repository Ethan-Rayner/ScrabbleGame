#ifndef TILES         //Prevent multiple declarations
#define TILES

#include <iostream>                 
#include <string>     
#include <fstream>
using namespace std;

class Tile 
{
public:
	Tile(char letter, int value);
	~Tile();
	void S_Tile_file();
	void S_Dictionary_file();
	char getLetter();
	int getValue();


private:
	string buff;
	char word_tiles;
	char letter;
	int value;
};
#endif // TILES
