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
        if (!copy) delete temp->tutor;
        delete temp;
    }
}

void TutorList::InsertBeginning(Tutor *tutor)
{
    TutorNode *newNode = new TutorNode(tutor);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    newNode->prev = head->prev;
    head->prev = newNode;
    head = newNode;
}

void TutorList::Add(Tutor *tutor)
{
    TutorNode *newNode = new TutorNode(tutor);
    size++;
    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    TutorNode *ptr = head;
    while (ptr->next != nullptr)
    {
        ptr = ptr->next;
    }
    newNode->prev = ptr; // kf added here
    ptr->next = newNode;
    tail = newNode;
}

void TutorList::AddToFront(Tutor *tutor)
{
    TutorNode *newNode = new TutorNode(tutor);
    size++;
    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    TutorNode *ptr = head;

    newNode->next = ptr; // kf added here
    ptr->prev = newNode;
    head = newNode;
}

void TutorList::Display(TutorNode *&ptr, size_t count, std::string nav, bool isAdmin)
{
    /**
     * Keep track of the first address of the group in case we are reaching
     * the very last group
     */
    TutorNode *temp = ptr;
    for (size_t i = 0; i < count; i++)
    {
        if (nav == "prev")
        {
            if (ptr == head) break;
            ptr = ptr->prev;
        }
        else if (nav == "next")
        {
            if (ptr == nullptr) break;
            ptr = ptr->next;
        }
    }

    /**
     * When we reach the very last group reset ptr to the first address of the
     * group, else update our first address to be the new first address of the
     * group
     */
    if (ptr == nullptr)
        ptr = temp;
    else
        temp = ptr;

    for (size_t i = 0; i < count && temp != nullptr; i++, temp = temp->next)
    {
        Tutor *tutor = temp->tutor;
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
    if (head == nullptr) return;

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

TutorList TutorList::Sort(int (*CompareFn)(Tutor *, Tutor *), char order)
{
    BinaryTree bt(*this, (*CompareFn), order);
    TutorList sortedLL = bt.ToLinkedList();
    return sortedLL;
}

bool TutorList::Empty()
{
    return (head == nullptr) ? true : false;
}
