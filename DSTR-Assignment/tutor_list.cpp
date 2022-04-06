#include <iostream>

#include "tutor_node.h"
#include "tutor_list.h"
#include "binary_tree.h"
#include "tutor.h"

TutorList::TutorList() {
    head = NULL;
    size = 0;
    /* puts("TutorList constructed"); */
}

TutorList::~TutorList() {
    while (head != NULL) {
        TutorNode* temp = head;
        head = head->next;
        delete temp->tutor;
        delete temp;
    }
}

void TutorList::InsertBeginning(Tutor* tutor) {
    TutorNode* newNode = new TutorNode(tutor);
    if (head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    newNode->prev = head->prev;
    head->prev = newNode;
    head = newNode;
}

void TutorList::Add(Tutor* tutor) {
    TutorNode* newNode = new TutorNode(tutor);
    size++;
    if (head == NULL) {
        head = newNode;
        return;
    }

    TutorNode* ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

void TutorList::Display() {
    puts("Tutor Display");
    TutorNode* nodePtr = head;
    while (nodePtr != NULL) {
        std::cout << "Addr: " << nodePtr->tutor << '\n';
        std::cout << "Name: " << nodePtr->tutor->name << '\n';
        std::cout << "ID: " << nodePtr->tutor->ID << '\n';
        std::cout << "Pay: " << nodePtr->tutor->payRate << '\n';
        std::cout << "Rating: " << nodePtr->tutor->rating << '\n';
        puts("");
        nodePtr = nodePtr->next;
    }
    puts("");
}

void TutorList::DeleteBeginning() {
    TutorNode* nodePtr = head;
    if (head->next != NULL) {
        head = head->next;
        head->prev = NULL;
    }
    delete nodePtr;
}

TutorList* TutorList::Sort(int (*CompareFn)(Tutor*, Tutor*), char order) {
    BinaryTree* bt = new BinaryTree(this, (*CompareFn), order);
    TutorList* sortedLL = bt->BTToLL();
    delete bt;
    return sortedLL;
}
