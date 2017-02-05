#include "Node.h"

Node::Node(Data _data) {
  next = nullptr;
  nextSequence = nullptr;
  data = _data;
  sequenceSize = 1;
}
