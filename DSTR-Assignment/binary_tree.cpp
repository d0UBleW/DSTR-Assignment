#include <iostream>

#include "binary_tree.h"
#include "my_stack.h"
#include "tutor.h"
#include "tutor_list.h"
#include "tutor_node.h"

BinaryTree::BinaryTree()
{
    root = nullptr;
}

BinaryTree::~BinaryTree()
{
}

BinaryTree::BinaryTree(TutorList &ll, int (*CompareFn)(Tutor *, Tutor *), char order)
{
    root = nullptr;
    if (ll.Empty())
        return;

    TutorNode *listNodePtr = ll.head;

    root = new TutorNode(listNodePtr->tutor);
    root->prev = nullptr;
    root->next = nullptr;
    listNodePtr = listNodePtr->next;

    while (listNodePtr != nullptr)
    {
        TutorNode *treeNodePtr = root;
        int result;
        TutorNode *treeNodePtrParent = nullptr;
        while (treeNodePtr != nullptr)
        {
            treeNodePtrParent = treeNodePtr;
            Tutor *listData = listNodePtr->tutor;
            Tutor *treeData = treeNodePtr->tutor;
            result = (*CompareFn)(listData, treeData);
            if (order == 'a')
            {
                if (result > 0)
                {
                    treeNodePtr = treeNodePtr->next;
                }
                else
                {
                    treeNodePtr = treeNodePtr->prev;
                }
            }
            else
            {
                if (result > 0)
                    treeNodePtr = treeNodePtr->prev;
                else
                    treeNodePtr = treeNodePtr->next;
            }
        }

        if (order == 'a')
        {
            if (result > 0)
            {
                treeNodePtrParent->next = new TutorNode(listNodePtr->tutor);
                treeNodePtr = treeNodePtrParent->next;
            }
            else
            {
                treeNodePtrParent->prev = new TutorNode(listNodePtr->tutor);
                treeNodePtr = treeNodePtrParent->prev;
            }
        }
        else
        {
            if (result > 0)
            {
                treeNodePtrParent->prev = new TutorNode(listNodePtr->tutor);
                treeNodePtr = treeNodePtrParent->prev;
            }
            else
            {
                treeNodePtrParent->next = new TutorNode(listNodePtr->tutor);
                treeNodePtr = treeNodePtrParent->next;
            }
        }
        treeNodePtr->next = nullptr;
        treeNodePtr->prev = nullptr;
        listNodePtr = listNodePtr->next;
    }
}

TutorList BinaryTree::ToLinkedList()
{
    TutorList lst;
    lst.copy = true;
    /*
     * Create a stack which stores a pointer to Node<T> (Node<T>*)
     */
    MyStack nodeStack;
    TutorNode *treeNodePtr = root;

    /*
     * Iterative in-order traversal
     */
    while (!nodeStack.Empty() || treeNodePtr != nullptr)
    {
        if (treeNodePtr != nullptr)
        {
            /*
             * Traverse the left sub-tree while keeping track of previous node
             * with stack
             */
            nodeStack.Push(treeNodePtr);
            treeNodePtr = treeNodePtr->prev;
        }
        else
        {
            /*
             * Reached end of left sub-tree, retrieve the parent (previous)
             * node from the stack
             */
            treeNodePtr = nodeStack.Top();
            lst.AddToLast(treeNodePtr->tutor);
            nodeStack.Pop();
            /*
             * Store the unused tree node address to be deallocate
             * before moving to the next node (right sub-tree)
             */
            TutorNode *tmp = treeNodePtr;
            treeNodePtr = treeNodePtr->next;
            delete tmp;
        }
    }
    return lst;
}
