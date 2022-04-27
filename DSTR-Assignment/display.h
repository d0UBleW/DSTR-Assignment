#pragma once
#include "center.h"
#include "subject.h"
#include "tutor.h"
#include "tutor_list.h"
#include "tutor_node.h"
#include <iostream>

extern CenterList _CENTER;
extern SubjectList _SUBJECT;
using namespace std;

void DisplayTutor(TutorList &tutorL, bool isAdmin = true);
void clearScreen();
void DisplayCenter();
void DisplaySubject();
