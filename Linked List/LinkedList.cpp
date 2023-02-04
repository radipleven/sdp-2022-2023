#include "LinkedList.h"

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

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) {
    front = nullptr;
    size = 0;
    Node<T> *temp = other.front;
    while (temp != nullptr) {
        this->push_back(temp->key);
        temp = temp->next;
    }
};

template <typename T>
template <typename G>
bool LinkedList<T>::Node<G>::operator<(const Node<G>& other) const {
    return this->key < other.key;
}


template <class T>
bool LinkedList<T>::operator==(const LinkedList<T>& other) const {
    if (size != other.size) {
        return false;
    }

    Node<T> *temp1 = front, *temp2 = other.front;
    while (temp1 != nullptr) {
        if (temp1->key != temp2->key) {
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return true;
}


template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other) {
    if (*this == other) return *this;

    this->~LinkedList();

    Node<T>* traverseOther = other.front;
    while (traverseOther) {
        insertAtPos(traverseOther->key);
        traverseOther = traverseOther->next;
    }

    this->reverse();
    return *this;
}


template <class T>
void LinkedList<T>::insertAtPos(T a, std::size_t pos) {
    if (pos > size) {
        throw std::out_of_range("Error: index out of range");
    }

    Node<T> *newNode = new Node<T>(a);
    if (pos == 0) {
        newNode->next = front;
        front = newNode;
        ++size;
        return;
    }

    Node<T> *temp = front;
    for (std::size_t i = 1; i < pos; ++i) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    ++size;
}

template <typename T>
void LinkedList<T>::reverse() {
    Node<T>* frnt = this->front;
    Node<T>* nxt = nullptr;
    Node<T>* prev = nullptr;

    while (frnt) {

        nxt = frnt->next;
        frnt->next = prev;
        prev = frnt;
        frnt = nxt;

    }
    this->front = prev;
}

template <typename T>
void LinkedList<T>::removeAtPos(std::size_t pos) {

            if (pos > size) {
                throw std::out_of_range("Error: index out of range");
            }
            if (front == nullptr || pos >= size) {
                    return;
            }

            if (pos == 0) {
                Node<T> *temp = front;
                front = front->next;
                delete temp;
                --size;
                return;
            }

            Node<T> *temp = front;
            for (std::size_t i = 1; i < pos; ++i) {
                temp = temp->next;
            }
            Node<T> *temp2 = temp->next;
            temp->next = temp2->next;
            delete temp2;
            --size;

        }


template <typename T>
const T& LinkedList<T>::getElementAtPos(unsigned pos) {

            if (front == nullptr || pos >= size) {
                throw std::out_of_range("Error: index out of range");
            }

            Node<T> *temp = front;
            for (std::size_t i = 0; i < pos; ++i) {
                temp = temp->next;
            }

            return temp->key;
        }

template <typename T>
T& LinkedList<T>::top() const {
    if (front == nullptr) {
        throw std::runtime_error("List is empty");
    }
    return front->key;
}


template <typename T>
std::size_t LinkedList<T>::getSize() {

    
    return this->size;

}
template <typename T>
void LinkedList<T>::sort() {
    for (Node<T>* i = front; i != nullptr; i = i->next) {
        for (Node<T>* j = i->next; j != nullptr; j = j->next) {
            if (i->key < j->key) {
                T temp = i->key;
                i->key = j->key;
                j->key = temp;
            }
        }
    }
}

