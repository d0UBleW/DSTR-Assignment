#include <iostream>

#include "center.h"
#include "date.h"
#include "subject.h"
#include "tutor.h"

Tutor::Tutor()
{
    ID = "";
    name = "";
    payRate = 0;
    rating = 0;
    phone = "";
    address = "";
    center = nullptr;
    subject = nullptr;
    countRate = 0;
}

Tutor::Tutor(string paramName, string paramID, float paramPayRate, float paramRating)
{
    name = paramName;
    ID = paramID;
    payRate = paramPayRate;
    rating = paramRating;
}

Tutor::~Tutor()
{
}

Tutor *CreateTutor(string name, string ID, float payRate, float rating)
{
    Tutor *newTutor = new Tutor(name, ID, payRate, rating);
    return newTutor;
}
