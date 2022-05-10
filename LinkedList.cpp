
#include <iostream>
#include "LinkedList.h"
#include <assert.h>
#include "Node.h"
//#include <bits/stdc++.h>


LinkedList::LinkedList()
{
   head = nullptr;
}
//No idea if this will work, maybe someone take a look just to make sure
LinkedList::~LinkedList()
{
   Node *current = head;
   current = head;

   while(current != nullptr)
   {
      current = current->next;
      delete head;
      head = current;
   }
}

int LinkedList::size()
{
   int count = 0;
   Node *current = head;

   while (current != NULL)
   {
      count++;
      current = current->next;
   }
   return count;
}

Tile *LinkedList::get(int index)
{
   Node *current = head;

   int count = 0;
   while (current != NULL)
   {
      if (count == index)
         return (current->tile);
      count++;
      current = current->next;
   }

   assert(0);
}

void LinkedList::add(Tile *newTile)
{
   Node *new_node = new Node(newTile, head);
   new_node->tile = newTile;
   new_node->next = (head);

   (head) = new_node;
}


void LinkedList::remove(Tile* key)
{
   Node *temp = head;
   Node *prev = NULL;

   if (temp != NULL && temp->tile == key)
   {
      head = temp->next;
      delete temp;
      return;
   }
   else
   {
      while (temp != NULL && temp->tile != key)
      {
         prev = temp;
         temp = temp->next;
      }

      if (temp == NULL)
      {
         return;
      }
      prev->next = temp->next;
      delete temp;
   }
}

void LinkedList::clear()
{
   Node *current = head;
   Node *next = NULL;

   while (current != NULL)
   {
      next = current->next;
      free(current);
      current = next;
   }
   head = NULL;
}


// Reading from file and add it to linkedlist
// void LinkedList::addTile(Node* head)
// {
//    ifstream file;
//    string buf;
//    file.open("scrabbletiles.txt", ios::in | ios::binary);
//    // checking if file is open
//    if (file.is_open())
//    {
//       cout << "The file is opened fail" << endl;
//       while (getline(file, buf))
//       {
//          istringstream iss(buf);
//          char letter;
//          int value;
//          iss >> letter >> value;
//          // Code for testing if values are printed out correctly
//          // cout << "Letter: " << letter << " Value: " << value << endl;

//          LinkedList* tilebag = new LinkedList();
//          head = NULL;
//          for (int i = 0; i < 98; i++)
//          {
//             Tile* tile = new Tile(letter, value);
//              //head = new Node (letter, value);
//             tilebag->add(tile);
//          }
//       }
//       while (!file.eof())
//       {
//       }

//       file.close();
//    }
// }