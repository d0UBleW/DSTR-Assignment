#include <iostream>

#include "display.h"
#include "tutor_list.h"
#include "tutor.h"
#include "center.h"
#include "subject.h"
#include "validation.h"
#include "tutor_node.h"

using namespace std;

void DisplayTutor(TutorNode* head,TutorNode* tail,bool isAdmin)
{
	TutorNode* nodePtr = head;
	size_t end = 5;
	if (isAdmin) { end = 3; };
	if (head == nullptr)
	{
		std::cout << "No tutor record to be displayed" << endl;
		Enter();
		return;
	}
	int choice = 0;
	bool isTail = false;
	while (true)
	{
		int step = 0;
		clearScreen();
		for (int i = 0; i < 3; i++)
		{
			if (nodePtr != nullptr)
			{
				step += 1;
				SubDisplay(nodePtr->tutor);
				if (nodePtr == tail)
				{
					step -= 1;
					isTail = true;
					break;
				}
				nodePtr = nodePtr->next;
			}
		}
		//backward to the start point of current page
		for (int i = 0; i < step; i++)
		{
			if ( nodePtr !=nullptr)
			{
				nodePtr = nodePtr->prev;
			}
		}
		string sentence = "Prev or Next (1 to Prev 2 to Next 0 to Exit): ";
		choice = getIntInput(sentence);
		// the statement to move forward and back
		if (choice == 2)
		{
			if (!isTail)
			{
				for (int i = 0; i < end; i++)
				{
					if (nodePtr != nullptr)
					{
						//moving forward
						nodePtr = nodePtr->next;
					}
				}
			}
		}
		else if (choice == 1)
		{
			if (nodePtr == head) { continue; }
			for (int i = 0; i < end; i++)
			{
				//moving backward
				isTail = false;
				nodePtr = nodePtr->prev;
			}
		}
		else if (choice == 0)
		{
			break;
		}	
	}
	return;
	
}

void SubDisplay(Tutor* tutor, bool isAdmin)
{

    cout << "Tutor ID: " << tutor->ID << endl;
    cout << "Tutor Name: " << tutor->name << endl;
    // if its not admin then only show
    // tutor id and name
    if (!isAdmin)
    {
        cout << endl;
		return;
    }
    cout << "Pay Rate: " << tutor->payRate << endl;
    cout << "Rating: " << tutor->rating << endl;
    cout << "Phone Number: " << tutor->phone << endl;

    cout << "Joined Date: " << tutor->joinDate.ToString() << endl;
    cout << "Termination Date: " << tutor->terminateDate.ToString() << endl;
    cout << "Center ID: " << tutor->center->ID << endl;
    cout << "Center Name: " << tutor->center->name << endl;
    cout << "Subject ID: " << tutor->subject->ID << endl;
    cout << "Subject Name: " << tutor->subject->name << endl;
    cout << endl;
    
}

void DisplayCenter()
{
	CenterNode* nodePtr = _CENTER.head;
	while (nodePtr != nullptr)
	{
		cout << "CenterID: " << nodePtr->center->ID<<endl;
		cout << "Center Name: " << nodePtr->center->name<<endl<<endl;
		nodePtr = nodePtr->next;
	}
	return;
}


void DisplaySubject()
{
	SubjectNode* nodePtr = _SUBJECT.head;
	while (nodePtr != nullptr)
	{
		cout << "SubjectID: " << nodePtr->subject->ID <<endl;
		cout << "Subject Name: " << nodePtr->subject->name<<endl<<endl;
		nodePtr = nodePtr->next;
	}
	return;

}

void clearScreen()
{
	system("cls || clear");
}

