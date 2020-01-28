#include "SegmentNode.hpp"

SegmentNode::SegmentNode(LightSegment * segment){
  this->segment = segment;
  this->next = NULL;
}