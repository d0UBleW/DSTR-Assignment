#include <iostream>

#include "admin.h"

Admin::Admin() {}

Admin::Admin(std::string paramUsername, std::string paramPassword) {
    username = paramUsername;
    password = paramPassword;
}

Admin::~Admin() {}

AdminNode::AdminNode() {
    admin = nullptr;
    next = nullptr;
    prev = nullptr;
}

AdminNode::AdminNode(Admin *paramAdmin) {
    admin = paramAdmin;
    next = nullptr;
    prev = nullptr;
}

AdminNode::~AdminNode() {
    std::cout << admin << '\n';
    delete admin;
}

AdminList::AdminList() { head = nullptr; }

AdminList::~AdminList() {
    while (head != nullptr) {
        Delete();
    }
}

void AdminList::Add(Admin *admin) {
    AdminNode *newNode = new AdminNode(admin);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    newNode->next = head;
    newNode->prev = head->prev;
    head->prev = newNode;
    head = newNode;
}

void AdminList::Delete() {
    if (head == nullptr) return;

    AdminNode *temp = head;
    if (head->next != nullptr) {
        head = head->next;
        head->prev = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;
}

void AdminList::Display() {
    AdminNode *ptr = head;
    while (ptr != nullptr) {
        std::cout << ptr->admin->username << '\n';
        ptr = ptr->next;
    }
}

bool AdminList::Empty() { return (head == nullptr) ? true : false; }

Admin *getAdminByUsername(AdminList &adminL, std::string username) {
    AdminNode *ptr = adminL.head;
    while (ptr != nullptr) {
        Admin adm = *(ptr->admin);
        if (username == adm.username) {
            return ptr->admin;
        }
        ptr = ptr->next;
    }
    return nullptr;
}
