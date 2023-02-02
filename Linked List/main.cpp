#include "LinkedList.cpp"
#include <iostream>

int main()
{
    LinkedList<int> list;
    list.insertAtPos(5);
    list.insertAtPos(10);
    list.insertAtPos(15, 1);
    list.reverse();
    std::cout << "Element at position 0: " << list.getElementAtPos(0) << std::endl;
    std::cout << "Element at position 1: " << list.getElementAtPos(1) << std::endl;
    std::cout << "Element at position 2: " << list.getElementAtPos(2) << std::endl;
    return 0;
}
