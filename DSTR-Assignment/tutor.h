#ifndef TUTOR_H_INCLUDED
#define TUTOR_H_INCLUDED

#include <string>

#include "center.h"
#include "date.h"
#include "subject.h"

using std::string;

struct Tutor {
    string ID;
    string name;
    float payRate;
    float rating;
    Date joinDate;
    Date terminateDate;
    Center *center;
    Subject *subject;
    Tutor();
    Tutor(string paramName, string paramID, float paramPayRate,
          float paramRating);
    ~Tutor();
};

Tutor *CreateTutor(string name, string ID, float payRate, float rating);

#endif
