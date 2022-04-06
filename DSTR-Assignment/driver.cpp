#include <iostream>

#include "tutor_list.h"
#include "tutor_node.h"
#include "sort.h"
#include "tutor.h"

using std::string;

int main() {
    TutorList* a = new TutorList();
    a->InsertBeginning(CreateTutor("andy", "T01", 90.3, 4));
    a->Add(CreateTutor("alice", "T02", 90.3, 3));
    a->InsertBeginning(CreateTutor("bob", "T03", 70, 5));
    a->Display();
    TutorList* sortedLLID = sortTutorList(a, &CompareTutorPay, 'd');
    sortedLLID->Display();
    a->Display();
    delete sortedLLID;
    delete a;
    return 0;
}
