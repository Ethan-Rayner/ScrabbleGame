
#include "LinkedList.h"
#include "Game.h"
#include <iostream>
#include <vector>


#define EXIT_SUCCESS 0
#define COLUMNS      15
#define ROWS         15
#define CHAR    'A'

using std::vector;
using std::cout;
using std::cin;
using std::endl;

void printBoard();
void loadGame(string filename);
LinkedList* createBag(LinkedList* tileBag, bool gameLoad);

int main(void)
{
   LinkedList *list = new LinkedList();
   int selection, NEW_GAME = 1, LOAD_GAME = 2, CREDITS = 3, EXIT = 4;
   delete list;

   /*
    * MAIN MENU
    */
   // Welcome Message
   cout << "Welcome to Scrabble!\n-------------------\n"
             << endl;

   // Main Menu Prompt
   cout << "Menu\n----\n1. New Game\n2. Load Game\n3. Credits (Show student information\n4. Quit\n\n> "
             << "";
   cin >> selection;
   cout << "" << endl;

   // Menu selection
   if (selection == NEW_GAME)
   {
      //create new game objects
      vector<vector<char>> board(ROWS, vector<char> (COLUMNS));
      LinkedList player1Hand;
      LinkedList player2Hand;
      LinkedList* tileBag = new LinkedList();
      tileBag = createBag(tileBag, false);
      Player player1("Player1", 0, player1Hand);
      Player player2("Player2", 0, player2Hand);
      //add them to game
      Game game(player1, player2, board, tileBag);
      game.startGame();
      // NEW GAME CODE HERE
   }
   else if (selection == LOAD_GAME)
   {
      
      LinkedList* tileBag = new LinkedList();
      tileBag = createBag(tileBag, true);
      for(int i = 0; i < tileBag->size(); i++){
         cout << tileBag->get(i)->getLetter();
         cout << tileBag->get(i)->getValue() << endl;
      }

   }
   else if (selection == CREDITS)
   {
      cout << "----------------------------------" << endl;
      cout << "Name: Shuo Zhou\nStudent ID: s3849606\nEmail: s3849606@student.rmit.edu.au\n" << endl;
      cout << "Name: Ethan Rayner\nStudent ID: s3902240\nEmail: s3902240@student.rmit.edu.au\n" << endl;
      cout << "Name: Joanna Tepaa\nStudent ID: s3680413\nEmail: s3680413@student.rmit.edu.au\n" << endl;
      cout << "Name: Fei Mo\nStudent ID: s3754501\nEmail: s3754501@student.rmit.edu.au" << endl;
      cout << "----------------------------------" << endl;
   }
   else if (selection == EXIT)
   {
      cout << "Goodbye" << endl;
      return EXIT_SUCCESS;
   }
   else
   {
      cout << "Sorry, that is not a valid option." << endl;
   }

   return EXIT_SUCCESS;
}

void loadGame(string filename){
   bool isExist = true;
   ifstream loadFile;
   
   while (isExist){
   
   loadFile.open(filename);
   isExist = loadFile.fail();
   if (isExist){
      cout << "Invalid input, please enter the files full name including extensions" << endl;
   }
   }
   string line;

   getline(loadFile, line);
   cout << line;
   vector<vector<char>> board(ROWS, vector<char> (COLUMNS));
   LinkedList player1Hand;
   LinkedList player2Hand;
   LinkedList* tileBag = new LinkedList();
   tileBag = createBag(tileBag, true);
   Player player1("Player1", 0, player1Hand);
   Player player2("Player2", 0, player2Hand);
   
   //add them to game
   Game game(player1, player2, board, tileBag);

   


}

LinkedList* createBag(LinkedList* tileBag, bool gameLoad)
{
   string inputFile = "ScrabbleTiles.txt";
   if (gameLoad){
      cout << "Please enter the filename to load" << endl << "> ";
      cin >> inputFile;
      //loadGame(inputFile);
      //call loadGame here
   }
   ifstream file;
   string line;
   file.open(inputFile, ios::in | ios::binary);
   // checking if file is open
   if (file.is_open())
   {
      while (getline(file, line))
      {
         std::string delimiter = " ";
         std::string letter = line.substr(0, line.find(delimiter));
         string value = line.substr(line.find(delimiter), -1);
         int score = stoi(value);
         char letterChar = letter[0];
         Tile* newTile = new Tile(letterChar, score);
         tileBag->add(newTile);
   }
   
   }
   return tileBag;
}

