#include <iostream>

#include "sort.h"
#include "tutor.h"
#include "tutor_list.h"
#include "tutor_node.h"

using std::string;

int test() {
    TutorList a;
    a.InsertBeginning(CreateTutor("andy", "T01", 90.3, 4));
    a.Add(CreateTutor("alice", "T02", 90.3, 3));
    a.InsertBeginning(CreateTutor("bob", "T03", 70, 5));
    a.Display();
    // a->Sort(&CompareTutorID, 'a');
    SortMenu(a);

    return 0;
}
