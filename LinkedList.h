
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

class LinkedList
{
public:
   LinkedList();
   ~LinkedList();

   // Return the current size of the Linked List.
   int size();

   // Get the value at the given index.
   Tile *get(int index);

   // Add the value to the back of the Linked List
   void add(Tile *newTile);

   // Remove the value at the back of the Linked List
   void remove(Tile* key);

   // Removes all values from the Linked List
   void clear();

private:
   Node *head;
};

#endif // ASSIGN2_LINKEDLIST_H
