#ifndef BINARY_TREE_H_INCLUDED
#define BINARY_TREE_H_INCLUDED

#include "type.h"

struct BinaryTree {
    TutorNode* root;
    BinaryTree();
    ~BinaryTree();
    BinaryTree(TutorList* ll, int (*CompareFn)(Tutor*, Tutor*), char order);
    TutorList* BTToLL();
};

#endif
