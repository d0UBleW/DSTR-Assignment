#include <iostream>
#include <stack>

#include "binary_tree.h"
#include "my_stack.h"
#include "tutor_list.h"
#include "tutor_node.h"

BinaryTree::BinaryTree() {
    root = NULL;
}

BinaryTree::~BinaryTree() {

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
