
#include "Node.h"
//Constructor
Node::Node(Tile* tile, Node* next)
{
   this->next = next;
   this->tile = tile;
}

Node::Node(Node& other)
{
}
