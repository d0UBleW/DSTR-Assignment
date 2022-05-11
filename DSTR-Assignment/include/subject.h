#ifndef SUBJECT_H_INCLUDED
#define SUBJECT_H_INCLUDED

#include <string>

struct Subject {
    std::string ID;
    std::string name;
    Subject();
    Subject(std::string, std::string);
    ~Subject();
};

struct SubjectNode {
    Subject *subject;
    SubjectNode *next;
    SubjectNode *prev;
    SubjectNode();
    SubjectNode(Subject *);
    ~SubjectNode();
};

struct SubjectList {
    SubjectNode *head;
    SubjectList();
    ~SubjectList();
    void Add(Subject *);
    void Delete();
    void Display();
    bool Empty();
};

Subject *getSubjectByID(SubjectList &, std::string);

#endif
