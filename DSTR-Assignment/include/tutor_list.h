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
  void AddToLast(Tutor *tutor);
  void AddToFront(Tutor *tutor);
  void Display(TutorNode *tutorN, size_t step, bool isAdmin = true);
  void DeleteBeginning();
  void DeleteNode(TutorNode *);
  void Sort(int (*CompareFn)(Tutor *, Tutor *), char order, TutorList &result);
  void Search(int (*CompareFn)(Tutor *, Tutor *), Tutor *query, TutorList &listResult);
  bool Empty();
};

#endif
