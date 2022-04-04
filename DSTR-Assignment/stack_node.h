#ifndef STACK_NODE_H_INCLUDED
#define STACK_NODE_H_INCLUDED

#include <iostream>

#include "node.h"

struct StackNode {
    Node* data;
    StackNode* next;
    StackNode* prev;
    StackNode();
    StackNode(Node* paramData);
    ~StackNode();
};

#endif
