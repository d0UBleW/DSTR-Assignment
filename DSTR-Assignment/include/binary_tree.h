#ifndef BINARY_TREE_H_INCLUDED
#define BINARY_TREE_H_INCLUDED

#include "tutor.h"
#include "tutor_list.h"
#include "tutor_node.h"

struct BinaryTree {
    TutorNode *root;
    BinaryTree();
    ~BinaryTree();
    BinaryTree(TutorList &ll, int (*CompareFn)(Tutor *, Tutor *), char order);
    TutorList ToLinkedList();
};

#endif
