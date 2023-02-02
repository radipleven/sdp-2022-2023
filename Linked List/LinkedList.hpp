#include <stdexcept>
template <class T>
class LinkedList {
    private:
        template <class G>
        struct Node {
            G key;
            Node<G>* next;
            Node(G key) : key(key), next(nullptr){};
        };
        Node<T>* front;
        size_t size;
    public:
        LinkedList() : front(nullptr), size(0) {};
        ~LinkedList() {
            while (front != nullptr) {
                Node<T> *temp = front;
                front = front->next;
                delete temp;
            }
        };
        LinkedList(const LinkedList<T>& other) {
            front = nullptr;
            size = 0;
            Node<T> *temp = other.front;
            while (temp != nullptr) {
                this->push_back(temp->key);
                temp = temp->next;
            }
        };
        bool operator==(const LinkedList<T>& other) const {

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
        LinkedList<T>& operator=(const LinkedList<T>& other) {

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
        void insertAtPos(T a, std::size_t pos = 0) {

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
        void reverse() {

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
        void removeAtPos(std::size_t pos) {

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
        const T& getElementAtPos(unsigned pos) {

            if (front == nullptr || pos >= size) {
                throw std::out_of_range("Error: index out of range");
            }

            Node<T> *temp = front;
            for (std::size_t i = 0; i < pos; ++i) {
                temp = temp->next;
            }

            return temp->key;
        }
        T& top() const {
        }
		std::size_t getSize() {

            std::size_t count = 0;
            Node<T> *temp = front;
            while (temp != nullptr) {
                ++count;
                temp = temp->next;
            }
            return count;

		}
        void sort() { // sort based on operator <
        }
		struct Iterator { // can this be also class?
			Iterator() : current(nullptr) {};
			Iterator(Node<T>* _current) : current(_current){};
			friend bool operator==(const Iterator& a, const Iterator& b) {
				return a.current == b.current;
			}
			friend bool operator!=(const Iterator& a, const Iterator& b) {
				return a.current != b.current;
			}
			T& operator*() const {}
			Iterator& operator++() {}
			Iterator operator++(int) {}
		private:
			Node<T>* current;
		};
		Iterator begin() {return Iterator();}
		Iterator end() {return Iterator();} // is there a way to know this value?
};

