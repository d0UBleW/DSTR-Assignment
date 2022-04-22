#include <iostream>

#include "my_stack.h"
#include "tutor_list.h"
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
        StackNode *temp = head;
        head = head->next;
        delete temp;
    }
}

void StackList::InsertBeginning(TutorNode *data) {
    StackNode *newStackNode = new StackNode(data);
    if (head == nullptr) {
        head = newStackNode;
        return;
    }
    newStackNode->next = head;
    head = newStackNode;
}

void StackList::DeleteBeginning() {
    StackNode *ptr = head;
    if (head->next != nullptr) {
        head = head->next;
    }
    if (head == ptr) head = nullptr;
    delete ptr;
}

MyStack::MyStack() {}

MyStack::~MyStack() {}

void MyStack::Push(TutorNode *data) { ll.InsertBeginning(data); }

TutorNode *MyStack::Top() {
    if (Empty()) return nullptr;
    return ll.head->data;
}

void MyStack::Pop() { ll.DeleteBeginning(); }

bool MyStack::Empty() { return (ll.head == nullptr) ? true : false; }
