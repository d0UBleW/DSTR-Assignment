#ifndef TUTOR_NODE_H_INCLUDED
#define TUTOR_NODE_H_INCLUDED

#include "tutor.h"

struct TutorNode {
  Tutor *tutor;
  TutorNode *next;
  TutorNode *prev;
  TutorNode();
  TutorNode(Tutor *paramTutor);
  ~TutorNode();
};

#endif
