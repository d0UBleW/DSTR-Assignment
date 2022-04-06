#include <iostream>
#include <stack>

#include "binary_tree.h"
#include "my_stack.h"
#include "tutor_list.h"
#include "tutor_node.h"
#include "tutor.h"

BinaryTree::BinaryTree() {
    root = NULL;
}

BinaryTree::~BinaryTree() {

}

BinaryTree::BinaryTree(TutorList* ll, int (*CompareFn)(Tutor*, Tutor*), char order) {
    if (ll == NULL) return;

    TutorNode* listNodePtr = ll->head;

    root = new TutorNode();
    root->tutor = new Tutor(*(listNodePtr->tutor));
    root->prev = NULL;
    root->next = NULL;
    listNodePtr = listNodePtr->next;

    while (listNodePtr != NULL) {
        TutorNode* treeNodePtr = root;
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
}

