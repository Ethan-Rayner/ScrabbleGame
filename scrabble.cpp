
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
void loadGame();

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
      vector<vector<int>> board(ROWS, vector<int> (COLUMNS));
      LinkedList player1Hand;
      LinkedList player2Hand;
      Player player1("Player1", 0, player1Hand);
      Player player2("Player2", 0, player2Hand);
      
      //add them to game
      Game game(player1, player2, board);
      game.printBoard();
      game.startGame();
      // NEW GAME CODE HERE
   }
   else if (selection == LOAD_GAME)
   {
      loadGame();
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

void loadGame(){
   std::string filename;
   bool isExist = true;
   ifstream loadFile;
   
   while (isExist){
   cout << "Select a file to open" << endl;
   cin >> filename;
   
   loadFile.open(filename);
   isExist = loadFile.fail();
   if (isExist){
      cout << "Invalid input, please enter the files full name including extensions" << endl;
   }
   }
   string line;

   getline(loadFile, line);
   cout << line;
   vector<vector<int>> board(ROWS, vector<int> (COLUMNS));
   LinkedList player1Hand;
   LinkedList player2Hand;
   Player player1("Player1", 0, player1Hand);
   Player player2("Player2", 0, player2Hand);
   
   //add them to game
   Game game(player1, player2, board);

   


}
//vector<vector<int>> board(ROWS, vector<int> (COLUMNS)) ;

// void printBoard(){

// cout << "    ";
//     //printing out column
//   for(int column = 0; column < COLUMNS; column++){
//      if(column > 9){
//         cout << column << " ";
//      }
//      else{
//         cout << column << "  ";
//      }
        
//     }

//         cout << endl;
//         cout << "------------------------";
//         cout << "------------------------";
//         cout << endl;

// char rowTag = CHAR;

// //Printing out rows
// for (int row = 0; row < ROWS; row++) {
//         cout << rowTag << "  " << "|";     
//         rowTag++;

//         for (int column = 0; column < COLUMNS; column++) {
            
//             if (board[row][column] == 0) { 
//                 cout << "  ";
//             } else {
//                 cout << board[row][column];  
//             }
//             cout << "|"; 
//         } 
//         cout << endl; 
//     }  
     

//}