#ifndef LIST
#define LIST 

#include "Node.hpp"

class LinkedList{
  public:
    Node * head;
    LinkedList(LightSegment * head);
    void add(LightSegment * newSegment);
};

#endif