#include "LightSegment.hpp"

LightSegment::LightSegment(CRGB * leds, int startIndex, int endIndex){
  this->r = 0;
  this->g = 0;
  this->b = 0;
  this->leds = leds;
  this->startIndex = startIndex;
  this->endIndex = endIndex;
  this->next = NULL;
} 

void LightSegment::setToColor(Color theColor){
  this->r = theColor.r;
  this->g = theColor.g;
  this->b = theColor.b;
  for (int i = startIndex; i <= endIndex; i++){
    leds[i] = CRGB(theColor.r,theColor.g,theColor.b);
  }
}

void LightSegment::setToColorNoUpdate(Color theColor){
  for (int i = startIndex; i <= endIndex; i++){
    leds[i] = CRGB(theColor.r,theColor.g,theColor.b);
  }
}

void LightSegment::setColorFieldsOnly(Color color){
  this->r = color.r;
  this->g = color.g;
  this->b = color.b;
}

void LightSegment::turnOff(){
  for (int i = startIndex; i <= endIndex; i++){
    leds[i] = CRGB(0,0,0);
  }
}

void LightSegment::traceOneColorFromBothEnds(int thickness, int delayTime){
  for (int i = 0; i <= endIndex - startIndex - thickness + 1; i++){
    for (int j = 0; j < thickness; j++){
      leds[i+startIndex+j] = CRGB(this->r,this->g,this->b);
      leds[endIndex-i-j] = CRGB(this->r,this->g,this->b);
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
