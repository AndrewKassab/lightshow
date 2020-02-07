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
  for (int i = 255; i >= 210; i--){
    for (int j = 0; j <= this->size; j++){
      this->leds[j].nscale8(i);
    }
    FastLED.show();
    delay(delayTime);
  }
}

void LightSegment::fadeUp(int delayTime, CRGB color){
  for (int i = 0; i<= 255; i++){
    for (int j = 0; j <= this->size; j++){
      this->leds[j] = color;
      this->leds[j].maximizeBrightness(i);
    }
    FastLED.show();
    delay(delayTime);
  }
}
