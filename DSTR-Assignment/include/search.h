#pragma once

#include <string>
#include <vector>

#include "tutor.h"
#include "tutor_list.h"
#include "tutor_node.h"
#include "sort.h"

TutorList searchTutor(TutorList& ll, int (*CompareFn)(Tutor*, Tutor*), Tutor *t);
