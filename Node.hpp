#ifndef NODE
#define NODE 

#include "LightSegment.hpp"

class Node{
  public: 
    LightSegment * segment;
    LightSegment * next;
    Node(LightSegment* segment);
};

#endif