#include <iostream>

#include "stack_node.h"

StackNode::StackNode() {
    data = NULL;
    next = NULL;
    prev = NULL;
}

StackNode::StackNode(TutorNode* paramData) {
    data = paramData;
    next = NULL;
    prev = NULL;
}

StackNode::~StackNode() {

}
