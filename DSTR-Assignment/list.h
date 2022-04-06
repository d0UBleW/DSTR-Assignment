#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>

#include "type.h"

struct List {
    TutorNode* head;
    size_t size;
    List();
    ~List();
    void InsertBeginning(Tutor* n);
    void Add(Tutor* n);
    void Display();
    void DeleteBeginning();

    BinaryTree* LLToBT(int (*CompareFn)(Tutor*, Tutor*), char order);

    List* Sort(int (*CompareFn)(Tutor*, Tutor*), char order);
};

#endif
