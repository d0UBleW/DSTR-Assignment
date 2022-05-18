#include <iostream>

#include "my_stack.h"
#include "tutor_node.h"

StackNode::StackNode() {
    data = nullptr;
    next = nullptr;
}

StackNode::StackNode(TutorNode *paramData) {
    data = paramData;
    next = nullptr;
}

StackNode::~StackNode() {}

StackList::StackList() { head = nullptr; }

StackList::~StackList() {
    while (head != nullptr) {
        DeleteBeginning();
    }
}

void StackList::InsertBeginning(TutorNode *data) {
    StackNode *newStackNode = new StackNode(data);
    if (Empty()) {
        head = newStackNode;
        return;
    }
    newStackNode->next = head;
    head = newStackNode;
}

void StackList::DeleteBeginning() {
    if (Empty()) return;

    StackNode *ptr = head;
    if (head->next != nullptr) {
        head = head->next;
    } else {
        head = nullptr;
    }
    delete ptr;
}

bool StackList::Empty() {
    return head == nullptr;
}

MyStack::MyStack() {}

MyStack::~MyStack() {}

void MyStack::Push(TutorNode *data) { ll.InsertBeginning(data); }

TutorNode *MyStack::Top() {
    if (Empty()) return nullptr;
    return ll.head->data;
}

void MyStack::Pop() { ll.DeleteBeginning(); }

bool MyStack::Empty() { return (ll.Empty()) ? true : false; }
