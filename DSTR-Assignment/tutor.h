#ifndef TUTOR_H_INCLUDED
#define TUTOR_H_INCLUDED

#include <iostream>

#include "type.h"

using std::string;

struct Tutor {
    string ID;
    string name;
    float payRate;
    float rating;
    Date* joinDate;
    Date* terminateDate;
    Tutor();
    Tutor(string paramName, string paramID, float paramPayRate, float paramRating);
    Tutor(string paramID, string paramName, Date* paramJoinDate,
            Date* paramTerminateDate, float paramPayRate, string paramPhone,
            string paramAddress, Center* paramCenter, Subject* paramSubject,
            float paramRating);
    ~Tutor();
};

Tutor* CreateTutor(string name, string ID, float payRate, float rating);

#endif
