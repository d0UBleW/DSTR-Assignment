#ifndef TUTOR_H_INCLUDED
#define TUTOR_H_INCLUDED

#include <iostream>

#include "type.h"

using std::string;

struct Tutor {
    string name;
    string ID;
    float payRate;
    float rating;
    Tutor();
    Tutor(string paramName, string paramID, float paramPayRate, float paramRating);
    ~Tutor();
};

Tutor* CreateTutor(string name, string ID, float payRate, float rating);

#endif
