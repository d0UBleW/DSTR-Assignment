#include <iostream>

#include "tutor.h"
#include "tutor_list.h"
#include "binary_tree.h"

int CompareNumeric(int a, int b) {
  if (a > b)
    return 1;
  else if (a < b)
    return -1;
  else
    return 0;
}

int CompareFloat(float a, float b) {
  if (a > b)
    return 1;
  else if (a < b)
    return -1;
  else
    return 0;
}

int CompareString(std::string s1, std::string s2) {
    size_t shortest = std::min<size_t>(s1.length(), s2.length());
    for (size_t i = 0; i < shortest; i++) {
        if (s1[i] < s2[i]) return -1;
        if (s1[i] > s2[i]) return 1;
    }
    return s1.length() - s2.length();
}

int CompareTutorID(Tutor* t1, Tutor* t2) {
    int result = CompareString(t1->ID, t2->ID);
    return result;
}

int CompareTutorPay(Tutor* t1, Tutor* t2) {
    int result = CompareFloat(t1->payRate, t2->payRate);
    return result;
}

int CompareTutorRating(Tutor* t1, Tutor* t2) {
    int result = CompareFloat(t1->rating, t2->rating);
    return result;
}

/* void sortTutorList(TutorList* ll, int (*CompareFn)(Tutor*, Tutor*), */
/*         char order) { */
/*     BinaryTree* bt = new BinaryTree(ll, (*CompareFn), order); */
/*     TutorList* sortedLL = new TutorList(bt); */
/*     delete bt; */
/*     sortedLL->Display(); */
/*     delete sortedLL; */
/* } */
