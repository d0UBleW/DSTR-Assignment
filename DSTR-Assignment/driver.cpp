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
    a->Sort(CompareTutorID, 'a');
    delete a;

    size_t size = 3;
    Tutor* arr = new Tutor[size];

    arr[0].ID = "T001";
    arr[0].name = "First";

    arr[1].ID = "T002";
    arr[1].name = "Second";

    arr[2].ID = "T003";
    arr[2].name = "Third";

    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i].ID << ' ' << arr[i].name << '\n';
    }

    delete[] arr;

    /*
     * TODO: delete subject and center
     */

    return 0;
}
