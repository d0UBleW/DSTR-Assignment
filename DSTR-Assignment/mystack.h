#ifndef MYSTACK_H_INCLUDED
#define MYSTACK_H_INCLUDED

#include <iostream>

#include "type.h"

struct MyStack {
    StackList* ll;
    size_t size;
    MyStack();
    ~MyStack();
    void Push(Node* data);
    Node* Top();
    void Pop();
    /* void Display(); */
    bool Empty();
};

#endif
