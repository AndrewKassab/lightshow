#ifndef LIST
#define LIST 

#include "Node.hpp"
#include "LightShow.hpp"

class LinkedList{
  public:
    Node * head;
    int size;
    LinkedList(LightSegment * head);
    ~LinkedList();
    void add(LightSegment * newSegment);
    void setAllToColor(Color color);
    void turnAllOff();

    // lights fade in towards their rgb values 
    void fadeAllIn(int delayTime);

    // lights fade down from their rgb until they're off 
    void fadeAllDown(int delayTime);

    // lights perform a trace, reverse arrayindicates if a specific segment should trace in reverse
    void traceAll(int thickness, int delayTime, boolean * reverse);
};

#endif