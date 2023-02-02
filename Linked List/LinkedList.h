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
};
