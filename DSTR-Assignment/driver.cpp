#include <iostream>
#include "data_type.h"
#include "sort.h"

int main() {
    List<int>* a = new List<int>();
    a->InsertBeginning(1);
    a->Add(5);
    a->Add(4);
    a->Add(3);
    a->Add(2);
    a->Add(2);
    a->Add(2);
    a->Add(2);
    a->Add(2);
    a->Add(2);
    a->Add(2);
    a->Add(2);
    a->Add(2);
    a->Add(2);
    a->InsertBeginning(6);
    a->InsertBeginning(1);
    a->DeleteBeginning();
    a->Display();
    /* BinaryTree<int>* bt = LLToBT<int>(a, &CompareNumeric, 'a'); */
    /* std::cout << bt->root->x << '\n'; */
    /* std::cout << bt->root->prev->x << '\n'; */
    List<int>* sortedLL = a->Sort(&CompareNumeric, 'a');
    sortedLL->Display();
    a->Display();
    delete a;
    delete sortedLL;
    return 0;
}
