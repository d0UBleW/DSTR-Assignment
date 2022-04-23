#ifndef TUTOR_LIST_H_INCLUDED
#define TUTOR_LIST_H_INCLUDED

#include <iostream>

#include "tutor.h"
#include "tutor_node.h"

struct TutorList {
    TutorNode *head;
    TutorNode *tail;
    size_t size;
    bool copy;
    TutorList();
    ~TutorList();
    void InsertBeginning(Tutor *tutor);
    void Add(Tutor *tutor);
    void Display();
    void DeleteBeginning();
    void Sort(int (*CompareFn)(Tutor *, Tutor *), char order);
    bool Empty();
};

#endif
