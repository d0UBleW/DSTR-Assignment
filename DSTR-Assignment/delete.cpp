#include <iostream>
#include <vector>

#include "date.h"
#include "delete.h"
#include "display.h"
#include "tutor.h"
#include "validation.h"

void DeleteTutor(TutorList &tutorL, std::string ID)
{
    TutorNode *nodePtr = tutorL.head;

    while (nodePtr != nullptr && nodePtr->tutor->ID != ID)
    {
        nodePtr = nodePtr->next;
    }

    if (nodePtr == nullptr)
    {
        std::cout << "No tutor record found\n";
        Enter();
        return;
    }

    while (true)
    {
        clearScreen();
        tutorL.Display(nodePtr, 1);
        int choice = getIntInput("These tutors will be deleted, proceed? (1 = Yes / 0 = No): ");
        if (!isChoiceInMenuRange(choice, 1))
        {
            continue;
        }
        if (choice == 0)
            return;
        break;
    }

    tutorL.DeleteNode(nodePtr);
    std::cout << "Delete successful\n";
    Enter();
}

void DeleteTerminatedTutor(TutorList &tutorL)
{
    Date today = Date();
    today.Today();
    Date sixMonth = today.SixMonthBack();

    TutorNode *nodePtr = tutorL.head;

    /**
     * Create a vector to store all nodes which are eligible to be deleted
     */
    std::vector<TutorNode *> toBeDeleted;

    while (nodePtr != nullptr)
    {
        Date term = nodePtr->tutor->terminateDate;
        if (!term.Empty() && term < sixMonth)
        {
            toBeDeleted.push_back(nodePtr);
            tutorL.Display(nodePtr, 1);
        }
        nodePtr = nodePtr->next;
    }

    if (toBeDeleted.size() == 0)
    {
        std::cout << "No tutor to be deleted.\n";
        Enter();
        return;
    }

    while (true)
    {
        int choice = getIntInput("These tutors will be deleted, proceed? (1 = Yes / 0 = No): ");
        if (!isChoiceInMenuRange(choice, 1))
        {
            continue;
        }
        if (choice == 0)
        {
            return;
        }
        break;
    }

    std::vector<TutorNode *>::iterator it;

    for (it = toBeDeleted.begin(); it != toBeDeleted.end(); it++)
    {
        tutorL.DeleteNode(*it);
    }

    std::cout << "Delete successful\n";
    Enter();
    return;
}
