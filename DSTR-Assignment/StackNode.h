#ifndef STACKNODE_H_INCLUDED
#define STACKNODE_H_INCLUDED

#include <iostream>

#include "node.h"

struct StackNode {
    Node* node;
    StackNode* next;
    StackNode* prev;
    StackNode();
    StackNode(Node* paramNode);
    ~StackNode();
};

#endif
