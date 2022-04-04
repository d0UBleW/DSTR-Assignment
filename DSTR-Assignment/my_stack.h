#ifndef MY_STACK_H_INCLUDED
#define MY_STACK_H_INCLUDED

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
