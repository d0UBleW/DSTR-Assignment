#include <string>
#include <vector>

#include "display.h"
#include "search.h"
#include "binary_tree.h"

using namespace std;

TutorList searchTutor(TutorList &ll, int (*CompareFn)(Tutor *, Tutor *),
                      Tutor *t) {
  BinaryTree bt = BinaryTree(ll, (*CompareFn), 'a');
  
  TutorNode *treeNodePtr = bt.root;
  TutorList tempList;
  tempList.copy = true;

  while (treeNodePtr != nullptr) {
    int result = (*CompareFn)(t, treeNodePtr->tutor);
    if (result == 0) {
      tempList.AddToLast(treeNodePtr->tutor);
      treeNodePtr = treeNodePtr->prev;
    }
    else if (result > 0) {
      treeNodePtr = treeNodePtr->next;
    }
    else {
      treeNodePtr = treeNodePtr->prev;
    }
  }

  return tempList;
}
