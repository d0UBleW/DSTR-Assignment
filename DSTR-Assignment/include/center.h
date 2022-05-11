#ifndef CENTER_H_INCLUDED
#define CENTER_H_INCLUDED

#include <string>

struct Center {
    std::string ID;
    std::string name;
    Center();
    Center(std::string, std::string);
    ~Center();
};

struct CenterNode {
    Center *center;
    CenterNode *next;
    CenterNode *prev;
    CenterNode();
    CenterNode(Center *);
    ~CenterNode();
};

struct CenterList {
    CenterNode *head;
    CenterList();
    ~CenterList();
    void Add(Center *);
    void Delete();
    void Display();
    bool Empty();
};

Center *getCenterByID(CenterList &, std::string);

#endif
