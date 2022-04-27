#include <iostream>

#include "center.h"
#include "display.h"
#include "subject.h"
#include "tutor.h"
#include "tutor_list.h"
#include "tutor_node.h"
#include "validation.h"

using namespace std;

void DisplayTutor(TutorList &tutorL, bool isAdmin)
{
    if (tutorL.head == nullptr)
    {
        std::cout << "No tutor record to be displayed" << endl;
        Enter();
        return;
    }

    int choice = 0;
    size_t step = 5;
    if (isAdmin) step = 3;
    TutorNode *ptr = tutorL.head;

    while (true)
    {
        clearScreen();
        tutorL.Display(ptr, step);
        std::string sentence = "Prev or Next (1 to Prev 2 to Next 0 to Exit): ";
        choice = getIntInput(sentence);
        if (choice == 0)
            return;
        else if (choice < 0 || choice > 2)
        {
            std::cout << "Invalid choice\n";
            Enter();
            continue;
        }
        else
        {
            /**
             * Keep track of the first address of the group in case we are
             * reaching the very last group
             */
            TutorNode *temp = ptr;
            for (size_t i = 0; i < step; i++)
            {
                if (choice == 1)
                {
                    if (ptr == tutorL.head) break;
                    ptr = ptr->prev;
                }
                else if (choice == 2)
                {
                    if (ptr == nullptr) break;
                    ptr = ptr->next;
                }
            }
            /**
             * When we reach the very last group reset ptr to the first
             * address of the group
             */
            if (ptr == nullptr) ptr = temp;
        }
    }
}

void DisplayCenter()
{
    CenterNode *nodePtr = _CENTER.head;
    while (nodePtr != nullptr)
    {
        cout << "CenterID: " << nodePtr->center->ID << endl;
        cout << "Center Name: " << nodePtr->center->name << endl << endl;
        nodePtr = nodePtr->next;
    }
    return;
}

void DisplaySubject()
{
    SubjectNode *nodePtr = _SUBJECT.head;
    while (nodePtr != nullptr)
    {
        cout << "SubjectID: " << nodePtr->subject->ID << endl;
        cout << "Subject Name: " << nodePtr->subject->name << endl << endl;
        nodePtr = nodePtr->next;
    }
    return;
}

void clearScreen()
{
    system("cls || clear");
}
