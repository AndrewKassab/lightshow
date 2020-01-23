#include "LinkedList.hpp"

LinkedList::LinkedList(LightSegment * head){
  Node * newNode = new Node(head);
  this->head = newNode;
  this->size = 1;
}

void LinkedList::add(LightSegment * newSegment){
  Node * currentSegment = this->head;
  while (currentSegment->next){
    currentSegment = currentSegment->next;
  }
  currentSegment->next = new Node(newSegment);
  this->size++;
}

void LinkedList::setAllToColor(Color color){
  Node * currentSegment = this->head;
  while (currentSegment){
    currentSegment->segment->setToColor(color.r,color.g,color.b);
    currentSegment = currentSegment->next;
  }
}
void LinkedList::turnAllOff(){
  Node * currentSegment = this->head;
  while (currentSegment){
    currentSegment->segment->turnOff();
    currentSegment = currentSegment->next;
  }
}


void LinkedList::fadeAllIn(int delayTime){
  Node * currentSegmentNode = this->head;
  for (int i = 1; i <= 70; i++){
    currentSegmentNode = this->head;
    while (currentSegmentNode){
      LightSegment * segment = currentSegmentNode->segment;
      segment->setToColorNoUpdate((segment->r/70) * i, segment->g/70 * i, segment->b/70 * i);
      currentSegmentNode = currentSegmentNode->next;
    }
    FastLED.show();
    delay(delayTime);
  }
}

void LinkedList::fadeAllDown(int delayTime){
  Node * currentSegmentNode;
  for (int i = 1; i <= 70; i++){
    currentSegmentNode = this->head;
    while (currentSegmentNode){
      LightSegment * segment = currentSegmentNode->segment;
      segment->setToColorNoUpdate(segment->r - ((segment->r/70) * i), segment->g - ((segment->g/70) * i), segment->b - ((segment->b/70) * i));
      currentSegmentNode = currentSegmentNode->next;
    }
    FastLED.show();
    delay(delayTime);
  }  
  turnAllOff();
}

// each segment must be equal in length
void LinkedList::traceAll(int thickness, int delayTime, boolean * reverse){
  for (int i = 0; i < this->head->segment->endIndex - this->head->segment->startIndex - thickness + 2; i++){
    Node * currentSegment = this->head;
    int segIndex = 0;
    while (currentSegment){
      LightSegment * segment = currentSegment->segment;
      for (int j = 0; j < thickness; j++){
        if (reverse[segIndex]){
            segment->leds[segment->endIndex-i-j] = CRGB(segment->r,segment->g,segment->b);
        } else {
            segment->leds[segment->startIndex+i+j] = CRGB(segment->r,segment->g,segment->b);
        }
      }
      currentSegment = currentSegment->next; 
      segIndex++;
    }
    FastLED.show();
    delay(delayTime);
  }
}
