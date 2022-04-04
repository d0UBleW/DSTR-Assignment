#include <iostream>

#include "stack_node.h"

StackNode::StackNode() {
    data = NULL;
    next = NULL;
    prev = NULL;
}

StackNode::StackNode(Node* paramData) {
    data = paramData;
    next = NULL;
    prev = NULL;
}

StackNode::~StackNode() {

}
