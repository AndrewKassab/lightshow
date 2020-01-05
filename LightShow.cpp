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
  leftSquare = new LightSegment(leds, start, left_bottom_right_corner);
  leftSquareLeft = new LightSegment(leds, left_top_left_corner, left_bottom_left_corner);
  leftSquareTop = new LightSegment(leds, left_top_right_corner, left_top_left_corner-1);
  leftSquareRight = new LightSegment(leds), start, left_top_right_corner-1;
  leftSquareBottom = new LightSegment(leds, left_bottom_left_corner, left_bottom_right_corner);
  rightSquare = new LightSegment(leds, right_bottom_left_corner, end);
  rightSquareTop = new LightSegment(leds, right_top_right_corner, right_top_left_corner-1);
  rightSquareRight = new LightSegment(leds, right_bottom_right_corner, right_top_right_corner-1);
  rightSquareLeft = new LightSegment(leds, right_top_left_corner, end);
  rightSquareBottom = new LightSegment(leds, right_bottom_left_corner, right_bottom_right_corner-1);
  middleArch = new LightSegment(leds, middle_bottom_left_corner, middle_bottom_right_corner);
  middleTop; = new LightSegment(leds, middle_top_left_corner, middle_top_right_corner);
  middleLeft = new LightSegment(leds, middle_bottom_left_corner, middle_top_left_corner);
  middleRight = new LightSegment(leds, middle_top_right_corner, middle_bottom_right_corner);
  middleTopLeft = new LightSegment(leds, middle_top_left_corner, middle_top_middle);
  middleTopRight = new LightSegment(leds, middle_top_middle, middle_top_right_corner);
  rightBridge = new LightSegment(leds, middle_bottom_right_corner, right_bottom_left_corner);
  leftBridge = new LightSegment(leds, left_bottom_right_corner, middle_bottom_left_corner);
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