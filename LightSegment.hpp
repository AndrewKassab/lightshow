#ifndef LIGHTSEGMENT 
#define LIGHTSEGMENT 

#include <FastLED.h>

class LightSegment{
  public: 
    LightSegment(CRGB * leds, int startIndex, int endIndex);
    int startIndex;
    int endIndex;
    int r;
    int g; 
    int b;
    void setToColor(int r, int g, int b);
    void turnOff();
    void traceOneColorFromBothEnds(int r, int g, int b, int thickness, int delayTime);
    CRGB * leds;
};

#endif