#include <iostream>
#include <cstddef>
class LinkedList
{
private:
template <class g>
struct Node
{
    G key;
    Node<G>* next;
    Node (G key) : key(key), next(nullptr){};
};
Node<T>* front;
size_t size;

public:
LinkedList()
{
    
};
~LinkedList()
{
    
    while (front)
    {
        Node<T>* tempNode = front;
        std:: cout<< tempNode->key;
        front = front->next;
        delete tempNode;
        size --;
    }
    
};

LinkedList (const LinkedList<T>& other)
{

};
bool operator==(const LinkedList<T>& other)const
{

};
LinkedList<T>& operator= (const LinkedList<T>& other)
{

}
void insertAtPos(T a, std::size_t pos = 0)
{
    if (pos == 0)
    {
        Node<T>* newNode = newNode<T>(a);
        newNode->next = front;
        front = newNode;
    }else
    {
        Node<T>* traverse = front;
        while (--pos)
        {
           traverse = traverse -> next;
        }
        Node<T>* newNode = new Node<T>(a);
        newNode->next= traverse->next;
        traverse->next= newNode;
    }
    size++;
}

void removeAtPos(std:: size_t pos)
{
    Node<T>* traverse = front;
    if (pos==0)
    {
        front = front->next;
        delete traverse;
    }else 
    {
    while (--pos)
    {
        traverse = traverse->next;
    }
    Node<T>* tempNode = traverse->next;
    traverse->next= tempNode->next;
    delete tempNode;

    }
    size--;
}
const T& getElementAtPos(unsigned pos)
{

}

}


int main ()
{


    return 0;
}