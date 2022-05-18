

#include "display.h"
#include "tutor_list.h"
#include "validation.h"

void modifyTutor(TutorList &tutorL, bool isAdmin)
{
    Tutor *tutor = tutorL.head->tutor;
    int choice;
    while (true)
    {
        clearScreen();
        tutorL.Display(tutorL.head, 1, isAdmin);
        if (isAdmin)
        {
            choice = getIntInput("Do you want to modify this record (1 = Yes / 0 = No): ");
        }
        else
        {
            choice = getIntInput("Do you want to rate this tutor (1 = Yes / 0 = No): ");
        }
        if (!isChoiceInMenuRange(choice, 1))
        {
            continue;
        }
        if (choice == 0)
        {
            return;
        }
        if (!isAdmin && choice == 1)
        {
            while (true)
            {
                float rate = getFloatInput("Please give your rate (1.0 ~ 5.0): ");
                if (!isRatingRateRangeValid(rate))
                {
                    continue;
                }
                size_t countRate = tutor->countRate;
                float tutorRate = tutor->rating;
                tutorRate *= countRate;
                tutorRate += rate;
                countRate++;
                tutorRate /= countRate;
                tutor->rating = tutorRate;
                std::cout << "Thank you for your rating\n";
                Enter();
                return;
            }
        }
        std::cout << "Modify:\n";
        std::cout << "1. Phone Number\n";
        std::cout << "2. Address\n";
        std::cout << "3. Termination Date\n";
        std::cout << "0. Back\n";
        while (true)
        {
            int option = getIntInput("Choose what to be modified: ");
            if (!isChoiceInMenuRange(option, 3))
                continue;
            if (option == 1)
            {
                string phone;
                while (true)
                {
                    std::cout << "New phone number: ";
                    std::getline(std::cin, phone);
                    if (isPhoneFormatValid(phone))
                    {
                        tutor->phone = phone;
                        break;
                    }
                }
            }
            else if (option == 2)
            {
                std::cout << "New Address: ";
                std::getline(std::cin, tutor->address);
            }
            else if (option == 3)
            {
                string date;
                while (true)
                {
                    std::cout << "Terminate date: ";
                    std::getline(std::cin, date);
                    if (isDateValid(date))
                    {
                        tutor->terminateDate = Date(date);
                        break;
                    }
                }
            }
            break;
        }
        std::cout << "Update successful\n";
        Enter();
    }
}
