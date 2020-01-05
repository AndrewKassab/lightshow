#ifndef LIGHTSEGMENT 
#define LIGHTSEGMENT 

#include "LightShow.hpp"

class LightSegment{
  public: 
    LightSegment(CRGB leds[], int startIndex, int endIndex);
    CRGB leds;
    int startIndex;
    int endIndex;
    int r;
    int g; 
    int b;
    void setToColor(int r, int g, int b);
    void turnOff();
};

#endif