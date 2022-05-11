#ifndef MY_STACK_H_INCLUDED
#define MY_STACK_H_INCLUDED

#include "tutor_node.h"

struct StackNode {
    TutorNode *data;
    StackNode *next;
    StackNode();
    StackNode(TutorNode *paramData);
    ~StackNode();
};

struct StackList {
    StackNode *head;
    StackList();
    ~StackList();
    void InsertBeginning(TutorNode *data);
    void DeleteBeginning();
};

struct MyStack {
    StackList ll;
    MyStack();
    ~MyStack();
    void Push(TutorNode *data);
    TutorNode *Top();
    void Pop();
    bool Empty();
};

#endif
