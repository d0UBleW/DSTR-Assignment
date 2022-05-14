#include <iostream>
#include <vector>

#include "date.h"
#include "delete.h"
#include "display.h"
#include "tutor.h"
#include "validation.h"
#include "tutor_node.h"
#include "tutor_list.h"

using namespace std;

void DeleteTerminatedTutor(TutorList& tutorL)
{
	TutorNode* it = tutorL.head;
	while (it != tutorL.tail && it->tutor->ID != ID)
	{
		it++;
	}
	if (it == tutorL.tail)
	{
		std::cout << "No matching record found.\n";
		Enter();
		return;
	}
	while (true)
	{
		{
			TutorList temp(it, it + 1);
			clearScreen();
			SubDisplay(temp, 0, 1, false);
		}
		int choice = getIntInput("Do you want to proceed? (1 = Yes / 0 = No): ");
		if (isChoiceInMenuRange(choice, 1))
		{
			if (choice == 1)
			{
				tutorL.DeleteBeginning(it);
				std::cout << "Delete successful\n";
				Enter();
				return;
			}
			else if (choice == 0)
			{
				return;
			}
		}
	}
}

void DeleteTerminatedTutor(TutorList& tutorL)
{
	Date today = Date();
	today.Today();
	Date sixMonth = today.SixMonthBack();
	TutorNode* TnotePtr = tutorL.head;

	TutorList<size_t> idx;

	puts("");
	for (size_t i = 0; i < tutorL.size; i++)
	{
		Date term = TnotePtr->tutor->terminateDate;
		if (!term.Empty() && term < sixMonth)
		{
			idx.insert(idx.begin(), i);
			SubDisplay(tutorL, 0, 1, false);
		}
	}
	if (idx.size() == 0)
	{
		std::cout << "No tutor to be deleted.\n";
		Enter();
		return;
	}
	while (true)
	{
		int choice = getIntInput("These tutors will be deleted, proceed? (1 = Yes / 0 = No): ");
		if (isChoiceInMenuRange(choice, 1))
		{
			if (choice == 1)
			{
				for (size_t i = 0; i < idx.size(); i++)
				{
					//william i need some help here 
				}
				std::cout << "Delete successful\n";
				Enter();
				return;
			}
			else if (choice == 0)
			{
				return;
			}
		}
	}
}