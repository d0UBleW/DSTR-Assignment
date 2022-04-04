#include <iostream>

#include "stacklist.h"

StackList::StackList() {

}

StackList::~StackList() {
    while (head != NULL) {
        StackNode* temp = head;
        head = head->next;
        delete temp->node;
        delete temp;
    }
}

void StackList::InsertBeginning(Node* n) {
    StackNode* sn = new StackNode(n);
    if (head == NULL) {
        head = sn;
        return;
    }
    sn->next = head;
    sn->prev = head->prev;
    head->prev = sn;
    head = sn;
}

void StackList::DeleteBeginning() {
    StackNode* ptr = head;
    if (head->next != NULL) {
        head = head->next;
        head->prev = NULL;
    }
    delete ptr;
}
