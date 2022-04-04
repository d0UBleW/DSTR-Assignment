#include <iostream>

#include "stack_node.h"

StackNode::StackNode() {

}

StackNode::StackNode(Node* paramData) {
    data = paramData;
    next = NULL;
    prev = NULL;
}

StackNode::~StackNode() {

}
