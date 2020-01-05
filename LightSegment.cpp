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