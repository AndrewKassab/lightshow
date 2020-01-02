#include "LightShow.h"

void set_to_color(int startIndex, int endIndex, int r, int g, int b){
  for (int i = startIndex; i <= endIndex, i++){
    leds[i] = CRGB(r,g,b);
  }
}

void turn_off(int startIndex, int endIndex){
  for (int i = startINdex, i <= endIndex, i++){
    leds[i] = CRGB(0,0,0);
  }
}