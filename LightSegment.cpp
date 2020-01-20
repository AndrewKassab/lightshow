#include "LightSegment.hpp"

LightSegment::LightSegment(CRGB * leds, int startIndex, int endIndex){
  this->r = 0;
  this->g = 0;
  this->b = 0;
  this->leds = leds;
  this->startIndex = startIndex;
  this->endIndex = endIndex;
} 

void LightSegment::setToColor(int new_r, int new_g, int new_b){
  this->r = new_r; 
  this->g = new_g;
  this->b = new_b;
  for (int i = startIndex; i <= endIndex; i++){
    leds[i] = CRGB(r,g,b);
  }
}

void LightSegment::turnOff(){
  for (int i = startIndex; i <= endIndex; i++){
    leds[i] = CRGB(0,0,0);
  }
}

void LightSegment::traceOneColorFromBothEnds(int r, int g, int b, int thickness, int delayTime){
  for (int i = 0; i <= endIndex - startIndex - thickness + 1; i++){
    for (int j = 0; j < thickness; j++){
      leds[i+startIndex+j] = CRGB(r,g,b);
      leds[endIndex-i-j] = CRGB(r,g,b);
    }
    FastLED.show();
    leds[i+startIndex] = CRGB(0,0,0);
    leds[endIndex-i] = CRGB(0,0,0);
    delay(delayTime);
  }
  for (int i = 0; i <= thickness; i++){
    leds[endIndex-i] = CRGB(0,0,0);
  }
  for (int i = startIndex; i <= thickness; i++){
    leds[i] = CRGB(0,0,0);
  }
  FastLED.show();
}
