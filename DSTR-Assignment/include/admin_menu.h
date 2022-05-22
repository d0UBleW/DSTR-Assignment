#pragma once
#include <iostream>

#include "tutor.h"
#include "tutor_list.h"

extern const std::string TUTOR_FILE;
void startMenu(TutorList &tutorL);
void adminMainMenu(TutorList &tutorL);
void addMenu(TutorList &tutorL);
void sortMenu(TutorList &tutorL);
void searchMenu(TutorList &tutorL);
void deleteMenu(TutorList &tutorL);
