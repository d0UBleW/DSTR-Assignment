#include <iostream>

#include "center.h"

Center::Center() {}

Center::Center(std::string paramID, std::string paramName) {
    ID = paramID;
    name = paramName;
}

Center::~Center() {}

CenterNode::CenterNode() {
    center = nullptr;
    next = nullptr;
    prev = nullptr;
}

CenterNode::CenterNode(Center *paramCenter) {
    center = paramCenter;
    next = nullptr;
    prev = nullptr;
}

CenterNode::~CenterNode() { delete center; }

CenterList::CenterList() { head = nullptr; }

CenterList::~CenterList() {
    while (head != nullptr) {
        Delete();
    }
}

void CenterList::Add(Center *center) {
    CenterNode *newNode = new CenterNode(center);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    newNode->next = head;
    newNode->prev = head->prev;
    head->prev = newNode;
    head = newNode;
}

void CenterList::Delete() {
    if (head == nullptr) return;

    CenterNode *temp = head;
    if (head->next != nullptr) {
        head = head->next;
        head->prev = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;
}

void CenterList::Display() {
    CenterNode *ptr = head;
    while (ptr != nullptr) {
        std::cout << ptr->center->ID << '\n';
        ptr = ptr->next;
    }
}

bool CenterList::Empty() { return (head == nullptr) ? true : false; }

Center *getCenterByID(CenterList &centerL, std::string ID) {
    CenterNode *ptr = centerL.head;
    while (ptr != nullptr) {
        Center c = *(ptr->center);
        if (ID == c.ID) {
            return ptr->center;
        }
      
        ptr = ptr->next;
    }
   
    return nullptr;
}
