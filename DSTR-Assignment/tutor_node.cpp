#include <iostream>

#include "tutor_node.h"

TutorNode::TutorNode() {
    tutor = nullptr;
    next = nullptr;
    prev = nullptr;
}

TutorNode::~TutorNode() {

}

TutorNode::TutorNode(Tutor* t) {
    this->tutor = t;
    this->next = nullptr;
    this->prev = nullptr;
}
