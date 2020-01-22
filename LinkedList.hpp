#ifndef LIST
#define LIST 

#include "Node.hpp"
#include "LightShow.hpp"

class LinkedList{
  public:
    Node * head;
    LinkedList(LightSegment * head);
    void add(LightSegment * newSegment);
    void setAllToColor(int r, int g, int b);
    void turnAllOff();
    void fadeAllIn(int delayTime);
};

#endif