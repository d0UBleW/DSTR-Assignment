template <typename T>
BinaryTree<T>::BinaryTree() {

}

template <typename T>
BinaryTree<T>::~BinaryTree() {

}

template <typename T>
List<T>* BinaryTree<T>::BTToLL() {
    /*
     * Create a stack which stores a pointer to Node<T> (Node<T>*)
     */
    MyStack<Node<T>*>* S = new MyStack<Node<T>*>();
    Node<T>* currNode = this->root;
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
