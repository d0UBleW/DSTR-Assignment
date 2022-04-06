#include <iostream>

#include "stack_node.h"

StackNode::StackNode() {
    data = nullptr;
    next = nullptr;
    prev = nullptr;
}

StackNode::StackNode(TutorNode* paramData) {
    data = paramData;
    next = nullptr;
    prev = nullptr;
}

StackNode::~StackNode() {

}
