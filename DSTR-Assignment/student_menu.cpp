#include <iostream>
#include <string>

#include "display.h"
#include "file2struct.h"
#include "modify.h"
#include "sort.h"
#include "student_menu.h"
#include "tutor.h"
#include "validation.h"

void studentRatingMenu(TutorList &TL)
{
    while (true)
    {
        clearScreen();
        std::cout << "Welcome student what you want to do?" << std::endl;
        std::cout << "1) Rate a tutor" << std::endl;
        std::cout << "2) Display list of tutor" << std::endl;
        std::cout << "0) Log Out" << std::endl;
        std::string sentence = "Enter your choice: ";
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
        }
    }
}

void studentSearchingTutorMenu(TutorList &tutorL)
{
    int (*CompareFn)(Tutor *, Tutor *) = nullptr;
    Tutor *query = new Tutor();
    std::cout << "Enter Tutor ID (TXX): ";
    std::getline(std::cin, query->ID);
    CompareFn = &CompareTutorID;

    TutorList result;
    result.copy = true;
    tutorL.Search((*CompareFn), query, result);
    if (result.Empty())
    {
        std::cout << "No Tutor Found please try another Tutor ID\n";
        Enter();
        return;
    }
    modifyTutor(result, false);
    tutorToFile(tutorL, TUTOR_FILE);
}
