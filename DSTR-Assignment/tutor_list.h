#ifndef TUTOR_LIST_H_INCLUDED
#define TUTOR_LIST_H_INCLUDED

#include <iostream>

#include "type.h"

struct TutorList {
    TutorNode* head;
    size_t size;
    TutorList();
    ~TutorList();
    void InsertBeginning(Tutor* n);
    void Add(Tutor* n);
    void Display();
    void DeleteBeginning();

    BinaryTree* LLToBT(int (*CompareFn)(Tutor*, Tutor*), char order);

    TutorList* Sort(int (*CompareFn)(Tutor*, Tutor*), char order);
};

#endif
