#include <iostream>

#include "add.h"
#include "admin_menu.h"
#include "authentication.h"
#include "delete.h"
#include "display.h"
#include "file2struct.h"
#include "modify.h"
#include "search.h"
#include "sort.h"
#include "student_menu.h"
#include "tutor.h"
#include "tutor_list.h"
#include "validation.h"

using namespace std;

void startMenu(TutorList &tutorL) {
  while (true) {
    clearScreen();
    cout << "Welcome to eXcel Tuition Centre" << endl;
    cout << "Who are you?" << endl;
    cout << "1) Admin" << endl;
    cout << "2) Student" << endl;
    cout << "3) Student Register" << endl;
    cout << "0) Exit" << endl;
    string sentence = "Enter your choice: ";
    int choice = getIntInput(sentence);
    if (!isChoiceInMenuRange(choice, 3))
      continue;
    switch (choice) {
    case 0:
      cout << "Thank you for using this system" << endl;
      return;

    case 1:
      if (adminLogin()) {
        adminMainMenu(tutorL);
      } else {
        continue;
      }
      break;
    case 2:
      if (studentLogin()) {
        studentRatingMenu(tutorL);
      } else {
        continue;
      }
      break;
    case 3:
      registerStudent();
      break;
    }
  }
}

void modifyMenu(TutorList &tutorL) {
  while (true) {
    clearScreen();
    cout << "You are About to Modify Tutor Record, Please Becareful!\n";
    cout << "1)Modify by Tutor ID" << endl;
    cout << "0)Return to Previous Page" << endl;
    string sentence = "Enter your choice: ";
    int choice = getIntInput(sentence);
    if (!isChoiceInMenuRange(choice, 1))
      continue;
    Tutor query;
    int (*CompareFn)(Tutor *, Tutor *) = nullptr;
    if (choice == 1) {
      std::cout << "Enter Tutor ID (TXX): ";
      std::getline(std::cin, query.ID);
      CompareFn = &CompareTutorID;
      TutorList result = searchTutor(tutorL, (*CompareFn), &query);
      if (result.head != nullptr) {
        modifyTutor(result, true);
        tutorToFile(tutorL, TUTOR_FILE);
      } else {
        cout << "No Tutor Found please try another Tutor ID" << endl;
        Enter();
      }
    } else if (choice == 0) {
      return;
    }
  }
}
void adminMainMenu(TutorList &tutorL) {
  while (true) {
    clearScreen();
    cout << "Welcome back admin, please select a function" << endl;
    cout << "1) Add Tutor" << endl;
    cout << "2) Display Tutor" << endl;
    cout << "3) Sort Tutor" << endl;
    cout << "4) Search Tutor" << endl;
    cout << "5) Modify Tutor" << endl;
    cout << "6) Termination or Delete Tutor" << endl;
    cout << "7) Register New Admin" << endl;
    cout << "0) Logout" << endl;
    string sentence = "Enter your choice: ";
    int choice = getIntInput(sentence);
    if (!isChoiceInMenuRange(choice, 7))
      continue;
    switch (choice) {
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

void addMenu(TutorList &tutorL) {

  while (true) {
    clearScreen();
    Tutor *tutor;
    cout << "Where you want to add?" << endl;
    cout << "1) Add to First" << endl;
    cout << "2) Add to Last" << endl;
    cout << "0) Previous Page" << endl;
    string sentence = "Enter your choice: ";
    int choice = getIntInput(sentence);
    if (!isChoiceInMenuRange(choice, 2))
      continue;
    // code here
    switch (choice) {
    case 0:
      return;

    case 1:
      tutor = addingInterface(tutorL);
      tutorL.AddToFront(tutor);
      tutorToFile(tutorL, TUTOR_FILE);
      cout << "Succesfully added to front" << endl;
      Enter();
      break;
    case 2:
      tutor = addingInterface(tutorL);
      tutorL.AddToLast(tutor);
      tutorToFile(tutorL, TUTOR_FILE);
      cout << "Succesfully added to back" << endl;
      Enter();
      break;
    }
  }
}

void sortMenu(TutorList &tutorL) {
  int choice;
  while (true) {
    clearScreen();
    cout << "How do you want to sort?" << endl;
    cout << "1) Sort by Tutors ID" << endl;
    cout << "2) Sort by Pay Rate " << endl;
    cout << "3) Sort by Overall Performance" << endl;
    cout << "0) Previous Page" << endl;
    string sentence = "Enter your choice: ";
    choice = getIntInput(sentence);
    if (!isChoiceInMenuRange(choice, 3))
      continue;

    int (*CompareFn)(Tutor *, Tutor *) = nullptr;
    switch (choice) {
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
    cout << "Sort in:\n";
    cout << "1) Ascending order\n";
    cout << "2) Descending order\n";
    cout << "0) Back\n";
    while (true) {
      int option = getIntInput("Enter your choice: ");
      if (!isChoiceInMenuRange(option, 2))
        continue;
      char order = ' ';
      if (option == 0) {
        break;
      } else if (option == 1) {
        order = 'a';
      } else if (option == 2) {
        order = 'd';
      }
      TutorList sortedTutorL = tutorL.Sort((*CompareFn), order);
      DisplayTutor(sortedTutorL);
      break;
    }
  }
}

void searchMenu(TutorList &tutorL) {
  while (true) {
    clearScreen();
    cout << "How do you want to search?" << endl;
    cout << "1) Search by Tutor ID" << endl;
    cout << "2) Search by overall performance" << endl;
    cout << "0) Previous Page" << endl;
    int choice = getIntInput("Enter your choice: ");
    if (!isChoiceInMenuRange(choice, 2))
      continue;
    Tutor query;
    int (*CompareFn)(Tutor *, Tutor *) = nullptr;
    if (choice == 0) {
      break;
    } else if (choice == 1) {
      std::cout << "Enter Tutor ID (TXX): ";
      std::getline(std::cin, query.ID);
      CompareFn = &CompareTutorID;
    } else if (choice == 2) {
      query.rating = getFloatInput("Enter Tutor rating: ");
      CompareFn = &CompareTutorRating;
    }
    TutorList result = searchTutor(tutorL, (*CompareFn), &query);
    DisplayTutor(result);
  }
}

void deleteMenu(TutorList &tutorL) {
  while (true) {
    clearScreen();
    cout << "Which function you need?" << endl;
    cout << "1) Terminate all expired tutors" << endl;
    cout << "2) Delete specific tutor data" << endl;
    cout << "0) Previous Page" << endl;
    string sentence = "Enter your choice: ";
    int choice = getIntInput(sentence);
    if (!isChoiceInMenuRange(choice, 2))
      continue;
    if (choice == 1) {
      DeleteTerminatedTutor(tutorL);
      tutorToFile(tutorL, TUTOR_FILE);
    }

    else if (choice == 2) {
      string ID;
      std::cout << "Enter Tutor ID (TXX): ";
      std::getline(std::cin, ID);
      DeleteTutor(tutorL, ID);
      tutorToFile(tutorL, TUTOR_FILE);
    } else if (choice == 0) {
      return;
    }
  }
}
