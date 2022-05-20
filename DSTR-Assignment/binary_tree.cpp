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
    while (root != nullptr)
    {
        TutorNode *treeNodePtr = root;
        /**
         * Make left child node as the root and make the new root right child
         * node as the old root left child node.
         * This essentialy tries to make root to only have right child node.
         */
        if (root->prev != nullptr)
        {
            root = root->prev;
            treeNodePtr->prev = root->next;
            root->next = treeNodePtr;
        }
        else
        {
            root = root->next;
            delete treeNodePtr;
        }
    }
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
        // Traverse until end of tree
        while (treeNodePtr != nullptr)
        {
            Tutor *listData = listNodePtr->tutor;
            Tutor *treeData = treeNodePtr->tutor;
            result = (*CompareFn)(listData, treeData);
            if (order == 'a')
            {
                if (result > 0)
                {
                    // reach end of tree
                    if (treeNodePtr->next == nullptr)
                    {
                        treeNodePtr->next = new TutorNode(listData);
                        break;
                    }
                    treeNodePtr = treeNodePtr->next;
                }
                else
                {
                    // reach end of tree
                    if (treeNodePtr->prev == nullptr)
                    {
                        treeNodePtr->prev = new TutorNode(listData);
                        break;
                    }
                    treeNodePtr = treeNodePtr->prev;
                }
            }
            else
            {
                if (result > 0)
                {
                    // reach end of tree
                    if (treeNodePtr->prev == nullptr)
                    {
                        treeNodePtr->prev = new TutorNode(listData);
                        break;
                    }
                    treeNodePtr = treeNodePtr->prev;
                }
                else
                {
                    // reach end of tree
                    if (treeNodePtr->next == nullptr)
                    {
                        treeNodePtr->next = new TutorNode(listData);
                        break;
                    }
                    treeNodePtr = treeNodePtr->next;
                }
            }
        }
        listNodePtr = listNodePtr->next;
    }
}

void BinaryTree::ToLinkedList(TutorList &result)
{
    result.copy = true;
    /*
     * Create a stack which stores TutorNode data type
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
             * node from the stack, append the node to new sorted list,
             * traverse the right sub-tree
             */
            treeNodePtr = nodeStack.Top();
            result.AddToLast(treeNodePtr->tutor);
            nodeStack.Pop();
            treeNodePtr = treeNodePtr->next;
        }
    }
}
