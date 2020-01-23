#include "LightShow.hpp"

void set_to_color(CRGB leds[], int startIndex, int endIndex, Color color){ 
  for (int i = startIndex; i <= endIndex; i++){
    leds[i] = CRGB( color.r, color.g, color.b);
  }
}

void set_one_to_color(CRGB leds[], int index, Color color){
  leds[index] = CRGB(color.r, color.g, color.b);
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

void light_all_corners(CRGB leds[], Color color){
  leds[left_top_left_corner] = CRGB(color.r,color.g,color.b);
  leds[left_top_right_corner] = CRGB(color.r,color.g,color.b);
  leds[left_bottom_left_corner] = CRGB(color.r,color.g,color.b);
  leds[left_bottom_right_corner] = CRGB(color.r,color.g,color.b);
  leds[middle_bottom_left_corner] = CRGB(color.r,color.g,color.b);
  leds[middle_bottom_right_corner] = CRGB(color.r,color.g,color.b);
  leds[middle_top_left_corner] = CRGB(color.r,color.g,color.b);
  leds[middle_top_middle] = CRGB(color.r,color.g,color.b);
  leds[middle_top_right_corner] = CRGB(color.r,color.g,color.b);
  leds[right_bottom_right_corner] = CRGB(color.r,color.g,color.b);
  leds[right_bottom_left_corner] = CRGB(color.r,color.g,color.b);
  leds[right_top_right_corner] = CRGB(color.r,color.g,color.b);
  leds[right_top_left_corner] = CRGB(color.r,color.g,color.b);
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

void turn_all_off(CRGB leds[]){
  for (int i = start; i <= end; i++){
    leds[i] = CRGB(0,0,0);
  }
}

void trace_outwards_evenly(CRGB leds[], int startIndex, int lengthOut, int thickness, int delayTime, Color color){ 
  for (int i = 0; i <= lengthOut-thickness; i++){
    for (int j = 0; j < thickness; j++){
      leds[startIndex+i+j] = CRGB(color.r,color.g,color.b);
      leds[startIndex-i-j] = CRGB(color.r,color.g,color.b);
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

// factory 
void get_left_square(CRGB* leds){
  return new LightSegment(leds, start, left_bottom_right_corner);
}
void get_left_square_left(CRGB* leds){
  return new LightSegment(leds, left_top_left_corner, left_bottom_left_corner);
}
void get_left_square_right(CRGB* leds){
  return new LightSegment(leds, start, left_top_right_corner-1);
}
void get_left_square_top(CRGB* leds){
  return new LightSegment(leds, left_top_right_corner, left_top_left_corner-1);
}
void get_left_square_bottom(CRGB* leds){
  return new LightSegment(leds, left_bottom_left_corner, left_bottom_right_corner);
}


void get_right_square(CRGB* leds){
  return new LightSegment(leds, right_bottom_left_corner, end);
}
void get_right_square_left(CRGB* leds){
  return new LightSegment(leds, right_top_left_corner, end);
}
void get_right_square_right(CRGB* leds){
  return new LightSegment(leds, right_bottom_right_corner, right_top_right_corner-1); 
}
void get_right_square_top(CRGB* leds){
  return new LightSegment(leds, right_top_right_corner, right_top_left_corner-1); 
}
void get_right_square_bottom(CRGB* leds){
  return new LightSegment(leds, right_bottom_left_corner, right_bottom_right_corner-1); 
}


void get_middle_arch(CRGB* leds){
  return new LightSegment(leds, middle_bottom_left_corner, middle_bottom_right_corner); 
}
void get_middle_top(CRGB* leds){
  return new LightSegment(leds, middle_top_left_corner, middle_top_right_corner); 
}
void get_middle_left(CRGB* leds){
  return new LightSegment(leds, middle_bottom_left_corner, middle_top_left_corner); 
}
void get_middle_right(CRGB* leds){
  return new LightSegment(leds, middle_top_right_corner, middle_bottom_right_corner); 
}
void get_middle_top_left(CRGB* leds){
  return new LightSegment(leds, middle_top_left_corner, middle_top_middle); 
}
void get_middle_top_right(CRGB* leds){
  return new LightSegment(leds, middle_top_middle, middle_top_right_corner); 
}
  

void get_left_bridge(CRGB* leds){
  return new LightSegment(leds, left_bottom_right_corner, middle_bottom_left_corner);
}
void get_right_bridge(CRGB* leds){
  return new LightSegment(leds, middle_bottom_right_corner, right_bottom_left_corner);  
}
void get_left_bridge_no_slant(CRGB* leds){
  return new LightSegment(leds, left_bottom_left_corner+1, middle_bottom_left_corner-5);
}
void get_right_bridge_no_slant(CRGB* leds){
  return new LightSegment(leds, middle_bottom_right_corner+5, right_bottom_left_corner-1);
}


void get_all_lights(CRGB* leds){
  return new LightSegment(leds, start, end); 
}

void get_start_left_bridge_to_middle_top_left(CRGB* leds){
  return new LightSegment(leds, left_bottom_right_corner, middle_top_left_corner);
}
void get_middle_top_right_to_right_bridge_end(CRGB* leds){
  return new LightSegment(leds, middle_top_right_corner, right_bottom_left_corner);
}

void get_left_square_left_center_with_offset(CRGB* leds, int offset){
  return new LightSegment(leds, left_top_left_corner + offset, left_bottom_left_corner - offset);
}
void get_left_square_top_center_with_offset(CRGB* leds, int offset){
  return new LightSegment(leds, left_top_right_corner + offset, left_top_left_corner - offset); 
}
void get_left_square_right_center_with_offset(CRGB* leds, int offset){
  return new LightSegment(leds, start + offset, left_top_right_corner - offset); 
}
void get_left_square_bottom_center_with_offset(CRGB* leds, int offset){
  return new LightSegment(leds, left_bottom_left_corner+offset, left_bottom_right_corner-offset); 
}

void get_right_square_left_center_with_offset(CRGB* leds, int offset){
  return new LightSegment(leds, right_top_left_corner + offset, end - offset);
}
void get_right_square_top_center_with_offset(CRGB* leds, int offset){
  return new LightSegment(leds, right_top_right_corner + offset, right_top_left_corner - offset);
}
void get_right_square_right_center_with_offset(CRGB* leds, int offset){
  return new LightSegment(leds, right_bottom_right_corner + offset, right_top_right_corner - offset);
}
void get_right_square_bottom_center_with_offset(CRGB* leds, int offset){
  return new LightSegment(leds, right_bottom_left_corner + offset, right_bottom_right_corner - offset);
}

void get_middle_left_center_with_offset(CRGB* leds, int offset){
  return new LightSegment(leds, middle_bottom_left_corner + offset, middle_top_left_corner - offset);
}
void get_middle_right_center_with_offset(CRGB* leds, int offset){
  return new LightSegment(leds, middle_top_right_corner + offset, middle_bottom_right_corner - offset); 
}

void get_middle_top_center_with_offset(CRGB* leds, int offset){
  return new LightSegment(leds, middle_top_left_corner + offset, middle_top_right_corner - offset); 
}
void get_middle_top_left_center_with_offset(CRGB* leds, int offset){
  return new LightSegment(leds, middle_top_left_corner + offset, middle_top_middle - offset); 
}
void get_middle_top_right_center_with_offset(CRGB* leds, int offset){
  return new LightSegment(leds, middle_top_middle + offset, middle_top_right_corner - offset); 
}