#include <iostream>

#include "binary_tree.h"
#include "my_stack.h"
#include "tutor.h"
#include "tutor_list.h"
#include "tutor_node.h"

TutorList::TutorList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
    copy = false;
}

TutorList::~TutorList()
{
    while (head != nullptr)
    {
        TutorNode *temp = head;
        head = head->next;
        if (!copy)
            delete temp->tutor;
        delete temp;
    }
}

void TutorList::AddToLast(Tutor *tutor)
{
    TutorNode *newNode = new TutorNode(tutor);
    size++;
    if (Empty())
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void TutorList::AddToFront(Tutor *tutor)
{
    TutorNode *newNode = new TutorNode(tutor);
    size++;
    if (Empty())
    {
        head = newNode;
        return;
    }

    newNode->next = head;
    newNode->prev = head->prev;
    head->prev = newNode;
    head = newNode;
}

void TutorList::Display(TutorNode *ptr, size_t count, bool isAdmin)
{
    for (size_t i = 0; i < count && ptr != nullptr; i++, ptr = ptr->next)
    {
        Tutor *tutor = ptr->tutor;
        std::cout << "Tutor ID: " << tutor->ID << '\n';
        std::cout << "Tutor Name: " << tutor->name << '\n';
        // if its not admin then only show
        // tutor id and name
        if (!isAdmin)
        {
            std::cout << '\n';
            continue;
        }
        std::cout << "Pay Rate: " << tutor->payRate << '\n';
        std::cout << "Rating: " << tutor->rating << '\n';
        std::cout << "Phone Number: " << tutor->phone << '\n';
        std::cout << "Address: " << tutor->address << '\n';
        std::cout << "Joined Date: " << tutor->joinDate.ToString() << '\n';
        std::cout << "Termination Date: " << tutor->terminateDate.ToString() << '\n';
        std::cout << "Center ID: " << tutor->center->ID << '\n';
        std::cout << "Center Name: " << tutor->center->name << '\n';
        std::cout << "Subject ID: " << tutor->subject->ID << '\n';
        std::cout << "Subject Name: " << tutor->subject->name << '\n';
        std::cout << '\n';
    }
}

void TutorList::DeleteBeginning()
{
    if (Empty())
        return;

    TutorNode *nodePtr = head;
    if (head->next != nullptr)
    {
        head = head->next;
        head->prev = nullptr;
    }
    else
    {
        head = nullptr;
    }
    delete nodePtr;
}

void TutorList::DeleteNode(TutorNode *tutorNode)
{
    if (tutorNode == nullptr)
        return;
    if (tutorNode == head)
    {
        DeleteBeginning();
        return;
    }

    if (tutorNode == tail)
    {
        tail = tutorNode->prev;
        tail->next = nullptr;
        delete tutorNode;
        return;
    }

    tutorNode->prev->next = tutorNode->next;
    tutorNode->next->prev = tutorNode->prev;
    delete tutorNode;
}

TutorList TutorList::Sort(int (*CompareFn)(Tutor *, Tutor *), char order)
{
    BinaryTree bt(*this, (*CompareFn), order);
    TutorList sortedLL = bt.ToLinkedList();
    return sortedLL;
}

bool TutorList::Empty()
{
    return head == nullptr;
}
