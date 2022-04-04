#ifndef BINARY_TREE_H_INCLUDED
#define BINARY_TREE_H_INCLUDED

#include "type.h"

struct BinaryTree {
    Node* root;
    BinaryTree();
    ~BinaryTree();
    List* BTToLL();
};

#endif
