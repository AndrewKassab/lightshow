#include "sequences.hpp"

/* Square and center trace */
void sequence_one(CRGB* leds, int delayTime, int thickness, Color colorOne, Color colorTwo){

  for (int i = 0; i <= 79; i++){

      if ( i == 1 ){
        turn_one_off(leds, 76);
        turn_one_off(leds, 185);
      } else if ( i == 2 ){
        turn_one_off(leds,77);
        turn_one_off(leds, 184);
      } else if ( i == 3 ) {
        turn_one_off(leds,78);
        turn_one_off(leds, 183);
      } else if ( i == 4 ) {
        turn_one_off(leds,79);
        turn_one_off(leds, 182);
      }

      delay(delayTime);

      // left square
      set_one_to_color(leds, start+i, colorOne);
      turn_one_off(leds, start+i-thickness);

      // right square
      set_one_to_color(leds, end-i, colorOne);
      turn_one_off(leds, end-i+thickness);

      // middle 
      if ( i != 42){
        turn_one_off(leds, middle_bottom_left_corner+i-thickness);
        turn_one_off(leds, middle_bottom_right_corner-i+thickness);
      }
      if ( i == 79 ){
        turn_one_off(leds, middle_bottom_left_corner+2);
        turn_one_off(leds, middle_bottom_right_corner-2);
      } else {
        set_one_to_color(leds, middle_bottom_left_corner+i, colorTwo);
        set_one_to_color(leds, middle_bottom_right_corner-i, colorTwo);
      }
      
      // corners
      light_all_corners(leds, Color {100,100,100});        
      
      FastLED.show();
  }
}

/* Square Cycle */
void sequence_two(CRGB* leds, int delayTime, Color colorOne, Color colorTwo){
  LightSegment * leftSquareLeftInSeq = get_left_square_left(leds);
  LightSegment * leftSquareTopInSeq = get_left_square_top(leds);
  LightSegment * leftSquareRightInSeq = get_left_square_right(leds);
  LightSegment * leftSquareBottomInSeq = get_left_square_bottom(leds);
  LightSegment * rightSquareTopInSeq = get_right_square_top(leds);
  LightSegment * rightSquareRightInSeq = get_right_square_right(leds);
  LightSegment * rightSquareLeftInSeq = get_right_square_left(leds);
  LightSegment * rightSquareBottomInSeq = get_right_square_bottom(leds);

  turn_all_off(leds);
  leftSquareLeftInSeq->setToColor(colorOne);
  rightSquareRightInSeq->setToColor(colorOne);
  FastLED.show();
  delay(delayTime);
  leftSquareLeftInSeq->turnOff();
  rightSquareRightInSeq->turnOff();
  leftSquareTopInSeq->setToColor(colorTwo);
  rightSquareTopInSeq->setToColor(colorTwo);
  FastLED.show();
  delay(delayTime);
  leftSquareTopInSeq->turnOff();
  rightSquareTopInSeq->turnOff();
  leftSquareRightInSeq->setToColor(colorOne);
  rightSquareLeftInSeq->setToColor(colorOne);
  FastLED.show();
  delay(delayTime);
  leftSquareRightInSeq->turnOff();
  rightSquareLeftInSeq->turnOff();
  leftSquareBottomInSeq->setToColor(colorTwo);
  rightSquareBottomInSeq->setToColor(colorTwo);
  FastLED.show();
  delay(delayTime);


  free(leftSquareLeftInSeq);
  free(leftSquareTopInSeq);
  free(leftSquareRightInSeq);
  free(leftSquareBottomInSeq);
  free(rightSquareTopInSeq);
  free(rightSquareRightInSeq);
  free(rightSquareLeftInSeq);
  free(rightSquareBottomInSeq);
}