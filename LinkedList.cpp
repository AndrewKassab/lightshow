#include "LinkedList.hpp"

LinkedList::LinkedList(LightSegment * head){
  Node * newNode = new Node(head);
  this->head = newNode;
}

void LinkedList::add(LightSegment * newSegment){
  Node * currentSegment = this->head;
  while (currentSegment->next){
    currentSegment = currentSegment->next;
  }
  currentSegment->next = new Node(newSegment);
}