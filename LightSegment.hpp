#ifndef LIGHTSEGMENT 
#define LIGHTSEGMENT 

#include <FastLED.h>

class LightSegment{
  public: 
    LightSegment(CRGB * all_leds, int startIndex, int endIndex);
    int size;
    CRGB * leds;
    void setToColor(CRGB color);
    void turnOff();
    void traceOneColorFromBothEnds(int thickness, int delayTime, CRGB color);
    void fadeToBlack(int delayTime);
    void fadeUp(int delayTime, CRGB color);
};

#endif
