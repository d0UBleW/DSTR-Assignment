#include <iostream>

#include "stack_list.h"

StackList::StackList() {
    head = NULL;
    size = 0;
}

StackList::~StackList() {
    while (head != NULL) {
        StackNode* temp = head;
        head = head->next;
        delete temp->data;
        delete temp;
    }
}

void StackList::InsertBeginning(TutorNode* data) {
    StackNode* newStackNode = new StackNode(data);
    if (head == NULL) {
        head = newStackNode;
        return;
    }
    newStackNode->next = head;
    newStackNode->prev = head->prev;
    head->prev = newStackNode;
    head = newStackNode;
}

void StackList::DeleteBeginning() {
    StackNode* ptr = head;
    if (head->next != NULL) {
        head = head->next;
        head->prev = NULL;
    }
    delete ptr;
}
