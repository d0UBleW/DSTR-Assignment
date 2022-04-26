#include <iostream>

#include "sort.h"
#include "tutor.h"
#include "tutor_list.h"

int CompareNumeric(int a, int b) {
    if (a > b)
        return 1;
    else if (a < b)
        return -1;
    else
        return 0;
}

int CompareFloat(float a, float b) {
    if (a > b)
        return 1;
    else if (a < b)
        return -1;
    else
        return 0;
}

int CompareString(std::string s1, std::string s2) {
    size_t shortest = std::min<size_t>(s1.length(), s2.length());
    for (size_t i = 0; i < shortest; i++) {
        if (s1[i] < s2[i]) return -1;
        if (s1[i] > s2[i]) return 1;
    }
    return (int) s1.length() - (int) s2.length();
}

int CompareTutorID(Tutor *t1, Tutor *t2) {
    int result = CompareString(t1->ID, t2->ID);
    return result;
}

int CompareTutorPay(Tutor *t1, Tutor *t2) {
    int result = CompareFloat(t1->payRate, t2->payRate);
    return result;
}

int CompareTutorRating(Tutor *t1, Tutor *t2) {
    int result = CompareFloat(t1->rating, t2->rating);
    return result;
}

void SortMenu(TutorList &lst) {
    std::cout << "Sort by:" << '\n';
    std::cout << "1. ID\n";
    std::cout << "2. Pay Rate\n";
    std::cout << "3. Rating\n";
    int opt = 0;
    bool valid = false;
    int (*CompareFn)(Tutor *, Tutor *) = nullptr;
    while (!valid) {
        std::cout << "Option: ";
        std::cin >> opt;
        switch (opt) {
        case 1:
            CompareFn = &CompareTutorID;
            valid = true;
            break;
        case 2:
            CompareFn = &CompareTutorPay;
            valid = true;
            break;
        case 3:
            CompareFn = &CompareTutorRating;
            valid = true;
            break;
        default:
            std::cout << "Invalid option\n";
            continue;
        }
        int orderChoice = 0;
        std::cout << "Order: 1. Asc\t2.Desc\n";
        std::cin >> orderChoice;
        char order = 0;
        switch (orderChoice) {
        case 1:
            order = 'a';
            break;
        case 2:
            order = 'd';
            break;
        default:
            order = 'a';
        }
        lst.Sort((*CompareFn), order);
    }
}
