#include <iostream>

#include "tutor_node.h"
#include "tutor_list.h"
#include "binary_tree.h"
#include "tutor.h"
#include "my_stack.h"

TutorList::TutorList() {
    head = nullptr;
    size = 0;
    /* puts("TutorList constructed"); */
}

TutorList::TutorList(BinaryTree* bt) {
    /*
     * Create a stack which stores a pointer to Node<T> (Node<T>*)
     */
    MyStack* S = new MyStack();
    TutorNode* treeNodePtr = bt->root;
    TutorNode* listNodePtr = head;

    /*
     * Iterative in-order traversal
     */
    while (!S->Empty() || treeNodePtr != nullptr) {
        if (treeNodePtr != nullptr) {
            /*
             * Traverse the left sub-tree while keeping track of previous node
             * with stack
             */
            S->Push(treeNodePtr);
            treeNodePtr = treeNodePtr->prev;
        }
        else {
            /*
             * Reached end of left sub-tree, retrieve the parent (previous)
             * node from the stack
             */
            treeNodePtr = S->Top();
            /*
             * Check if our linked list is empty
             * Then build the linked list with deep copy of the tree node
             */
            if (listNodePtr == nullptr) {
                head = new TutorNode(*treeNodePtr);
                listNodePtr = head;
            }
            else {
                listNodePtr->next = new TutorNode(*treeNodePtr);
                listNodePtr = listNodePtr->next;
            }
            S->Pop();
            /*
             * Store the unused tree node address to be deallocate
             * before moving to the next node (right sub-tree)
             */
            TutorNode* tmp = treeNodePtr;
            treeNodePtr = treeNodePtr->next;
            delete tmp;
        }
    }
    listNodePtr->next = nullptr;
    delete S;
}

TutorList::~TutorList() {
    while (head != nullptr) {
        TutorNode* temp = head;
        head = head->next;
        delete temp->tutor;
        delete temp;
    }
}

void TutorList::InsertBeginning(Tutor* tutor) {
    TutorNode* newNode = new TutorNode(tutor);
    if (head == nullptr) {
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
    if (head == nullptr) {
        head = newNode;
        return;
    }

    TutorNode* ptr = head;
    while (ptr->next != nullptr) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

void TutorList::Display() {
    puts("Tutor Display");
    TutorNode* nodePtr = head;
    while (nodePtr != nullptr) {
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
    if (head->next != nullptr) {
        head = head->next;
        head->prev = nullptr;
    }
    delete nodePtr;
}

void TutorList::Sort(int (*CompareFn)(Tutor*, Tutor*), char order) {
    BinaryTree* bt = new BinaryTree(this, (*CompareFn), order);
    TutorList* sortedLL = new TutorList(bt);
    delete bt;
    sortedLL->Display();
    delete sortedLL;
}
