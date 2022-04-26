#pragma once
#include <iostream>
#include "tutor.h"
#include "tutor_list.h"
#include "tutor_node.h"

using namespace std;

void DisplayTutor(TutorNode* current,TutorNode* tail,bool isAdmin=true);
void clearScreen();
void SubDisplay(Tutor* tutor, bool isAdmin=true);