#ifndef LIGHTSEGMENT 
#define LIGHTSEGMENT 

#include <FastLED.h>

class LightSegment{
  public: 
    LightSegment(CRGB * leds, int startIndex, int endIndex);
    LightSegment * next;
    int startIndex;
    int endIndex;
    int r;
    int g; 
    int b;
    void setToColor(CRGB color);
    // sets the leds to rgb value without changing state variables
    void setToColorNoUpdate(CRGB color);
    // sets just the inner variables but not the leds
    void setColorFieldsOnly(CRGB color);
    void turnOff();
    void traceOneColorFromBothEnds(int thickness, int delayTime);
    CRGB * leds;
};

#endif