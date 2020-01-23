#ifndef LIGHTSEGMENT 
#define LIGHTSEGMENT 

#include <FastLED.h>
#include "color.h"

class LightSegment{
  public: 
    LightSegment(CRGB * leds, int startIndex, int endIndex);
    LightSegment * next;
    int startIndex;
    int endIndex;
    int r;
    int g; 
    int b;
    void setToColor(Color theColor);
    // sets the leds to rgb value without changing state variables
    void setToColorNoUpdate(Color theColor);
    // sets just the inner variables but not the leds
    void setColorFieldsOnly(Color color);
    void turnOff();
    void traceOneColorFromBothEnds(int thickness, int delayTime);
    CRGB * leds;
};

#endif