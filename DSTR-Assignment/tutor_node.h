#ifndef TUTOR_NODE_H_INCLUDED
#define TUTOR_NODE_H_INCLUDED

#include "type.h"

struct TutorNode {
    Tutor* tutor;
    TutorNode* next;
    TutorNode* prev;
    TutorNode();
    TutorNode(Tutor* t);
    ~TutorNode();
};

#endif
