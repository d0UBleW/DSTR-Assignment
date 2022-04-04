#ifndef DATA_TYPE_H_INCLUDED
#define DATA_TYPE_H_INCLUDED

#include <iostream>

template <typename T>
struct Node;

template <typename T>
struct List;

template <typename T>
struct BinaryTree;

template <typename T>
struct MyStack;

template <typename T>
struct Node {
    T x;
    Node* next;
    Node* prev;
    Node();
    Node(T paramX);
    ~Node();
};


template <typename T>
struct List {
    Node<T>* head;
    size_t size;
    List();
    ~List();
    void InsertBeginning(T n);
    void Add(T n);
    void Display();
    void DeleteBeginning();
    BinaryTree<T>* LLToBT(char order, std::string data);
    List<T>* Sort(char order, std::string data);
    /* template <typename U> */
    /* BinaryTree<T>* LLToBT(int (*CompareFn)(U, U), char order); */
    /* template <typename U> */
    /* BinaryTree<T>* LLToBT(int (*CompareFn)(U, U), char order, std::string data); */
    /* template <typename U> */
    /* List<T>* Sort(int (*CompareFn)(U, U), char order); */
    /* template <typename U> */
    /* List<T>* Sort(int (*CompareFn)(U, U), char order, std::string data); */
};

template <typename T>
struct MyStack {
    List<T>* ll;
    size_t size;
    MyStack();
    ~MyStack();
    void Push(T data);
    T Top();
    void Pop();
    void Display();
    bool Empty();
};

template <typename T>
struct BinaryTree {
    Node<T>* root;
    BinaryTree();
    ~BinaryTree();
    List<T>* BTToLL();
};

#include "node.hxx"
#include "list.hxx"
#include "stack.hxx"
#include "binary_tree.hxx"

#endif
