#include <iostream>

#include "node.h"
#include "list.h"
#include "binary_tree.h"
#include "tutor.h"

List::List() {
    /* puts("List constructed"); */
}

List::~List() {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp->x;
        delete temp;
    }
}

void List::InsertBeginning(Tutor* data) {
    Node* n = new Node(data);
    if (head == NULL) {
        head = n;
        return;
    }
    n->next = head;
    n->prev = head->prev;
    head->prev = n;
    head = n;
}

void List::Add(Tutor* data) {
    Node* n = new Node(data);
    size++;
    if (head == NULL) {
        head = n;
        return;
    }

    Node* ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = n;
}

void List::Display() {
    puts("Tutor Display");
    Node* ptr = head;
    while (ptr != NULL) {
        std::cout << "Addr: " << ptr->x << '\n';
        std::cout << "Name: " << ptr->x->name << '\n';
        std::cout << "ID: " << ptr->x->ID << '\n';
        std::cout << "Pay: " << ptr->x->payRate << '\n';
        std::cout << "Rating: " << ptr->x->rating << '\n';
        puts("");
        ptr = ptr->next;
    }
    puts("");
}

void List::DeleteBeginning() {
    Node* ptr = head;
    if (head->next != NULL) {
        head = head->next;
        head->prev = NULL;
    }
    delete ptr;
}

List* List::Sort(int (*CompareFn)(Tutor*, Tutor*), char order) {
    BinaryTree* bt = this->LLToBT((*CompareFn), order);
    List* sortedLL = bt->BTToLL();
    delete bt;
    return sortedLL;
}

BinaryTree* List::LLToBT(int (*CompareFn)(Tutor*, Tutor*), char order) {
    /* if (this == NULL) return NULL; */

    Node* ptr = this->head;

    BinaryTree* bt = new BinaryTree();
    bt->root = new Node();
    bt->root->x = new Tutor(*(ptr->x));
    bt->root->prev = NULL;
    bt->root->next = NULL;
    ptr = ptr->next;

    while (ptr != NULL) {
        Node* temp = bt->root;
        int result;
        Node* prev;
        while (temp != NULL) {
            prev = temp;
            Tutor* listData = ptr->x;
            Tutor* treeData = temp->x;
            result = (*CompareFn)(listData, treeData);
            if (order == 'a') {
                if (result > 0) {
                    temp = temp->next;
                }
                else {
                    temp = temp->prev;
                }
            }
            else {
                if (result > 0) temp = temp->prev;
                else temp = temp->next;
            }
        }

        Tutor* t = ptr->x;

        if (order == 'a') {
            if (result > 0) {
                /* prev->next = new Node<T>(*ptr); */
                prev->next = new Node();
                prev->next->x = new Tutor(*t);
                prev->next->next = NULL;
                prev->next->prev = NULL;
            }
            else {
                /* prev->prev = new Node<T>(*ptr); */
                prev->prev = new Node();
                prev->prev->x = new Tutor(*t);
                prev->prev->next = NULL;
                prev->prev->prev = NULL;
            }
        }
        else {
            if (result > 0) {
                /* prev->prev = new Node<T>(*ptr); */
                prev->prev = new Node();
                prev->prev->x = new Tutor(*t);
                prev->prev->next = NULL;
                prev->prev->prev = NULL;
            }
            else {
                /* prev->next = new Node<T>(*ptr); */
                prev->next = new Node();
                prev->next->x = new Tutor(*t);
                prev->next->next = NULL;
                prev->next->prev = NULL;
            }
        }
        ptr = ptr->next;
    }
    return bt;
}
