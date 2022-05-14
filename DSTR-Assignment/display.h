#pragma once

#include <iostream>

#include "center.h"
#include "subject.h"
#include "tutor.h"
#include "tutor_list.h"
#include "tutor_node.h"

extern CenterList _CENTER;
extern SubjectList _SUBJECT;

void DisplayTutor(TutorList &tutorL, bool isAdmin = true);
void clearScreen();
void DisplayCenter();
void DisplaySubject();
void SubDisplay(TutorList& tutorL, size_t start, size_t end, bool isAdmin);
