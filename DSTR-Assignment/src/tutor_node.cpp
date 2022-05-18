#include "tutor_node.h"
#include "tutor.h"

TutorNode::TutorNode() {
  tutor = nullptr;
  next = nullptr;
  prev = nullptr;
}

TutorNode::~TutorNode() {}

TutorNode::TutorNode(Tutor *t) {
  tutor = t;
  next = nullptr;
  prev = nullptr;
}
