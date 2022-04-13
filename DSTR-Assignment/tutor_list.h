#ifndef TUTOR_LIST_H_INCLUDED
#define TUTOR_LIST_H_INCLUDED

#include "type.h"

struct TutorList {
    TutorNode* head;
    size_t size;
    bool copy;
    TutorList();
    TutorList(BinaryTree* bt);
    ~TutorList();
    void InsertBeginning(Tutor* tutor);
    void Add(Tutor* tutor);
    void Display();
    void DeleteBeginning();
    void Sort(int (*CompareFn)(Tutor*, Tutor*), char order);
};

#endif
