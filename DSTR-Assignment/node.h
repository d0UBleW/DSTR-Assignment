#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include "type.h"

struct Node {
    Tutor* tutor;
    Node* next;
    Node* prev;
    Node();
    Node(Tutor* t);
    ~Node();
};

#endif
