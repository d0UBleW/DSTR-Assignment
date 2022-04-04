#include <iostream>
#include "data_type.h"
#include "sort.h"

using std::string;

struct Tutor {
    string name;
    string ID;
    float payRate;
    float rating;
    Tutor() {}
    Tutor(string paramName, string paramID, float paramPayRate, float paramRating) {
        name = paramName;
        ID = paramID;
        payRate = paramPayRate;
        rating = paramRating;
    }
    ~Tutor() {}
};

template <>
List<Tutor*>::List() {
}

template <>
List<Tutor*>::~List() {
    while (head != NULL) {
        Node<Tutor*>* temp = head;
        head = head->next;
        delete temp->x;
        delete temp;
    }
}

template <>
void List<Tutor*>::InsertBeginning(Tutor* data) {
    Node<Tutor*>* n = new Node<Tutor*>(data);
    if (head == NULL) {
        head = n;
        return;
    }
    n->next = head;
    n->prev = head->prev;
    head->prev = n;
    head = n;
}

template <>
void List<Tutor*>::Add(Tutor* data) {
    Node<Tutor*>* n = new Node<Tutor*>(data);
    size++;
    if (head == NULL) {
        head = n;
        return;
    }

    Node<Tutor*>* ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = n;
}

template <>
void List<Tutor*>::DeleteBeginning() {
    Node<Tutor*>* ptr = head;
    if (head->next != NULL) {
        head = head->next;
        head->prev = NULL;
    }
    delete ptr;
}


template<> void List<Tutor*>::Display() {
    puts("Tutor Display");
    Node<Tutor*>* ptr = head;
    while (ptr != NULL) {
        std::cout << "Name: " << ptr->x->name << '\n';
        std::cout << "ID: " << ptr->x->ID << '\n';
        std::cout << "Pay: " << ptr->x->payRate << '\n';
        std::cout << "Rating: " << ptr->x->rating << '\n';
        puts("");
        ptr = ptr->next;
    }
    puts("");
}

template<>
BinaryTree<Tutor*>* List<Tutor*>::LLToBT(char order, string data) {
    /* if (this == NULL) return NULL; */

    Node<Tutor*>* ptr = this->head;

    BinaryTree<Tutor*>* bt = new BinaryTree<Tutor*>();
    bt->root = new Node<Tutor*>(*ptr);
    bt->root->prev = NULL;
    bt->root->next = NULL;
    ptr = ptr->next;

    while (ptr != NULL) {
        Node<Tutor*>* temp = bt->root;
        int result;
        Node<Tutor*>* prev;
        while (temp != NULL) {
            prev = temp;
            Tutor* listData = ptr->x;
            Tutor* binaryData = temp->x;
            if (data == "ID")
                result = CompareString(listData->ID, binaryData->ID);
            else if (data == "pay")
                result = CompareFloat(listData->payRate, binaryData->payRate);
            else if (data == "rating")
                result = CompareFloat(listData->rating, binaryData->rating);
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

        if (order == 'a') {
            if (result > 0) {
                prev->next = new Node<Tutor*>(*ptr);
                prev->next->next = NULL;
                prev->next->prev = NULL;
            }
            else {
                prev->prev = new Node<Tutor*>(*ptr);
                prev->prev->next = NULL;
                prev->prev->prev = NULL;
            }
        }
        else {
            if (result > 0) {
                prev->prev = new Node<Tutor*>(*ptr);
                prev->prev->next = NULL;
                prev->prev->prev = NULL;
            }
            else {
                prev->next = new Node<Tutor*>(*ptr);
                prev->next->next = NULL;
                prev->next->prev = NULL;
            }
        }
        ptr = ptr->next;
    }
    return bt;
}

template <>
List<Tutor*>* List<Tutor*>::Sort(char order, std::string data) {
    BinaryTree<Tutor*>* bt = this->LLToBT(order, data);
    List<Tutor*>* sortedLL = bt->BTToLL();
    delete bt;
    return sortedLL;
}

Tutor* CreateTutor(string name, string ID, float payRate, float rating) {
    Tutor* newTutor = new Tutor(name, ID, payRate, rating);
    return newTutor;
}


int main() {
    List<Tutor*>* a = new List<Tutor*>();
    a->InsertBeginning(CreateTutor("andy", "T01", 90.3, 4));
    a->Add(CreateTutor("alice", "T02", 90.3, 3));
    a->InsertBeginning(CreateTutor("bob", "T03", 70, 5));
    a->Display();
    List<Tutor*>* sortedLLID = a->Sort('d', "ID");
    sortedLLID->Display();
    /* List<Tutor*>* sortedLLPay = a->Sort('a', "pay"); */
    /* sortedLLPay->Display(); */
    /* List<Tutor*>* sortedLLRate = a->Sort('a', "rating"); */
    /* sortedLLRate->Display(); */
    a->Display();
    delete a;
    delete sortedLLID;
    /* delete sortedLLPay; */
    /* delete sortedLLRate; */
    return 0;
}
