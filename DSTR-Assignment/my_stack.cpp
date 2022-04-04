#include <iostream>

#include "my_stack.h"
#include "stack_list.h"
#include "list.h"
#include "node.h"

MyStack::MyStack() {
    ll = new StackList();
    size = 0;
}

MyStack::~MyStack() {
}

void MyStack::Push(Node* data) {
    /* Node<T>* newNode = new Node<T>(paramN); */
    ll->InsertBeginning(data);
    size++;
}

Node* MyStack::Top() {
    return ll->head->data;
}

void MyStack::Pop() {
    ll->DeleteBeginning();
    size--;
}

/* void MyStack::Display() { */
/*     ll->Display(); */
/* } */

bool MyStack::Empty() {
    return (size > 0) ? false: true;
}
