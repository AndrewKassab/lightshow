#include "sequences.hpp"

/* Square and center trace */
void sequence_one(CRGB* leds, int delayTime, int thickness, CRGB colorOne, CRGB colorTwo){

  for (int i = 0; i <= 79; i++){

      if ( i == 1 ){
        leds[76] = CRGB::Black;
        leds[185] = CRGB::Black;
      } else if ( i == 2 ){
        leds[77] = CRGB::Black;
        leds[184] = CRGB::Black;
      } else if ( i == 3 ) {
        leds[78] = CRGB::Black;
        leds[183] = CRGB::Black;
      } else if ( i == 4 ) {
        leds[79] = CRGB::Black;
        leds[182] = CRGB::Black;
      }

      delay(delayTime);

      // left square
      leds[start+i] = colorOne;
      leds[start+i-thickness] = CRGB::Black;

      // right square
      leds[end-i] = colorOne;
      leds[end-i+thickness] = CRGB::Black;

      // middle 
      if ( i != 42){
        leds[middle_bottom_left_corner+i-thickness] = CRGB::Black;
        leds[middle_bottom_right_corner-i+thickness] = CRGB::Black;
      }
      if ( i == 79 ){
        leds[middle_bottom_left_corner+2] = CRGB::Black;
        leds[middle_bottom_right_corner-2] = CRGB::Black;
      } else {
        leds[middle_bottom_left_corner+i] = colorTwo;
        leds[middle_bottom_right_corner-i] = colorTwo;
      }
      
      // corners
      light_all_corners(leds, CRGB::White);        
      
      FastLED.show();
  } 
}

/* Square Cycle */
void square_side_cycle(CRGB* leds, int delayTime, CRGB colorOne, CRGB colorTwo, CRGB colorThree, CRGB colorFour){
  LightSegment * leftSquareLeftInSeq = get_left_square_left(leds);
  LightSegment * leftSquareTopInSeq = get_left_square_top(leds);
  LightSegment * leftSquareRightInSeq = get_left_square_right(leds);
  LightSegment * leftSquareBottomInSeq = get_left_square_bottom(leds);
  LightSegment * rightSquareTopInSeq = get_right_square_top(leds);
  LightSegment * rightSquareRightInSeq = get_right_square_right(leds);
  LightSegment * rightSquareLeftInSeq = get_right_square_left(leds);
  LightSegment * rightSquareBottomInSeq = get_right_square_bottom(leds);

  FastLED.clear();
  leds[middle_top_left_corner] = CRGB::White;
  leds[middle_top_right_corner] = CRGB::White;
  leds[middle_bottom_left_corner] = CRGB::White;
  leds[middle_bottom_right_corner] = CRGB::White;
  leds[middle_top_middle] = CRGB::White;
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
  leftSquareRightInSeq->setToColor(colorThree);
  rightSquareLeftInSeq->setToColor(colorThree);
  FastLED.show();
  delay(delayTime);
  leftSquareRightInSeq->turnOff();
  rightSquareLeftInSeq->turnOff();
  leftSquareBottomInSeq->setToColor(colorFour);
  rightSquareBottomInSeq->setToColor(colorFour);
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

void square_color_trace(CRGB * leds, int thickness, int delayTime, CRGB * colors, int numColors){
  leds[middle_top_left_corner] = CRGB::White;
  leds[middle_top_right_corner] = CRGB::White;
  leds[middle_bottom_left_corner] = CRGB::White;
  leds[middle_bottom_right_corner] = CRGB::White;
  leds[middle_top_middle] = CRGB::White;
  LightSegment * leftSquare = get_left_square(leds);
  LightSegment * rightSquare = get_right_square(leds);
  SegmentList squares = SegmentList(leftSquare);
  squares.add(rightSquare);
  boolean reverseTable[2] = {true, false};
  for ( int i = 0; i < numColors; i++ ){
    squares.traceAllAndRemain(thickness,delayTime,reverseTable, colors[i]);
  }
  free(leftSquare);
  free(rightSquare);
}

void up_down_trace(CRGB * leds, int thickness, int delayTime, CRGB colorOne, CRGB colorTwo){
  LightSegment * leftSquareLeft = get_left_square_left(leds);
  LightSegment * leftSquareRight = get_left_square_right(leds);
  LightSegment * rightSquareLeft = get_right_square_left(leds);
  LightSegment * rightSquareRight = get_right_square_right(leds);
  LightSegment * middleLeft = get_middle_left(leds);
  LightSegment * middleRight = get_middle_right(leds);
  SegmentList lights = SegmentList(leftSquareLeft);
  lights.add(leftSquareRight);
  lights.add(rightSquareLeft);
  lights.add(rightSquareRight);
  lights.add(middleLeft);
  lights.add(middleRight);
  boolean reverseTable[6] = {true, false, true, false, true, false};
  lights.traceAllDontRemain(thickness, delayTime,reverseTable, colorOne);
  reverseTable[0] = false;
  reverseTable[2] = false;
  reverseTable[4] = false;
  reverseTable[1] = true;
  reverseTable[3] = true;
  reverseTable[5] = true;
  lights.traceAllDontRemain(thickness, delayTime,reverseTable, colorTwo);
  free(leftSquareLeft);
  free(leftSquareRight);
  free(rightSquareLeft);
  free(rightSquareRight);
  free(middleLeft);
  free(middleRight);

}

void left_right_trace(CRGB * leds, int thickness, int delayTime, CRGB colorOne, CRGB colorTwo){
  LightSegment * leftSquareTop = get_left_square_top(leds);
  LightSegment * leftSquareBottom = get_left_square_bottom(leds);
  LightSegment * rightSquareTop = get_right_square_top(leds);
  LightSegment * rightSquareBottom = get_right_square_bottom(leds);
  LightSegment * middleTopLeft = get_middle_top_left(leds);
  LightSegment * middleTopRight = get_middle_top_right(leds);
  SegmentList lights = SegmentList(leftSquareTop);
  lights.add(leftSquareBottom);
  lights.add(rightSquareTop);
  lights.add(rightSquareBottom);
  lights.add(middleTopLeft);
  lights.add(middleTopRight);
  boolean reverseTable[6] = {true, true, false, false, true, false};
  lights.traceAllDontRemain(thickness, delayTime,reverseTable, colorOne);
  reverseTable[0] = false;
  reverseTable[2] = true;
  reverseTable[4] = false;
  reverseTable[1] = false;
  reverseTable[3] = true;
  reverseTable[5] = true;
  lights.traceAllDontRemain(thickness, delayTime,reverseTable, colorTwo);
  free(leftSquareTop);
  free(leftSquareBottom);
  free(rightSquareTop);
  free(rightSquareBottom);
  free(middleTopLeft);
  free(middleTopRight);
}

void sides_to_middle(CRGB * leds, int delayTime, CRGB colorOne, CRGB colorTwo, CRGB colorThree){
  LightSegment * allLights = get_all_lights(leds);
  allLights->turnOff();
  LightSegment * leftSquareLeft = get_left_square_left(leds);
  LightSegment * rightSquareRight = get_right_square_right(leds);
  SegmentList outer = SegmentList(leftSquareLeft);
  outer.add(rightSquareRight);
  LightSegment  * leftSquareRight = get_left_square_right(leds);
  LightSegment  * rightSquareLeft = get_right_square_left(leds);
  SegmentList middle = SegmentList(leftSquareRight);
  middle.add(rightSquareLeft);
  LightSegment * middleLeft = get_middle_left(leds);
  LightSegment * middleRight = get_middle_right(leds);
  SegmentList inner = SegmentList(middleLeft);
  inner.add(middleRight);

  outer.setAllToColor(colorOne);
  FastLED.show();
  delay(delayTime);
  outer.turnAllOff();
  middle.setAllToColor(colorTwo);
  FastLED.show();
  delay(delayTime);
  middle.turnAllOff();
  inner.setAllToColor(colorThree);
  FastLED.show();
  delay(delayTime);

  free(allLights);
  free(middleRight);
  free(middleLeft);
  free(leftSquareLeft);
  free(leftSquareRight);
  free(rightSquareLeft);
  free(rightSquareRight);
  
}

void trace_squares_and_middle(CRGB * leds, int delayTime, int thickness, CRGB color){
  LightSegment * leftSquare = get_left_square(leds);
  LightSegment * rightSquare = get_right_square(leds);
  LightSegment * middleArch = get_middle_arch(leds); 
  LightSegment * allLights = get_all_lights(leds);
  SegmentList lights = SegmentList(leftSquare);
  lights.add(rightSquare);
  lights.add(middleArch);
  lights.add(middleArch);

  boolean reverseTable[4] = {false, true, true, false};
  lights.traceAllDontRemain(thickness, delayTime, reverseTable, color);
  allLights->turnOff(); 

  free(leftSquare);
  free(rightSquare);
  free(middleArch);
  free(allLights);
}

void trace_squares_corners_and_middle(CRGB * leds, int delayTime, int thickness, CRGB color){
  LightSegment * leftSquare = get_left_square(leds);
  LightSegment * rightSquare = get_right_square(leds);
  LightSegment * middleArch = get_middle_arch(leds); 
  LightSegment * allLights = get_all_lights(leds);
  SegmentList lights = SegmentList(leftSquare);
  lights.add(leftSquare);
  lights.add(rightSquare);
  lights.add(rightSquare);
  lights.add(middleArch);
  lights.add(middleArch);

  boolean reverseTable[6] = {false, true, false, true, true, false};
  lights.traceAllDontRemain(thickness, delayTime, reverseTable, color);
  allLights->turnOff(); 

  free(leftSquare);
  free(rightSquare);
  free(middleArch);
  free(allLights);
}

void top_to_bottom(CRGB * leds, int delayTime, CRGB colorOne, CRGB colorTwo){
  LightSegment * allLights = get_all_lights(leds);
  LightSegment * leftSquareTop = get_left_square_top(leds);
  LightSegment * leftSquareBottom = get_left_square_bottom(leds);
  LightSegment * rightSquareTop = get_right_square_top(leds);
  LightSegment * rightSquareBottom = get_right_square_bottom(leds);
  LightSegment * middleTop = get_middle_top(leds);
  LightSegment * leftBridge = get_left_bridge(leds);
  LightSegment * rightBridge = get_right_bridge(leds);
  allLights->turnOff();

  SegmentList sideTopsAndBridges = SegmentList(leftSquareTop);
  sideTopsAndBridges.add(rightSquareTop);
  sideTopsAndBridges.add(rightBridge);
  sideTopsAndBridges.add(leftBridge);

  SegmentList middleTopAndSideBottoms = SegmentList(leftSquareBottom);
  middleTopAndSideBottoms.add(rightSquareBottom);
  middleTopAndSideBottoms.add(middleTop);

  middleTopAndSideBottoms.setAllToColor(colorOne);
  FastLED.show();
  delay(delayTime);
  middleTopAndSideBottoms.turnAllOff();
  sideTopsAndBridges.setAllToColor(colorTwo);
  FastLED.show();
  delay(delayTime);
  
  free(allLights);
  free(leftSquareTop);
  free(leftSquareBottom);
  free(rightSquareTop);
  free(rightSquareBottom);
  free(middleTop);
  free(leftBridge);
  free(rightBridge);
}

void trace_upwards(CRGB * leds, int thickness, int delayTime, CRGB color){
  LightSegment * leftSquareLeft = get_left_square_left(leds);
  LightSegment * leftSquareRight = get_left_square_right(leds);
  LightSegment * middleLeft = get_middle_left(leds);
  LightSegment * middleRight = get_middle_right(leds);
  LightSegment * rightSquareLeft = get_right_square_left(leds);
  LightSegment * rightSquareRight = get_right_square_right(leds);

  SegmentList lights = SegmentList(leftSquareLeft);
  lights.add(leftSquareRight);
  lights.add(middleLeft);
  lights.add(middleRight);
  lights.add(rightSquareLeft);
  lights.add(rightSquareRight);

  boolean reverseTable[6] = {true, false, false, true, true, false};

  lights.traceAllDontRemain(thickness, delayTime, reverseTable, color);

  free(leftSquareLeft);
  free(leftSquareRight);
  free(middleLeft);
  free(middleRight);
  free(rightSquareLeft);
  free(rightSquareRight);
}

void trace_downwards(CRGB * leds, int thickness, int delayTime, CRGB color){
  LightSegment * leftSquareLeft = get_left_square_left(leds);
  LightSegment * leftSquareRight = get_left_square_right(leds);
  LightSegment * middleLeft = get_middle_left(leds);
  LightSegment * middleRight = get_middle_right(leds);
  LightSegment * rightSquareLeft = get_right_square_left(leds);
  LightSegment * rightSquareRight = get_right_square_right(leds);

  SegmentList lights = SegmentList(leftSquareLeft);
  lights.add(leftSquareRight);
  lights.add(middleLeft);
  lights.add(middleRight);
  lights.add(rightSquareLeft);
  lights.add(rightSquareRight);

  boolean reverseTable[6] = {false, true, true, false, false, true};

  lights.traceAllDontRemain(thickness, delayTime, reverseTable, color);

  free(leftSquareLeft);
  free(leftSquareRight);
  free(middleLeft);
  free(middleRight);
  free(rightSquareLeft);
  free(rightSquareRight);
}

void trace_to_center(CRGB * leds, int thickness, int delayTime, CRGB color){
  LightSegment * startToMiddle = new LightSegment(leds, start, middle_top_middle);
  LightSegment * endToMiddle = new LightSegment(leds, middle_top_middle, end);

  SegmentList lights = SegmentList(startToMiddle);
  lights.add(endToMiddle);
  boolean reverseTable[2] = {false, true};
  lights.traceAllDontRemain(thickness, delayTime, reverseTable, color );

  free(startToMiddle);
  free(endToMiddle);
}

/* TODO:
void corners_cycle(CRGB * leds, int delayTime, CRGB colorOne, CRGB colorTwo){
  LightSegment * leftSquareTopRight = get_left_square
}
*/