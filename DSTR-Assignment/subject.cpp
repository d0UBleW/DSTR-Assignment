#include <iostream>

#include "subject.h"

Subject::Subject() {}

Subject::Subject(std::string paramID, std::string paramName) {
    ID = paramID;
    name = paramName;
}

Subject::~Subject() {}

SubjectNode::SubjectNode() {
    subject = nullptr;
    next = nullptr;
    prev = nullptr;
}

SubjectNode::SubjectNode(Subject *paramSubject) {
    subject = paramSubject;
    next = nullptr;
    prev = nullptr;
}

SubjectNode::~SubjectNode() { delete subject; }

SubjectList::SubjectList() { head = nullptr; }

SubjectList::~SubjectList() {
    while (head != nullptr) {
        Delete();
    }
}

void SubjectList::Add(Subject *subject) {
    SubjectNode *newNode = new SubjectNode(subject);
    if (Empty()) {
        head = newNode;
        return;
    }
    newNode->next = head;
    newNode->prev = head->prev;
    head->prev = newNode;
    head = newNode;
}

void SubjectList::Delete() {
    if (Empty()) return;

    SubjectNode *temp = head;
    if (head->next != nullptr) {
        head = head->next;
        head->prev = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;
}

void SubjectList::Display() {
    SubjectNode *ptr = head;
    while (ptr != nullptr) {
        std::cout << ptr->subject->ID << '\n';
        ptr = ptr->next;
    }
}

bool SubjectList::Empty() { return head == nullptr; }

Subject *getSubjectByID(SubjectList &subjectL, std::string ID) {
    SubjectNode *ptr = subjectL.head;
    while (ptr != nullptr) {
        Subject s = *(ptr->subject);
        if (ID == s.ID) {
            return ptr->subject;
        }
        ptr = ptr->next;
    }
    return nullptr;
}
