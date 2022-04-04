#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include "type.h"

struct Node {
    Tutor* x;
    Node* next;
    Node* prev;
    Node();
    Node(Tutor* paramX);
    ~Node();
};

#endif
