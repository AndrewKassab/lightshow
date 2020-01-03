#include "LightShow.h"

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

void default_setup(CRGB leds[]){
  FastLED.addLeds<WS2812, 2, GRB>(leds, 262);
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

void set_left_square_left(CRGB leds[], int r, int g, int b){
  set_to_color(leds, left_top_left_corner, left_bottom_left_corner-1, r, b, b);
}

void set_left_square_right(CRGB leds[], int r, int g, int b){
  set_to_color(leds, start, left_top_right_corner-1, r, b, b);
  set_to_color(leds, left_bottom_right_corner, left_bottom_right_corner, r, b, b);
}

void set_left_square_bottom(CRGB leds[], int r, int g , int b){
  set_to_color(leds, left_bottom_left_corner, left_bottom_right_corner, r, g, b);
}

void set_left_square_top(CRGB leds[], int r, int g , int b){
  set_to_color(leds, left_top_right_corner, left_top_left_corner-1, r, g, b);
}

void set_middle_left(CRGB leds[], int r, int g, int b){
  set_to_color(leds, middle_bottom_left_corner, middle_top_left_corner, r, g, b);
}

void set_middle_top_left(CRGB leds[], int r, int g, int b){
  set_to_color(leds, middle_top_left_corner, middle_top_middle, r, g, b);
}

void set_middle_top_right(CRGB leds[], int r, int g, int b){
  set_to_color(leds, middle_top_middle, middle_top_right_corner, r, g, b);
}

void set_middle_middle(CRGB leds[], int r, int g, int b){
  set_to_color(leds, middle_top_left_corner, middle_top_right_corner, r, g, b);
}

void set_middle_right(CRGB leds[], int r, int g, int b){
  set_to_color(leds, middle_top_right_corner, middle_bottom_right_corner, r, g, b);
}

void set_right_square_left(CRGB leds[], int r, int g, int b){
  set_to_color(leds, right_top_left_corner, end, r, g, b);
  set_one_to_color(leds, right_bottom_left_corner, r, g, b);
}

void set_right_square_top(CRGB leds[], int r, int g, int b){
  set_to_color(leds, right_top_right_corner, right_top_left_corner-1, r, g, b);
}

void set_right_square_right(CRGB leds[], int r, int g, int b){
  set_to_color(leds, right_bottom_right_corner, right_top_right_corner-1, r, g, b);
}

void set_right_square_bottom(CRGB leds[], int r, int g, int b){
  set_to_color(leds, right_bottom_left_corner, right_bottom_right_corner-1, r, g, b);
}

void set_right_bridge(CRGB leds[], int r, int g, int b){
  set_to_color(leds, middle_bottom_right_corner, right_bottom_left_corner, r, g, b);
}

void set_left_bridge(CRGB leds[], int r, int g, int b){
  set_to_color(leds, left_bottom_right_corner, middle_bottom_left_corner, r, g, b);
}