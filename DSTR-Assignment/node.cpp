#include <iostream>

#include "node.h"

Node::Node() {
    tutor = NULL;
    next = NULL;
    prev = NULL;
}

Node::~Node() {

}

Node::Node(Tutor* t) {
    this->tutor = t;
    this->next = NULL;
    this->prev = NULL;
}
