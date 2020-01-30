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

void SegmentList::fadeAllIn(int delayTime){
  return;
  SegmentNode * currentSegmentSegmentNode = this->head;
  for (int i = 1; i <= 255; i = i++){
    currentSegmentSegmentNode = this->head;
    while (currentSegmentSegmentNode){
      LightSegment * segment = currentSegmentSegmentNode->segment;
      CRGB * currLeds = segment->leds; 
      int currLedsSize = segment->size;
      for (int j = 0; j <= currLedsSize; j++){
          //currLeds[j] += 10;
      }
      currentSegmentSegmentNode = currentSegmentSegmentNode->next;
    }
    FastLED.show();
    delay(delayTime);
  }
}

void SegmentList::fadeAllDown(int delayTime){
  SegmentNode * currentSegmentSegmentNode;
  for (int i = 254; i >= 2; i = i - 2){
    currentSegmentSegmentNode = this->head;
    while (currentSegmentSegmentNode){
      LightSegment * segment = currentSegmentSegmentNode->segment;
      CRGB * currLeds = segment->leds;
      int currLedsSize = segment->size;
      for ( int j = 0; j <= size; j++){
        currLeds[j].nscale8(i);
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
  for (int i = 0; i < this->head->segment->size - thickness + 2; i++){
    SegmentNode * currentSegment = this->head;
    int segIndex = 0;
    while (currentSegment){
      LightSegment * segment = currentSegment->segment;
      for (int j = 0; j < thickness; j++){
        if (reverse[segIndex]){
            segment->leds[segment->size-i-j] = color;
        } else {
            segment->leds[i+j] = color;
        }
      }
      currentSegment = currentSegment->next; 
      segIndex++;
    }
    FastLED.show();
    delay(delayTime);
  }
}
