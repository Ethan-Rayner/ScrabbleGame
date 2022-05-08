#ifndef TILES         //Prevent multiple declarations
#define TILES

#include <iostream>                 
#include <string>     
#include <fstream>
using namespace std;

class Tile 
{
public:

	void S_Tile_file();
	void S_Dictionary_file();


private:
	string buff;
	char word_tiles;
	int value;
};
#endif // TILES
