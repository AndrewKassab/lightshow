#include "SegmentList.hpp"

SegmentList::SegmentList(LightSegment * head){
  SegmentNode * newSegmentNode = new SegmentNode(head);
  this->head = newSegmentNode;
  this->size = 1;
}

SegmentList::~SegmentList(){
  SegmentNode * currentSegment = this->head;
  while (currentSegment->next){
    SegmentNode * previousSegment = currentSegment;
    currentSegment = currentSegment->next;
    free(previousSegment);
  }
  free(currentSegment);
}

int SegmentList::getLongestSegmentSize(){
  SegmentNode * currentNode = this->head;
  int largestSize = 0;
  while (currentNode){
    LightSegment * currSegment = currentNode->segment;
    if (currSegment->size > largestSize){
      largestSize = currSegment->size;
    }
    currentNode = currentNode->next;
  }
  return largestSize;
}

void SegmentList::add(LightSegment * newSegment){
  SegmentNode * currentSegment = this->head;
  while (currentSegment->next){
    currentSegment = currentSegment->next;
  }
  currentSegment->next = new SegmentNode(newSegment);
  this->size++;
}

void SegmentList::setAllToColor(CRGB color){
  SegmentNode * currentSegment = this->head;
  while (currentSegment){
    currentSegment->segment->setToColor(color);
    currentSegment = currentSegment->next;
  }
}
void SegmentList::turnAllOff(){
  SegmentNode * currentSegment = this->head;
  while (currentSegment){
    currentSegment->segment->turnOff();
    currentSegment = currentSegment->next;
  }
}

void SegmentList::fadeAllIn(int delayTime, CRGB color){
  int r_factor = color.r / 70;
  int g_factor = color.g / 70;
  int b_factor = color.b / 70;
  CRGB * currLeds;
  SegmentNode * currentSegmentSegmentNode = this->head;
  for (int i = 0; i < 70; i++){
    currentSegmentSegmentNode = this->head;
    while (currentSegmentSegmentNode){
      LightSegment * segment = currentSegmentSegmentNode->segment;
      currLeds = segment->leds; 
      int currLedsSize = segment->size;
      for (int j = 0; j <= currLedsSize; j++){
          currLeds[j].r += r_factor;
          currLeds[j].g += g_factor;
          currLeds[j].b += b_factor;
      }
      currentSegmentSegmentNode = currentSegmentSegmentNode->next;
    }
    FastLED.show();
    if ( i < 35 ){
      delay(delayTime*2);
    } else {
      delay(delayTime);
    }
  }
}

// TODO: Figure this shit out
void SegmentList::fadeAllDown(int delayTime){
  int r_factor = this->head->segment->leds[0].r / 70;
  int g_factor = this->head->segment->leds[0].g / 70;
  int b_factor = this->head->segment->leds[0].b / 70;
  SegmentNode * currentSegmentSegmentNode;
  for (int i = 0; i <= 70; i++){
    currentSegmentSegmentNode = this->head;
    while (currentSegmentSegmentNode){
      LightSegment * segment = currentSegmentSegmentNode->segment;
      CRGB * currLeds = segment->leds;
      int currLedsSize = segment->size;
      for ( int j = 0; j <= currLedsSize; j++){
        currLeds[j].r -= r_factor;
        currLeds[j].g -= g_factor;
        currLeds[j].b -= b_factor;
      }
      currentSegmentSegmentNode = currentSegmentSegmentNode->next;
    }
    FastLED.show();
    delay(delayTime);
  }  
  turnAllOff();
}

// each segment must be equal in length
void SegmentList::traceAllAndRemain(int thickness, int delayTime, boolean * reverse, CRGB color){

  int largestSize = this->getLongestSegmentSize();

  for (int i = 0; i <= largestSize; i++){
    SegmentNode * currentSegment = this->head;
    int segIndex = 0;
    while (currentSegment){
      LightSegment * segment = currentSegment->segment;
      if (reverse[segIndex]){
          segment->leds[segment->size-i] = color;
      } else {
          segment->leds[i] = color;
      }
      currentSegment = currentSegment->next; 
      segIndex++;
    }
    FastLED.show();
    delay(delayTime);
  }
}

// TODO: Fix the erasing at the end
void SegmentList::traceAllDontRemain(int thickness, int delayTime, boolean * reverse, CRGB color){

  int largestSize = this->getLongestSegmentSize();

  for (int i = 0; i < largestSize; i++){
    SegmentNode * currentSegment = this->head;
    int segIndex = 0;
    while (currentSegment){
      LightSegment * segment = currentSegment->segment;
      if (reverse[segIndex]){
          if (segment->size-i >= 0){
            segment->leds[segment->size-i] = color;
          }
      } else {
          if (i < segment->size){
            segment->leds[i] = color;
          }
      }
      if (reverse[segIndex] && i >= thickness){
        segment->leds[segment->size-i+thickness] = CRGB::Black;
      } else if ( i >= thickness ) {
        segment->leds[i-thickness] = CRGB::Black;
      }
      currentSegment = currentSegment->next; 
      segIndex++;
    }
    FastLED.show();
    delay(delayTime);
  }

  SegmentNode * currentSegment = this->head;
  int segIndex = 0;
  for ( int i = 0; i <= thickness; i++){
    while (currentSegment){
      LightSegment * segment = currentSegment->segment;
      if (!reverse[segIndex]){
        segment->leds[segment->size-thickness+i] = CRGB::Black;
      } else {
        segment->leds[thickness - i] = CRGB::Black;
      }
      currentSegment = currentSegment->next; 
      segIndex++;
    }
    FastLED.show();
    delay(delayTime);
  }

}
