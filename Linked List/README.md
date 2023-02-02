# Linked List
## Features

* LinkedList class has the following functions:
    * insertAtPos(T a, std::size_t pos = 0): Inserts an element at a given position (default is the front of the list).
    * reverse(): Reverses the order of the elements in the linked list.
    * removeAtPos(std::size_t pos): Removes an element at a given position.
    * getElementAtPos(unsigned pos): Returns the element at a given position.
    * getSize(): Returns the number of elements in the linked list.
    * sort(): Sorts the elements in the linked list based on the operator <. //TODO
    
* Class also has the following operators:
    * operator==(const LinkedList<T>& other)
    * operator=(const LinkedList<T>& other)
    * Iterator class to traverse the linked list. //TODO
    * Exception handling using out_of_range.

## Usage

```
#include "LinkedList.h"
#include <iostream>

int main() {
    LinkedList<int> ll;
    ll.insertAtPos(1);
    ll.insertAtPos(2, 1);
    std::cout << "List size: " << ll.getSize() << '\n';
    std::cout << "Element at position 0: " << ll.getElementAtPos(0) << '\n';
    return 0;
}
```
## Note
More functions need to be implemented. This is not a finished version.
