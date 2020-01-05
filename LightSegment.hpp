#include "LightShow.h"

class LightSegment{
  public: 
    LightSegment(int startIndex, int endIndex);
    CRGB leds;
    int startIndex;
    int endIndex;
    int r;
    int g; 
    int b;
    void setToColor(int r, int g, int b);
    void turnOff();
}