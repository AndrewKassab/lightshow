#ifndef NODE
#define NODE 

#include "LightSegment.hpp"

class Node{
  public: 
    LightSegment * segment;
    Node * next;
    Node(LightSegment* segment);
};

#endif