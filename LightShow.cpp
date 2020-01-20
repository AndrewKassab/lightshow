#include "LightShow.hpp"

void set_to_color(CRGB leds[], int startIndex, int endIndex, int r, int g, int b){
  for (int i = startIndex; i <= endIndex; i++){
    leds[i] = CRGB(r,g,b);
  }
}

void set_one_to_color(CRGB leds[], int index, int r, int g, int b){
  leds[index] = CRGB(r,g,b);
}

void turn_off(CRGB leds[], int startIndex, int endIndex){
  for (int i = startIndex; i <= endIndex; i++){
    leds[i] = CRGB(0,0,0);
  }
}

void turn_one_off(CRGB leds[], int index){
  leds[index] = CRGB(0,0,0);
}

void default_setup(CRGB leds[]){
  FastLED.addLeds<WS2812, 2, GRB>(leds, 262);
}

void countdown(CRGB leds[]){
  set_to_color(leds, middle_top_middle - 2, middle_top_middle+2, 255, 255, 255);
  FastLED.show();

  for (int i = 0; i <= 4; i++){
    delay(1000);
    turn_one_off(leds, middle_top_middle - 2 + i);
    FastLED.show();
  }
}

void light_all_corners(CRGB leds[], int r, int g, int b){
  leds[left_top_left_corner] = CRGB(r,g,b);
  leds[left_top_right_corner] = CRGB(r,g,b);
  leds[left_bottom_left_corner] = CRGB(r,g,b);
  leds[left_bottom_right_corner] = CRGB(r,g,b);
  leds[middle_bottom_left_corner] = CRGB(r,g,b);
  leds[middle_bottom_right_corner] = CRGB(r,g,b);
  leds[middle_top_left_corner] = CRGB(r,g,b);
  leds[middle_top_middle] = CRGB(r,g,b);
  leds[middle_top_right_corner] = CRGB(r,g,b);
  leds[right_bottom_right_corner] = CRGB(r,g,b);
  leds[right_bottom_left_corner] = CRGB(r,g,b);
  leds[right_top_right_corner] = CRGB(r,g,b);
  leds[right_top_left_corner] = CRGB(r,g,b);
}

void turn_off_all_corners(CRGB leds[]){ 
  leds[left_top_left_corner] = CRGB(0,0,0);
  leds[left_top_right_corner] = CRGB(0,0,0);
  leds[left_bottom_left_corner] = CRGB(0,0,0);
  leds[left_bottom_right_corner] = CRGB(0,0,0);
  leds[middle_bottom_left_corner] = CRGB(0,0,0);
  leds[middle_bottom_right_corner] = CRGB(0,0,0);
  leds[middle_top_left_corner] = CRGB(0,0,0);
  leds[middle_top_middle] = CRGB(0,0,0);
  leds[middle_top_right_corner] = CRGB(0,0,0);
  leds[right_bottom_right_corner] = CRGB(0,0,0);
  leds[right_bottom_left_corner] = CRGB(0,0,0);
  leds[right_top_right_corner] = CRGB(0,0,0);
  leds[right_top_left_corner] = CRGB(0,0,0);
}

void single_trace(CRGB leds[], int startIndex, int endIndex, int thickness, int delayTime, int r, int g, int b){
  // trace
  for (int i = startIndex; i <= endIndex - thickness + 1; i++){
    for (int j = 0; j < thickness; j++){
      leds[i+j] = CRGB(r,g,b); 
    }
    FastLED.show();
    leds[i] = CRGB(0,0,0);
    delay(delayTime);
  }
  // make sure last few turn off
  for (int i = 0; i <= thickness; i++){
    leds[endIndex-i] = CRGB(0,0,0);
  }
  FastLED.show();
}

void turn_all_off(CRGB leds[]){
  for (int i = start; i <= end; i++){
    leds[i] = CRGB(0,0,0);
  }
}

void trace_outwards_evenly(CRGB leds[], int startIndex, int lengthOut, int thickness, int delayTime, int r, int g, int b){
  for (int i = 0; i <= lengthOut-thickness; i++){
    for (int j = 0; j < thickness; j++){
      leds[startIndex+i+j] = CRGB(r,g,b);
      leds[startIndex-i-j] = CRGB(r,g,b);
    }
    FastLED.show();
    leds[startIndex+i] = CRGB(0,0,0);
    leds[startIndex-i] = CRGB(0,0,0);
    delay(delayTime);
  }
  for (int i = thickness; i >= 0; i--){
    leds[startIndex+lengthOut-i] = CRGB(0,0,0);
    leds[startIndex-lengthOut+i] = CRGB(0,0,0);
    FastLED.show();
    delay(delayTime);
  }
}

