template <class T>
LinkedList<T>::LinkedList() : front(nullptr), size(0) {}

template <class T>
LinkedList<T>::~LinkedList() {
    while (front != nullptr) {
        Node<T> *temp = front;
        front = front->next;
        delete temp;
    }
}
