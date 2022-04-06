#include <iostream>

#include "tutor_node.h"

TutorNode::TutorNode() {
    tutor = NULL;
    next = NULL;
    prev = NULL;
}

TutorNode::~TutorNode() {

}

TutorNode::TutorNode(Tutor* t) {
    this->tutor = t;
    this->next = NULL;
    this->prev = NULL;
}
