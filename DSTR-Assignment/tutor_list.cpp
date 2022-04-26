#include <iostream>

#include "binary_tree.h"
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

void TutorList::Display()
{
    puts("Tutor Display");
    TutorNode *nodePtr = head;
    while (nodePtr != nullptr)
    {
        std::cout << "Addr: " << nodePtr->tutor << '\n';
        std::cout << "Name: " << nodePtr->tutor->name << '\n';
        std::cout << "ID: " << nodePtr->tutor->ID << '\n';
        std::cout << "Pay: " << nodePtr->tutor->payRate << '\n';
        std::cout << "Rating: " << nodePtr->tutor->rating << '\n';
        puts("");
        nodePtr = nodePtr->next;
    }
    puts("");
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
