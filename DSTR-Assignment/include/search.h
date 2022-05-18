#pragma once

#include <string>
#include <vector>

#include "sort.h"
#include "tutor.h"
#include "tutor_list.h"
#include "tutor_node.h"

TutorList searchTutor(TutorList &ll, int (*CompareFn)(Tutor *, Tutor *),
                      Tutor *t);
