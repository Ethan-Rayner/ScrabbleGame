
#include "LinkedList.h"

#include <iostream>

#define EXIT_SUCCESS 0

int main(void)
{
   LinkedList *list = new LinkedList();
   int selection, NEW_GAME = 1, LOAD_GAME = 2, CREDITS = 3, EXIT = 4;
   delete list;

   /*
    * MAIN MENU
    */
   // Welcome Message
   std::cout << "Welcome to Scrabble!\n-------------------\n"
             << std::endl;

   // Main Menu Prompt
   std::cout << "Menu\n----\n1. New Game\n2. Load Game\n3. Credits (Show student information\n4. Quit\n\n> "
             << "";
   std::cin >> selection;
   std::cout << "" << std::endl;

   // Menu selection
   if (selection == NEW_GAME)
   {
      // NEW GAME CODE HERE
   }
   else if (selection == LOAD_GAME)
   {
      // LOAD GAME CODE HERE
   }
   else if (selection == CREDITS)
   {
      std::cout << "----------------------------------" << std::endl;
      std::cout << "Name: Shuo Zhou\nStudent ID: s3849606\nEmail: s3849606@student.rmit.edu.au\n" << std::endl;
      std::cout << "Name: Ethan Rayner\nStudent ID: s3902240\nEmail: s3902240@student.rmit.edu.au\n" << std::endl;
      std::cout << "Name: Joanna Tepaa\nStudent ID: s3680413\nEmail: s3680413@student.rmit.edu.au\n" << std::endl;
      std::cout << "Name: Fei Mo\nStudent ID: s3754501\nEmail: s3754501@student.rmit.edu.au" << std::endl;
      std::cout << "----------------------------------" << std::endl;
   }
   else if (selection == EXIT)
   {
      std::cout << "Goodbye" << std::endl;
      return EXIT_SUCCESS;
   }
   else
   {
      std::cout << "Sorry, that is not a valid option." << std::endl;
   }

   return EXIT_SUCCESS;
}
