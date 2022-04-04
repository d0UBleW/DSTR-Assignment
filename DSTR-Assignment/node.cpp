#include <iostream>

#include "node.h"

Node::Node() {

}

Node::~Node() {

}

Node::Node(Tutor* t) {
    this->tutor = t;
    this->next = NULL;
    this->prev = NULL;
}
