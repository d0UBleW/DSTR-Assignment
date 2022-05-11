#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include "tutor.h"
#include "tutor_list.h"

int CompareNumeric(int, int);

int CompareFloat(float, float);

int CompareString(std::string, std::string);

int CompareTutorID(Tutor *, Tutor *);

int CompareTutorPay(Tutor *, Tutor *);

int CompareTutorRating(Tutor *, Tutor *);

void SortMenu(TutorList &);

#endif
