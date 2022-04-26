#pragma once
#include <iostream>
#include "tutor.h"
#include "tutor_list.h"
#include "tutor_node.h"
#include "center.h"
#include "subject.h"

extern CenterList _CENTER;
extern SubjectList _SUBJECT;
using namespace std;

void DisplayTutor(TutorNode* current,TutorNode* tail,bool isAdmin=true);
void clearScreen();
void DisplayCenter();
void DisplaySubject();
void SubDisplay(Tutor* tutor, bool isAdmin=true);