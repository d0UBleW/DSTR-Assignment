#include <iostream>

#include "center.h"
#include "display.h"
#include "subject.h"
#include "tutor.h"
#include "tutor_list.h"
#include "validation.h"

using namespace std;

Tutor *addingInterface(TutorList &tutorL)
{
    string date;
    Tutor *tutor = new Tutor();

    cout << "Please enter information below" << endl;
    while (true)
    {

        cout << "Tutor ID (TXX): ";
        getline(cin, tutor->ID);
        if (!isTutorIDFormatCorrect(tutor->ID))
        {
            continue;
        }
        if (isTutorIDExisted(tutorL, tutor->ID))
        {
            continue;
        }
        break;
    }

    cout << "Tutor Name: ";

    // use getline to get name with spaces
    getline(cin, tutor->name);

    while (true)
    {
        string setence = "Pay Rate (40 ~ 80): ";
        tutor->payRate = getFloatInput(setence);
        if (!isPayRateRangeValid(tutor->payRate))
        {
            continue;
        }
        break;
    }

    tutor->rating = 0;
    tutor->countRate = 0;

    while (true)
    {
        cout << "Phone Number(10~11 digits): ";
        getline(cin, tutor->phone);

        if (!isPhoneFormatValid(tutor->phone))
        {
            continue;
        }
        break;
    }

    cout << "Address: ";
    getline(cin, tutor->address);

    while (true)
    {

        cout << "Join Date (dd/MM/yyyy): ";
        getline(cin, date);

        if (!isDateValid(date))
        {
            continue;
        }
        tutor->joinDate = date;
        break;
    }
    tutor->terminateDate = Date("-");

    while (true)
    {
        string ID;
        cout << "Please choose Center ID from list below" << endl;
        DisplayCenter();
        cout << "Center ID: ";
        getline(cin, ID);
        tutor->center = getCenterByID(_CENTER, ID);
        if (!(isCenterExisted(tutor->center)))
        {
            continue;
        }
        break;
    }

    while (true)
    {
        string ID;
        cout << "Please choose Subject ID from list below " << endl;
        DisplaySubject();
        cout << "Subject ID: ";
        getline(cin, ID);
        tutor->subject = getSubjectByID(_SUBJECT, ID);
        if (!(isSubjectExisted(tutor->subject)))
        {
            continue;
        }
        break;
    }

    return tutor;
}
