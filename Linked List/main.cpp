#include "LinkedList.cpp"
#include <iostream>

int main() {
    LinkedList<int> list;
    list.insertAtPos(10);
    list.insertAtPos(30);
    list.insertAtPos(20);
    list.insertAtPos(40);
    list.sort();
    for (std::size_t i = 0; i < list.getSize(); i++) {
        std::cout << list.getElementAtPos(i) << " ";
    }
    std::cout << std::endl;
    return 0;
}
