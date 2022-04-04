template <typename T>
List<T>::List() {
    /* puts("List constructed"); */
}

template <typename T>
List<T>::~List() {
    while (head != NULL) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void List<T>::InsertBeginning(T data) {
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

template <typename T>
void List<T>::Add(T data) {
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

template <typename T>
void List<T>::Display() {
    Node<T>* ptr = head;
    while (ptr != NULL) {
        std::cout << ptr->x << ' ';
        ptr = ptr->next;
    }
    puts("");
}

template <typename T>
void List<T>::DeleteBeginning() {
    Node<T>* ptr = head;
    if (head->next != NULL) {
        head = head->next;
        head->prev = NULL;
    }
    delete ptr;
}

template <typename T>
template <typename U>
List<T>* List<T>::Sort(int (*CompareFn)(U, U), char order) {
    /* BinaryTree<T>* bt = LLToBT<T>(this, (*CompareFn), order); */
    BinaryTree<T>* bt = this->LLToBT<U>((*CompareFn), order);
    /* List<T>* sortedLL = BTToLL<T>(bt); */
    List<T>* sortedLL = bt->BTToLL();
    delete bt;
    return sortedLL;
}

template <typename T>
template <typename U>
BinaryTree<T>* List<T>::LLToBT(int (*CompareFn)(U, U), char order) {
    /* if (this == NULL) return NULL; */

    Node<T>* ptr = this->head;

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
