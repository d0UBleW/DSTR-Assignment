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

TutorList* BinaryTree::BTToLL() {
    /*
     * Create a stack which stores a pointer to Node<T> (Node<T>*)
     */
    MyStack* S = new MyStack();
    TutorNode* treeNodePtr = this->root;
    TutorList* ll = new TutorList();
    TutorNode* listNodePtr = ll->head;

    /*
     * Iterative in-order traversal
     */
    while (!S->Empty() || treeNodePtr != NULL) {
        if (treeNodePtr != NULL) {
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
            if (listNodePtr == NULL) {
                ll->head = new TutorNode(*treeNodePtr);
                listNodePtr = ll->head;
            }
            else {
                listNodePtr->next = new TutorNode(*treeNodePtr);
                listNodePtr = listNodePtr->next;
            }
            S->Pop();
            /*
             * Store the unused tree node address to be deallocate
             */
            TutorNode* tmp = treeNodePtr;
            treeNodePtr = treeNodePtr->next;
            delete tmp;
        }
    }
    listNodePtr->next = NULL;
    delete S;
    return ll;
}
