#include "LightSegment.hpp"

LightSegment::LightSegment(CRGB * all_leds, int startIndex, int endIndex){
  this->leds = &all_leds[startIndex];
  this->size = endIndex - startIndex;
} 

void LightSegment::setToColor(CRGB color){
  for (int i = 0; i <= size; i++){
    leds[i] = color;
  }
}

void LightSegment::turnOff(){
  for (int i = 0; i <= size; i++){
    leds[i] = CRGB::Black;
  }
}

void LightSegment::traceOneColorFromBothEnds(int thickness, int delayTime, CRGB color){
  for (int i = 0; i <= size - thickness + 1; i++){
    for (int j = 0; j < thickness; j++){
      leds[i+j] = color;
      leds[size-i-j] = color;
    }
    FastLED.show();
    leds[i] = CRGB::Black;
    leds[size-i] = CRGB::Black;
    delay(delayTime);
  }
  for (int i = 0; i <= thickness; i++){
    leds[size-i] = CRGB::Black;
  }
  for (int i = 0; i <= thickness; i++){
    leds[i] = CRGB::Black;
  }
  FastLED.show();
}

void LightSegment::fadeToBlack(int delayTime){
  int r_factor = this->leds[0].r / 70;
  int g_factor = this->leds[0].g / 70;
  int b_factor = this->leds[0].b / 70;
  for (int i = 0; i <= 70; i++){
    for ( int j = 0; j <= size; j++){
      if (leds[j].r > 0){
        leds[j].r -= r_factor;
      }
      if (leds[j].g > 0){
        leds[j].g -= g_factor;
      }
      if (leds[j].b > 0){
        leds[j].b -= b_factor;
      }
    }
    FastLED.show();
    delay(delayTime);
  }  
  turnOff();
}
