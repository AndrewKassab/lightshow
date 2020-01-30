#ifndef LIST
#define LIST 

#include "SegmentNode.hpp"
#include "LightShow.hpp"

class SegmentList{
  public:
    SegmentNode * head;
    int size;
    SegmentList(LightSegment * head);
    ~SegmentList();
    void add(LightSegment * newSegment);
    void setAllToColor(CRGB color);
    void turnAllOff();

    // lights fade in towards their rgb values 
    void fadeAllIn(int delayTime);

    // lights fade down from their rgb until they're off 
    void fadeAllDown(int delayTime);

    // lights perform a trace, reverse arrayindicates if a specific segment should trace in reverse
    void traceAllAndRemain(int thickness, int delayTime, boolean * reverse, CRGB color);
};

#endif