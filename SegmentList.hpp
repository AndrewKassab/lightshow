#ifndef LIST
#define LIST 

#include "SegmentNode.hpp"
#include "LightSegment.hpp"

class SegmentList{
  private:
    int size; // number of segments in list
    SegmentNode * head;
  public:
    SegmentList(LightSegment * head);
    ~SegmentList();
    void add(LightSegment * newSegment);

    // sets all segments in list to color
    void setAllToColor(CRGB color);

    void turnAllOff();
    
    // returns length of the longest lightsegment in the list
    int getLongestSegmentSize();

    // lights fade up towards their rgb values 
    void fadeAllIn(int delayTime, CRGB color);

    // lights fade down from their rgb value until they're off 
    void fadeAllDown(int delayTime);

    /* lights perform a trace and remain on as they trace, reverse array indicates 
     * if a specific segment at that index should trace in reverse
     */
    void traceAllAndRemain(int thickness, int delayTime, boolean * reverse, CRGB color);

    /* lights perform a trace and turn off as they trace, reverse array indicates 
     * if a specific segment at that index should trace in reverse
     */
    void traceAllDontRemain(int thickness, int delayTime, boolean * reverse, CRGB color);

    /* lights perform a trace and turn off as they trace, but the last few stay
     * on, reverse array indicates if a specific segment at that index should 
     * trace in reverse
     */
    void traceAllKeepEnd(int thickness, int delayTime, boolean * reverse, CRGB color);

    /* Strobe effect
     * delayTime - delay between strobes
     * numTimes - amount of times to strobe
     */
    void strobe(int delayTime, int numTimes, CRGB color);

};

#endif
