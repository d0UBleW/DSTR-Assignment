#include <iostream>
#include <stack>

#include "binary_tree.h"
#include "my_stack.h"
#include "tutor_list.h"
#include "tutor_node.h"
#include "tutor.h"

BinaryTree::BinaryTree() {
    root = nullptr;
}

BinaryTree::~BinaryTree() {

}

BinaryTree::BinaryTree(TutorList* ll, int (*CompareFn)(Tutor*, Tutor*), char order) {
    if (ll == nullptr) return;

    TutorNode* listNodePtr = ll->head;

    root = new TutorNode();
    /* root->tutor = new Tutor(*(listNodePtr->tutor)); */
    root->tutor = listNodePtr->tutor;
    root->prev = nullptr;
    root->next = nullptr;
    listNodePtr = listNodePtr->next;

    while (listNodePtr != nullptr) {
        TutorNode* treeNodePtr = root;
        int result;
        TutorNode* treeNodePtrParent = nullptr;
        while (treeNodePtr != nullptr) {
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
                treeNodePtrParent->next->tutor = t;
                /* treeNodePtrParent->next->tutor = new Tutor(*t); */
                treeNodePtrParent->next->next = nullptr;
                treeNodePtrParent->next->prev = nullptr;
            }
            else {
                treeNodePtrParent->prev = new TutorNode();
                treeNodePtrParent->prev->tutor = t;
                /* treeNodePtrParent->prev->tutor = new Tutor(*t); */
                treeNodePtrParent->prev->next = nullptr;
                treeNodePtrParent->prev->prev = nullptr;
            }
        }
        else {
            if (result > 0) {
                treeNodePtrParent->prev = new TutorNode();
                treeNodePtrParent->prev->tutor = t;
                /* treeNodePtrParent->prev->tutor = new Tutor(*t); */
                treeNodePtrParent->prev->next = nullptr;
                treeNodePtrParent->prev->prev = nullptr;
            }
            else {
                treeNodePtrParent->next = new TutorNode();
                treeNodePtrParent->next->tutor = t;
                /* treeNodePtrParent->next->tutor = new Tutor(*t); */
                treeNodePtrParent->next->next = nullptr;
                treeNodePtrParent->next->prev = nullptr;
            }
        }
        listNodePtr = listNodePtr->next;
    }
}

