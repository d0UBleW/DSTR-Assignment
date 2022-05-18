#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <string>

using namespace std;

struct Student {
  std::string username;
  std::string password;
  Student();
  Student(std::string paramUsername, std::string paramPassword);
  ~Student();
};

struct StudentNode {
  Student *student;
  StudentNode *next;
  StudentNode *prev;
  StudentNode();
  StudentNode(Student *);
  ~StudentNode();
};

struct StudentList {
  StudentNode *head;
  StudentList();
  ~StudentList();
  void Add(Student *);
  void Delete();
  void Display();
  bool Empty();
};

Student *getStudentByUsername(StudentList &studentL, std::string username);

#endif
