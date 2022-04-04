#include <iostream>
#include <stack>

#include "binary_tree.h"
#include "mystack.h"
#include "list.h"
#include "node.h"

BinaryTree::BinaryTree() {

}

BinaryTree::~BinaryTree() {

}

List* BinaryTree::BTToLL() {
    /*
     * Create a stack which stores a pointer to Node<T> (Node<T>*)
     */
    /* std::stack<Node*> s; */
    MyStack* S = new MyStack();
    Node* currNode = this->root;
    List* ll = new List();
    Node* ptr = ll->head;

    while (!S->Empty() || currNode != NULL) {
        if (currNode != NULL) {
            S->Push(currNode);
            /* s.push(currNode); */
            currNode = currNode->prev;
        }
        else {
            currNode = S->Top();
            /* currNode = s.top(); */
            if (ptr == NULL) {
                ll->head = new Node(*currNode);
                ptr = ll->head;
            }
            else {
                ptr->next = new Node(*currNode);
                ptr = ptr->next;
            }
            S->Pop();
            /* s.pop(); */
            Node* tmp = currNode;
            currNode = currNode->next;
            delete tmp;
        }
    }
    ptr->next = NULL;
    delete S;
    return ll;
}
