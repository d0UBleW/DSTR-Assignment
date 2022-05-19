#include <string>
#include <vector>

#include "binary_tree.h"
#include "display.h"
#include "search.h"

using namespace std;

TutorList searchTutor(TutorList &ll, int (*CompareFn)(Tutor *, Tutor *), Tutor *t)
{
	BinaryTree bt = BinaryTree(ll, (*CompareFn), 'a');

	TutorNode *treeNodePtr = bt.root;
	TutorList tempList;
	tempList.copy = true;

	/**
	 * Binary search
	 */
	while (treeNodePtr != nullptr)
	{
		int result = (*CompareFn)(t, treeNodePtr->tutor);
		if (result == 0)
		{
			tempList.AddToLast(treeNodePtr->tutor);
			/**
			 * Since our binary tree is constructed in ascending order and
			 * every node left sub-tree always contains nodes with value
			 * smaller than or equal to the node, we traverse to the left
			 * sub-tree
			 */
			treeNodePtr = treeNodePtr->prev;
		}
		else if (result > 0)
		{
			treeNodePtr = treeNodePtr->next;
		}
		else
		{
			treeNodePtr = treeNodePtr->prev;
		}
	}

	return tempList;
}

