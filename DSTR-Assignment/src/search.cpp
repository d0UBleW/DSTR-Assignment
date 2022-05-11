#include <string>
#include <vector>

#include "display.h"
#include "search.h"

using namespace std;

TutorList searchTutor(TutorList &ll, int (*CompareFn)(Tutor *, Tutor *), Tutor *t)
{
	TutorNode *temp = ll.head;
	TutorList tempList;

	while (temp != nullptr)
	{
		int result = (*CompareFn)(temp->tutor, t);
		if (result == 0)
		{
			tempList.AddToLast(temp->tutor);
		}

		temp = temp->next;
	}
	tempList.copy = true;

	return tempList;
}

