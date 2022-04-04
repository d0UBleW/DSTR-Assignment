template <typename T>
Node<T>::Node() {
    /* puts("Rise"); */
}

template <typename T>
Node<T>::~Node() {
    /* puts("Fall"); */
}

template <typename T>
Node<T>::Node(T paramX) {
    this->x = paramX;
    this->next = NULL;
    this->prev = NULL;
}
