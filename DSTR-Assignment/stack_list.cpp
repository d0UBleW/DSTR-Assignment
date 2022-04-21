#include <iostream>

#include "stack_list.h"
#include "stack_node.h"

StackList::StackList() {
    head = nullptr;
    size = 0;
}

StackList::~StackList() {
    while (head != nullptr) {
        StackNode *temp = head;
        head = head->next;
        delete temp->data;
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
    newStackNode->prev = head->prev;
    head->prev = newStackNode;
    head = newStackNode;
}

void StackList::DeleteBeginning() {
    StackNode *ptr = head;
    if (head->next != nullptr) {
        head = head->next;
        head->prev = nullptr;
    }
    delete ptr;
}
