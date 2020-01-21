#include "Node.hpp"

Node::Node(LightSegment * lightSegment){
  this->lightSegment = lightSegment;
  this->next = null;
}