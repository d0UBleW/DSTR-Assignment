#include <iostream>
#include <stack>

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
    void InsertBeginning(Node<T>* n) {
        if (head == NULL) {
            head = n;
            return;
        }
        n->next = head;
        n->prev = head->prev;
        head->prev = n;
        head = n;
    }
    void Add(Node<T>* n) {
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
    static List<T>* Sort(List<T>* ll, int (*CompareFn)(int, int), char order) {
        BinaryTree<T>* bt = LLToBT<T>(ll, (*CompareFn), order);
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
    void Push(Node<T>* paramN) {
        ll->InsertBeginning(paramN);
        size++;
    }
    Node<T>* Top() {
        return ll->head;
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
     * Since MyStack is made up of a linked list and we want the linked list
     * to be made up of pointer to Node<T>, then the element of the linked list
     * has the data type of Node<Node<T>*>
     * Create a stack which stores a Node whose data is a pointer to Node<T>
     * (Node<T>*)
     */
    MyStack<Node<T>*>* S = new MyStack<Node<T>*>();
    /* std::stack<Node<T>*> s; */
    Node<T>* currNode = bt->root;
    List<T>* ll = new List<T>();
    Node<T>* ptr = ll->head;

    while (!S->Empty() || currNode != NULL) {
        if (currNode != NULL) {
            /* s.push(currNode); */
            Node<Node<T>*>* ptrToNodePtr = new Node<Node<T>*>();
            ptrToNodePtr->x = currNode;
            S->Push(ptrToNodePtr);
            /* S->Push(new Node<Node<T>*>(&*currNode)); */
            currNode = currNode->prev;
        }
        else {
            /* currNode = s.top(); */
            currNode = S->Top()->x;
            if (ptr == NULL) {
                ll->head = currNode;
                ptr = ll->head;
            }
            else {
                ptr->next = currNode;
                ptr = ptr->next;
            }
            /* s.pop(); */
            S->Pop();
            currNode = currNode->next;
        }
    }
    ptr->next = NULL;
    delete S;
    return ll;
}


int main() {
    List<int>* a = new List<int>();
    a->InsertBeginning(CreateNode(1));
    a->Add(CreateNode(5));
    a->Add(CreateNode(4));
    a->Add(CreateNode(3));
    a->Add(CreateNode(2));
    a->InsertBeginning(CreateNode(6));
    a->InsertBeginning(CreateNode(1));
    a->DeleteBeginning();
    a->Display();
    /* BinaryTree<int>* bt = LLToBT<int>(a, &CompareNumeric, 'a'); */
    /* std::cout << bt->root->x << '\n'; */
    /* std::cout << bt->root->prev->x << '\n'; */
    List<int>* sortedLL = List<int>::Sort(a, &CompareNumeric, 'a');
    sortedLL->Display();
    a->Display();
    delete a;
    delete sortedLL;

    /* MyStack<int>* s = new MyStack<int>(); */
    /* s->Push(CreateNode(5)); */
}
