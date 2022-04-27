#ifndef TUTOR_LIST_H_INCLUDED
#define TUTOR_LIST_H_INCLUDED

#include <iostream>

#include "tutor.h"
#include "tutor_node.h"

struct TutorList
{
    TutorNode *head;
    TutorNode *tail;
    size_t size;
    bool copy;
    TutorList();
    ~TutorList();
    void InsertBeginning(Tutor *tutor);
    void Add(Tutor *tutor);
    void AddToFront(Tutor *tutor);
    void Display(TutorNode *&, size_t, std::string nav, bool isAdmin = true);
    void DeleteBeginning();
    TutorList Sort(int (*CompareFn)(Tutor *, Tutor *), char order);
    bool Empty();
};

#endif
