template <typename T>
MyStack<T>::MyStack() {
    ll = new List<T>();
    size = 0;
}

template <typename T>
MyStack<T>::~MyStack() {
}

template <typename T>
void MyStack<T>::Push(T data) {
    /* Node<T>* newNode = new Node<T>(paramN); */
    ll->InsertBeginning(data);
    size++;
}

template <typename T>
T MyStack<T>::Top() {
    return ll->head->x;
}

template <typename T>
void MyStack<T>::Pop() {
    ll->DeleteBeginning();
    size--;
}

template <typename T>
void MyStack<T>::Display() {
    ll->Display();
}

template <typename T>
bool MyStack<T>::Empty() {
    return (size > 0) ? false: true;
}
