#include <iostream>

#include "add.h"
#include "admin_menu.h"
#include "authentication.h"
#include "delete.h"
#include "display.h"
#include "file2struct.h"
#include "modify.h"
#include "sort.h"
#include "student_menu.h"
#include "tutor.h"
#include "tutor_list.h"
#include "validation.h"

void startMenu(TutorList &tutorL)
{
    while (true)
    {
        clearScreen();
        std::cout << "Welcome to eXcel Tuition Centre" << std::endl;
        std::cout << "Who are you?" << std::endl;
        std::cout << "1) Admin" << std::endl;
        std::cout << "2) Student" << std::endl;
        std::cout << "3) Student Register" << std::endl;
        std::cout << "0) Exit" << std::endl;
        std::string sentence = "Enter your choice: ";
        int choice = getIntInput(sentence);
        if (!isChoiceInMenuRange(choice, 3))
            continue;
        switch (choice)
        {
        case 0:
            std::cout << "Thank you for using this system" << std::endl;
            return;

        case 1:
            if (adminLogin())
            {
                adminMainMenu(tutorL);
            }
            else
            {
                continue;
            }
            break;
        case 2:
            if (studentLogin())
            {
                studentRatingMenu(tutorL);
            }
            else
            {
                continue;
            }
            break;
        case 3:
            registerStudent();
            break;
        }
    }
}

void modifyMenu(TutorList &tutorL)
{
    while (true)
    {
        clearScreen();
        std::cout << "You are about to modify Tutor Record, Please be careful!\n";
        std::cout << "1) Modify by Tutor ID" << std::endl;
        std::cout << "0) Return to Previous Page" << std::endl;
        std::string sentence = "Enter your choice: ";
        int choice = getIntInput(sentence);
        if (!isChoiceInMenuRange(choice, 1))
            continue;
        Tutor query;
        int (*CompareFn)(Tutor *, Tutor *) = nullptr;
        if (choice == 1)
        {
            std::cout << "Enter Tutor ID (TXX): ";
            std::getline(std::cin, query.ID);
            CompareFn = &CompareTutorID;
            TutorList result;
            result.copy = true;
            tutorL.Search((*CompareFn), &query, result);
            if (!result.Empty())
            {
                modifyTutor(result, true);
                tutorToFile(tutorL, TUTOR_FILE);
            }
            else
            {
                std::cout << "No Tutor found please try another Tutor ID" << std::endl;
                Enter();
            }
        }
        else if (choice == 0)
        {
            return;
        }
    }
}
void adminMainMenu(TutorList &tutorL)
{
    while (true)
    {
        clearScreen();
        std::cout << "Welcome back admin, please select a function" << std::endl;
        std::cout << "1) Add Tutor" << std::endl;
        std::cout << "2) Display Tutor" << std::endl;
        std::cout << "3) Sort Tutor" << std::endl;
        std::cout << "4) Search Tutor" << std::endl;
        std::cout << "5) Modify Tutor" << std::endl;
        std::cout << "6) Termination or Delete Tutor" << std::endl;
        std::cout << "7) Register New Admin" << std::endl;
        std::cout << "0) Logout" << std::endl;
        std::string sentence = "Enter your choice: ";
        int choice = getIntInput(sentence);
        if (!isChoiceInMenuRange(choice, 7))
            continue;
        switch (choice)
        {
        case 0:
            return;

        case 1:
            addMenu(tutorL);
            break;
        case 2:
            DisplayTutor(tutorL);
            break;
        case 3:
            // code here
            sortMenu(tutorL);
            break;
        case 4:
            // code here
            searchMenu(tutorL);
            break;
        case 5:
            modifyMenu(tutorL);
            break;
        case 6:
            deleteMenu(tutorL);
            break;
        case 7:
            registerAdmin();
            break;
        }
    }
}

void addMenu(TutorList &tutorL)
{

    while (true)
    {
        clearScreen();
        Tutor *tutor;
        std::cout << "Where you want to add?" << std::endl;
        std::cout << "1) Add to First" << std::endl;
        std::cout << "2) Add to Last" << std::endl;
        std::cout << "0) Previous Page" << std::endl;
        std::string sentence = "Enter your choice: ";
        int choice = getIntInput(sentence);
        if (!isChoiceInMenuRange(choice, 2))
            continue;
        // code here
        switch (choice)
        {
        case 0:
            return;

        case 1:
            tutor = addingInterface(tutorL);
            tutorL.AddToFront(tutor);
            tutorToFile(tutorL, TUTOR_FILE);
            std::cout << "Succesfully added to front" << std::endl;
            Enter();
            break;
        case 2:
            tutor = addingInterface(tutorL);
            tutorL.AddToLast(tutor);
            tutorToFile(tutorL, TUTOR_FILE);
            std::cout << "Succesfully added to back" << std::endl;
            Enter();
            break;
        }
    }
}

void sortMenu(TutorList &tutorL)
{
    int choice;
    while (true)
    {
        clearScreen();
        std::cout << "How do you want to sort?" << std::endl;
        std::cout << "1) Sort by Tutors ID" << std::endl;
        std::cout << "2) Sort by Pay Rate " << std::endl;
        std::cout << "3) Sort by Overall Performance" << std::endl;
        std::cout << "0) Previous Page" << std::endl;
        std::string sentence = "Enter your choice: ";
        choice = getIntInput(sentence);
        if (!isChoiceInMenuRange(choice, 3))
            continue;

        int (*CompareFn)(Tutor *, Tutor *) = nullptr;
        switch (choice)
        {
        case 1:
            CompareFn = &CompareTutorID;
            break;
        case 2:
            CompareFn = &CompareTutorPay;
            break;
        case 3:
            CompareFn = &CompareTutorRating;
            break;
        case 0:
            return;
        }
        std::cout << "Sort in:\n";
        std::cout << "1) Ascending order\n";
        std::cout << "2) Descending order\n";
        std::cout << "0) Back\n";
        while (true)
        {
            int option = getIntInput("Enter your choice: ");
            if (!isChoiceInMenuRange(option, 2))
                continue;
            char order = ' ';
            if (option == 0)
            {
                break;
            }
            else if (option == 1)
            {
                order = 'a';
            }
            else if (option == 2)
            {
                order = 'd';
            }
            TutorList sortedTutorL;
            sortedTutorL.copy = true;
            tutorL.Sort((*CompareFn), order, sortedTutorL);
            DisplayTutor(sortedTutorL);
            break;
        }
    }
}

void searchMenu(TutorList &tutorL)
{
    while (true)
    {
        clearScreen();
        std::cout << "How do you want to search?" << std::endl;
        std::cout << "1) Search by Tutor ID" << std::endl;
        std::cout << "2) Search by overall performance" << std::endl;
        std::cout << "0) Previous Page" << std::endl;
        int choice = getIntInput("Enter your choice: ");
        if (!isChoiceInMenuRange(choice, 2))
            continue;
        Tutor query;
        int (*CompareFn)(Tutor *, Tutor *) = nullptr;
        if (choice == 0)
        {
            break;
        }
        else if (choice == 1)
        {
            std::cout << "Enter Tutor ID (TXX): ";
            std::getline(std::cin, query.ID);
            CompareFn = &CompareTutorID;
        }
        else if (choice == 2)
        {
            query.rating = getFloatInput("Enter Tutor rating: ");
            CompareFn = &CompareTutorRating;
        }
        TutorList result;
        result.copy = true;
        tutorL.Search((*CompareFn), &query, result);
        DisplayTutor(result);
    }
}

void deleteMenu(TutorList &tutorL)
{
    while (true)
    {
        clearScreen();
        std::cout << "Which function you need?" << std::endl;
        std::cout << "1) Terminate all expired tutors" << std::endl;
        std::cout << "2) Delete specific tutor data" << std::endl;
        std::cout << "0) Previous Page" << std::endl;
        std::string sentence = "Enter your choice: ";
        int choice = getIntInput(sentence);
        if (!isChoiceInMenuRange(choice, 2))
            continue;
        if (choice == 1)
        {
            DeleteTerminatedTutor(tutorL);
            tutorToFile(tutorL, TUTOR_FILE);
        }

        else if (choice == 2)
        {
            std::string ID;
            std::cout << "Enter Tutor ID (TXX): ";
            std::getline(std::cin, ID);
            DeleteTutor(tutorL, ID);
            tutorToFile(tutorL, TUTOR_FILE);
        }
        else if (choice == 0)
        {
            return;
        }
    }
}
