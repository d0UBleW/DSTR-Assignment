#include <iostream>
#include <string>

#include "display.h"
#include "file2struct.h"
/*#include "modify.h"*/
#include "search.h"
#include "sort.h"
#include "student_menu.h"
#include "tutor.h"
#include "validation.h"

void studentRatingMenu(TutorList &TL)
{
    while (true)
    {
        clearScreen();
        cout << "Welcome student what you want to do?" << endl;
        cout << "1) Rate a tutor" << endl;
        cout << "2) Display list of tutor" << endl;
        cout << "0) Log Out" << endl;
        string sentence = "Enter your choice: ";
        int choice = getIntInput(sentence);
        if (isChoiceInMenuRange(choice, 2))
        {
            switch (choice)
            {
            case 0:
                return;

            case 1:
                studentSearchingTutorMenu(TL);
                break;
            case 2:
                DisplayTutor(TL, false);
                break;
            }
        };
    }
}


void studentSearchingTutorMenu(TutorList& tutorL)
{
    while (true)
    {
        int (*CompareFn)(Tutor*, Tutor*) = nullptr;
        Tutor query;
        std::cout << "Enter Tutor ID (TXX): ";
        std::getline(std::cin, query.ID);
        CompareFn = &CompareTutorID;

        TutorList result = linearSearch(tutorL, (*CompareFn), query);
        DisplayTutor(result);

    }

}