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
    BinaryTree* bt = this->LLToBT((*CompareFn), order);
    TutorList* sortedLL = bt->BTToLL();
    delete bt;
    return sortedLL;
}

BinaryTree* TutorList::LLToBT(int (*CompareFn)(Tutor*, Tutor*), char order) {
    /* if (this == NULL) return NULL; */

    TutorNode* listNodePtr = this->head;

    BinaryTree* bt = new BinaryTree();
    bt->root = new TutorNode();
    bt->root->tutor = new Tutor(*(listNodePtr->tutor));
    bt->root->prev = NULL;
    bt->root->next = NULL;
    listNodePtr = listNodePtr->next;

    while (listNodePtr != NULL) {
        TutorNode* treeNodePtr = bt->root;
        int result;
        TutorNode* treeNodePtrParent = NULL;
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
                treeNodePtrParent->next = new TutorNode();
                treeNodePtrParent->next->tutor = new Tutor(*t);
                treeNodePtrParent->next->next = NULL;
                treeNodePtrParent->next->prev = NULL;
            }
            else {
                treeNodePtrParent->prev = new TutorNode();
                treeNodePtrParent->prev->tutor = new Tutor(*t);
                treeNodePtrParent->prev->next = NULL;
                treeNodePtrParent->prev->prev = NULL;
            }
        }
        else {
            if (result > 0) {
                treeNodePtrParent->prev = new TutorNode();
                treeNodePtrParent->prev->tutor = new Tutor(*t);
                treeNodePtrParent->prev->next = NULL;
                treeNodePtrParent->prev->prev = NULL;
            }
            else {
                treeNodePtrParent->next = new TutorNode();
                treeNodePtrParent->next->tutor = new Tutor(*t);
                treeNodePtrParent->next->next = NULL;
                treeNodePtrParent->next->prev = NULL;
            }
        }
        listNodePtr = listNodePtr->next;
    }
    return bt;
}
