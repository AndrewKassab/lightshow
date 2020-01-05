#include "LightSegment.hpp"

LightSegment::LightSegment(CRGB leds, int startIndex, int endIndex){
  this->r = 0;
  this->g = 0;
  this->b = 0;
  this->leds = leds;
  this->startIndex = startIndex;
  this->endIndex = endIndex;
} 

void LightSegment::setToColor(int r, int g, int b){
  set_to_color(leds, startIndex, endIndex, r, g, b);
}

void LightSegment::turnOff(){
  turn_off(leds, startIndex, endIndex);
}