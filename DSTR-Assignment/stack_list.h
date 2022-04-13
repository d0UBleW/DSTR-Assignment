#ifndef STACK_LIST_H_INCLUDED
#define STACK_LIST_H_INCLUDED

#include "type.h"
#include "stack_node.h"

struct StackList {
    StackNode* head;
    size_t size;
    StackList();
    ~StackList();
    void InsertBeginning(TutorNode* data);
    void DeleteBeginning();
};

#endif
