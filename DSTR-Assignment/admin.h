#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include <string>

using namespace std;

struct Admin
{
    std::string username;
    std::string password;
    Admin();
    Admin(std::string paramUsername, std::string paramPassword);
    ~Admin();
};

struct AdminNode
{
    Admin *admin;
    AdminNode *next;
    AdminNode *prev;
    AdminNode();
    AdminNode(Admin *);
    ~AdminNode();
};

struct AdminList
{
    AdminNode *head;
    AdminList();
    ~AdminList();
    void Add(Admin *);
    void Delete();
    void Display();
    bool Empty();
};

Admin *getAdminByUsername(AdminList &adminL, std::string username);

#endif
