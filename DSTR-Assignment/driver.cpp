#include <iostream>
#include "data_type.h"
#include "sort.h"

using std::string;

int main() {
    List<string>* a = new List<string>();
    a->InsertBeginning("abc");
    a->Add("abcd");
    a->Add("ab");
    a->Add("abcc");
    a->Add("abce");
    a->Add("abca");
    a->InsertBeginning("bc");
    a->InsertBeginning("abc");
    a->DeleteBeginning();
    a->Display();
    /* BinaryTree<int>* bt = LLToBT<int>(a, &CompareNumeric, 'a'); */
    /* std::cout << bt->root->x << '\n'; */
    /* std::cout << bt->root->prev->x << '\n'; */
    List<string>* sortedLL = a->Sort<string>(&CompareString, 'a');
    sortedLL->Display();
    a->Display();
    delete a;
    delete sortedLL;
    return 0;
}
