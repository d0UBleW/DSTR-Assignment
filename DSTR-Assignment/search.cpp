#include<vector>
#include<string>

#include "search.h"
#include "display.h"

using namespace std;

TutorList linearSearch(TutorList& ll, int (*CompareFn)(Tutor*, Tutor*), Tutor *t)
{
	TutorNode *temp = ll.head;
	TutorList tempList;

	if (ll.head == NULL) {
		printf("List is empty\n");
		return;
	}
	
	while (temp != nullptr) {
		int result = (*CompareFn)(temp->tutor, t);
		if (result == 0) {
			tempList.AddToLast(temp->tutor);
		}

		temp = temp->next;

	}

	return tempList;
}

