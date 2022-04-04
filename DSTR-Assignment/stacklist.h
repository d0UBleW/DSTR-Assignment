#ifndef STACKLIST_H_INCLUDED
#define STACKLIST_H_INCLUDED

#include "StackNode.h"

struct StackList {
    StackNode* head;
    size_t size;
    StackList();
    ~StackList();
    void InsertBeginning(Node* n);
    void DeleteBeginning();
};

#endif
