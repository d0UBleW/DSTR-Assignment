#ifndef TUTOR_LIST_H_INCLUDED
#define TUTOR_LIST_H_INCLUDED

#include <iostream>

#include "type.h"

struct TutorList {
    TutorNode* head;
    size_t size;
    TutorList();
    TutorList(BinaryTree* bt);
    ~TutorList();
    void InsertBeginning(Tutor* tutor);
    void Add(Tutor* tutor);
    void Display();
    void DeleteBeginning();
};

#endif
