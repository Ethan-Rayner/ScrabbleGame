
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

Tile *LinkedList::get(Node *head_ref, int index)
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

void LinkedList::add(Node *head_ref, Tile *newTile)
{
   Node *new_node = new Node(newTile, head_ref);
   new_node->tile = newTile;
   new_node->next = (head_ref);

   (head_ref) = new_node;
}

void LinkedList::remove(Node *head_ref, Tile* key)
{
   Node *temp = head_ref;
   Node *prev = NULL;

   if (temp != NULL && temp->tile == key)
   {
      head_ref = temp->next;
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

void LinkedList::clear(Node *head_ref)
{
   Node *current = head_ref;
   Node *next = NULL;

   while (current != NULL)
   {
      next = current->next;
      free(current);
      current = next;
   }
   head_ref = NULL;
}