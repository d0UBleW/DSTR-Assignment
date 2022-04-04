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
List<T>* BTToLL(BinaryTree<T>* bt);

template <typename T>
BinaryTree<T>* LLToBT(List<T>* ll, int (*CompareFn)(int, int), char order);

int CompareNumeric(int, int);

template <typename T>
struct Node {
    T x;
    Node* next;
    Node* prev;
    Node() {}
    Node(T paramX) {
        x = paramX;
        next = NULL;
        prev = NULL;
    }
};

template <typename T>
struct List {
    Node<T>* head;
    size_t size;
    List() {}
    ~List() {
        while (head != NULL) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void InsertBeginning(T data) {
        Node<T>* n = new Node<T>(data);
        if (head == NULL) {
            head = n;
            return;
        }
        n->next = head;
        n->prev = head->prev;
        head->prev = n;
        head = n;
    }
    void Add(T data) {
        Node<T>* n = new Node<T>(data);
        size++;
        if (head == NULL) {
            head = n;
            return;
        }

        Node<T>* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = n;
    }
    void Display() {
        Node<T>* ptr = head;
        while (ptr != NULL) {
            std::cout << ptr->x << ' ';
            ptr = ptr->next;
        }
        puts("");
    }
    void DeleteBeginning() {
        Node<T>* ptr = head;
        if (head->next != NULL) {
            head = head->next;
            head->prev = NULL;
        }
        delete ptr;
    }
    List<T>* Sort(int (*CompareFn)(int, int), char order) {
        BinaryTree<T>* bt = LLToBT<T>(this, (*CompareFn), order);
        List<T>* sortedLL = BTToLL<T>(bt);
        delete bt;
        return sortedLL;
    }
};

template <typename T>
Node<T>* CreateNode(T x) {
    Node<T>* n = new Node<T>(x);
    return n;
}

template <typename T>
struct MyStack {
    List<T>* ll;
    size_t size;
    MyStack() {
        ll = new List<T>();
        size = 0;
    }
    ~MyStack() {
    }
    void Push(T data) {
        /* Node<T>* newNode = new Node<T>(paramN); */
        ll->InsertBeginning(data);
        size++;
    }
    T Top() {
        return ll->head->x;
    }
    void Pop() {
        ll->DeleteBeginning();
        size--;
    }
    void Display() {
        ll->Display();
    }
    bool Empty() {
        return (size > 0) ? false: true;
    }
};

template <typename T>
struct BinaryTree {
    Node<T>* root;
    BinaryTree() {}
    ~BinaryTree() {}
};

int CompareNumeric(int a, int b) {
    if (a > b) return 1;
    else if (a < b) return -1;
    else return 0;
}

template <typename T>
BinaryTree<T>* LLToBT(List<T>* ll, int (*CompareFn)(int, int), char order) {
    if (ll == NULL) return NULL;

    Node<T>* ptr = ll->head;

    BinaryTree<T>* bt = new BinaryTree<T>();
    bt->root = new Node<T>(*ptr);
    bt->root->prev = NULL;
    bt->root->next = NULL;
    ptr = ptr->next;

    while (ptr != NULL) {
        Node<T>* temp = bt->root;
        int result;
        Node<T>* prev;
        while (temp != NULL) {
            prev = temp;
            result = (*CompareFn)(ptr->x, temp->x);
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
                prev->next = new Node<T>(*ptr);
                prev->next->next = NULL;
                prev->next->prev = NULL;
            }
            else {
                prev->prev = new Node<T>(*ptr);
                prev->prev->next = NULL;
                prev->prev->prev = NULL;
            }
        }
        else {
            if (result > 0) {
                prev->prev = new Node<T>(*ptr);
                prev->prev->next = NULL;
                prev->prev->prev = NULL;
            }
            else {
                prev->next = new Node<T>(*ptr);
                prev->next->next = NULL;
                prev->next->prev = NULL;
            }
        }
        ptr = ptr->next;
    }
    return bt;
}

template <typename T>
List<T>* BTToLL(BinaryTree<T>* bt) {
    /*
     * Create a stack which stores a pointer to Node<T> (Node<T>*)
     */
    MyStack<Node<T>*>* S = new MyStack<Node<T>*>();
    Node<T>* currNode = bt->root;
    List<T>* ll = new List<T>();
    Node<T>* ptr = ll->head;

    while (!S->Empty() || currNode != NULL) {
        if (currNode != NULL) {
            S->Push(currNode);
            currNode = currNode->prev;
        }
        else {
            currNode = S->Top();
            if (ptr == NULL) {
                ll->head = new Node<T>(*currNode);
                ptr = ll->head;
            }
            else {
                ptr->next = new Node<T>(*currNode);
                ptr = ptr->next;
            }
            S->Pop();
            Node<T>* tmp = currNode;
            currNode = currNode->next;
            delete tmp;
        }
    }
    ptr->next = NULL;
    delete S;
    return ll;
}

int main() {
    List<int>* a = new List<int>();
    a->InsertBeginning(1);
    a->Add(5);
    a->Add(4);
    a->Add(3);
    a->Add(2);
    a->Add(2);
    a->Add(2);
    a->Add(2);
    a->Add(2);
    a->Add(2);
    a->Add(2);
    a->Add(2);
    a->Add(2);
    a->Add(2);
    a->InsertBeginning(6);
    a->InsertBeginning(1);
    a->DeleteBeginning();
    a->Display();
    /* BinaryTree<int>* bt = LLToBT<int>(a, &CompareNumeric, 'a'); */
    /* std::cout << bt->root->x << '\n'; */
    /* std::cout << bt->root->prev->x << '\n'; */
    List<int>* sortedLL = a->Sort(&CompareNumeric, 'a');
    sortedLL->Display();
    a->Display();
    delete a;
    delete sortedLL;

    /* MyStack<int>* s = new MyStack<int>(); */
    /* s->Push(CreateNode(5)); */
}
