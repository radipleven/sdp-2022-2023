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
        LinkedList();
        ~LinkedList();
        LinkedList(const LinkedList<T>& other);
        bool operator==(const LinkedList<T>& other) const;
        LinkedList<T>& operator=(const LinkedList<T>& other);
        void insertAtPos(T a, std::size_t pos = 0);
        void reverse();
        void removeAtPos(std::size_t pos);
        const T& getElementAtPos(unsigned pos);
        T& top() const;
        void sort();
};
