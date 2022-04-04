#include <iostream>

#include "node.h"
#include "list.h"
#include "binary_tree.h"
#include "tutor.h"

List::List() {
    /* puts("List constructed"); */
}

List::~List() {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp->tutor;
        delete temp;
    }
}

void List::InsertBeginning(Tutor* tutor) {
    Node* newNode = new Node(tutor);
    if (head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    newNode->prev = head->prev;
    head->prev = newNode;
    head = newNode;
}

void List::Add(Tutor* tutor) {
    Node* newNode = new Node(tutor);
    size++;
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

void List::Display() {
    puts("Tutor Display");
    Node* nodePtr = head;
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

void List::DeleteBeginning() {
    Node* nodePtr = head;
    if (head->next != NULL) {
        head = head->next;
        head->prev = NULL;
    }
    delete nodePtr;
}

List* List::Sort(int (*CompareFn)(Tutor*, Tutor*), char order) {
    BinaryTree* bt = this->LLToBT((*CompareFn), order);
    List* sortedLL = bt->BTToLL();
    delete bt;
    return sortedLL;
}

BinaryTree* List::LLToBT(int (*CompareFn)(Tutor*, Tutor*), char order) {
    /* if (this == NULL) return NULL; */

    Node* listNodePtr = this->head;

    BinaryTree* bt = new BinaryTree();
    bt->root = new Node();
    bt->root->tutor = new Tutor(*(listNodePtr->tutor));
    bt->root->prev = NULL;
    bt->root->next = NULL;
    listNodePtr = listNodePtr->next;

    while (listNodePtr != NULL) {
        Node* treeNodePtr = bt->root;
        int result;
        Node* treeNodePtrParent = NULL;
        while (treeNodePtr != NULL) {
            treeNodePtrParent = treeNodePtr;
            Tutor* listData = listNodePtr->tutor;
            Tutor* treeData = treeNodePtr->tutor;
            result = (*CompareFn)(listData, treeData);
            if (order == 'a') {
                if (result > 0) {
                    treeNodePtr = treeNodePtr->next;
                }
                else {
                    treeNodePtr = treeNodePtr->prev;
                }
            }
            else {
                if (result > 0) treeNodePtr = treeNodePtr->prev;
                else treeNodePtr = treeNodePtr->next;
            }
        }

        Tutor* t = listNodePtr->tutor;

        if (order == 'a') {
            if (result > 0) {
                treeNodePtrParent->next = new Node();
                treeNodePtrParent->next->tutor = new Tutor(*t);
                treeNodePtrParent->next->next = NULL;
                treeNodePtrParent->next->prev = NULL;
            }
            else {
                treeNodePtrParent->prev = new Node();
                treeNodePtrParent->prev->tutor = new Tutor(*t);
                treeNodePtrParent->prev->next = NULL;
                treeNodePtrParent->prev->prev = NULL;
            }
        }
        else {
            if (result > 0) {
                treeNodePtrParent->prev = new Node();
                treeNodePtrParent->prev->tutor = new Tutor(*t);
                treeNodePtrParent->prev->next = NULL;
                treeNodePtrParent->prev->prev = NULL;
            }
            else {
                treeNodePtrParent->next = new Node();
                treeNodePtrParent->next->tutor = new Tutor(*t);
                treeNodePtrParent->next->next = NULL;
                treeNodePtrParent->next->prev = NULL;
            }
        }
        listNodePtr = listNodePtr->next;
    }
    return bt;
}
