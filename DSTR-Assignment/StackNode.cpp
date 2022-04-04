#include <iostream>

#include "StackNode.h"

StackNode::StackNode() {

}

StackNode::StackNode(Node* paramNode) {
    node = paramNode;
    next = NULL;
    prev = NULL;
}

StackNode::~StackNode() {

}
