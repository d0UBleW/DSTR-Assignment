#include <iostream>

#include "student.h"

Student::Student()
{
}

Student::Student(std::string paramUsername, std::string paramPassword)
{
    username = paramUsername;
    password = paramPassword;
}

Student::~Student()
{
}

StudentNode::StudentNode()
{
    student = nullptr;
    next = nullptr;
    prev = nullptr;
}

StudentNode::StudentNode(Student *paramStudent)
{
    student = paramStudent;
    next = nullptr;
    prev = nullptr;
}

StudentNode::~StudentNode()
{
    delete student;
}

StudentList::StudentList()
{
    head = nullptr;
}

StudentList::~StudentList()
{
    while (head != nullptr)
    {
        Delete();
    }
}

void StudentList::Add(Student *student)
{
    StudentNode *newNode = new StudentNode(student);
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

void StudentList::Delete()
{
    if (Empty())
        return;

    StudentNode *temp = head;
    if (head->next != nullptr)
    {
        head = head->next;
        head->prev = nullptr;
    }
    else
    {
        head = nullptr;
    }
    delete temp;
}

void StudentList::Display()
{
    StudentNode *ptr = head;
    while (ptr != nullptr)
    {
        std::cout << ptr->student->username << '\n';
        ptr = ptr->next;
    }
}

bool StudentList::Empty()
{
    return head == nullptr;
}

Student *getStudentByUsername(StudentList &studentL, std::string username)
{
    StudentNode *ptr = studentL.head;
    while (ptr != nullptr)
    {
        Student adm = *(ptr->student);
        if (username == adm.username)
        {
            return ptr->student;
        }
        ptr = ptr->next;
    }
    return nullptr;
}
