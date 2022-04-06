#ifndef STACK_NODE_H_INCLUDED
#define STACK_NODE_H_INCLUDED

#include <iostream>

#include "tutor_node.h"

struct StackNode {
    TutorNode* data;
    StackNode* next;
    StackNode* prev;
    StackNode();
    StackNode(TutorNode* paramData);
    ~StackNode();
};

#endif
