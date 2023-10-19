#include "integer_array.cpp"
#include "singly_linked_list.cpp"
#include "doubly_linked_list.cpp"
#include "heap.cpp"


void intList() {
    IntArrayList test;
    int len = 5; 

    for (int i = 0; i < len; i++) {
        test.add(i + 2);
    }

    for (int i = 0; i < len; i++) {
        cout << test.get(i) << " ";
    }
    
    cout << endl;

    test.dump();

    test.add(21);
    test.set(1, 5);
    test.removeItem(2);

    test.dump();

    test.add(32);
    test.add(52);

    test.removeAt(2);
    cout << test.contains(2);
    cout << test.indexOf(52);
    test.clear();

    test.dump();
}

void linkedList() {
    LinkedList<int> list; // Creating an instance of LinkedList

    // Adding elements to the list
    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);

    // Printing the list
    cout << "List: " << list.toString() << endl; // Output: List: [10, 20, 30, 40]


    // Adding an element at index 2
    list.add(2, 25);
    cout << "List after adding 25 at index 2: " << list.toString() << endl; // Output: List after adding 25 at index 2: [10, 20, 25, 30, 40]

    // Removing element at index 3
    int removedElement = list.removeAt(3);
    cout << "Removed element at index 3: " << removedElement << endl; // Output: Removed element at index 3: 30
    cout << "List after removal: " << list.toString() << endl;        // Output: List after removal: [10, 20, 25, 40]

    // Removing item 20
    bool itemRemoved = list.removeItem(20);
    cout << "Item 20 removed: " << (itemRemoved ? "true" : "false") << endl; // Output: Item 20 removed: true
    cout << "List after removal: " << list.toString() << endl;               // Output: List after removal: [10, 25, 40]

    // Getting element at index 1
    int element = list.get(1);
    cout << "Element at index 1: " << element << endl; // Output: Element at index 1: 25

    // Setting element at index 0 to 5
    list.set(0, 5);
    cout << "List after setting index 0 to 5: " << list.toString() << endl; // Output: List after setting index 0 to 5: [5, 25, 40]

    // Checking if list contains 25
    bool contains25 = list.contains(25);
    cout << "List contains 25: " << (contains25 ? "true" : "false") << endl; // Output: List contains 25: true

    // Getting the size of the list
    int size = list.size();
    cout << "Size of the list: " << size << endl; // Output: Size of the list: 3

    // Checking if the list is empty
    bool isEmpty = list.empty();
    cout << "List is empty: " << (isEmpty ? "true" : "false") << endl; // Output: List is empty: false

    // Clearing the list
    list.clear();
    cout << "List after clearing: " << list.toString() << endl; // Output: List after clearing: []
}

void doubleLinkedList() {
    //DLinkedList<int> list;

    // // Test add and toString
    // list.add(10);
    // list.add(20);
    // list.add(30);

    // std::cout << "List: " << list.toString() << std::endl; // Output: List: [10, 20, 30]

    // // Test add at index
    // list.add(1, 15);

    // std::cout << "List: " << list.toString() << std::endl; // Output: List: [10, 15, 20, 30]

    // // Test reverse
    // list.reverse();

    // std::cout << "List: " << list.toString() << std::endl;

    // // Test get
    // int value = list.get(2);

    // std::cout << "Value at index 2: " << value << std::endl; // Output: Value at index 2: 20

    // // Test set
    // list.set(0, 5);

    // std::cout << "List after set: " << list.toString() << std::endl; // Output: List after set: [5, 15, 20, 30]

    // // Test contains
    // bool contains15 = list.contains(15);
    // bool contains25 = list.contains(25);

    // std::cout << "Contains 15: " << contains15 << std::endl; // Output: Contains 15: 1 (true)
    // std::cout << "Contains 25: " << contains25 << std::endl; // Output: Contains 25: 0 (false)

    // // Test size and empty
    // int size = list.size();
    // bool isEmpty = list.empty();

    // std::cout << "Size: " << size << std::endl;        // Output: Size: 4
    // std::cout << "Is Empty: " << isEmpty << std::endl; // Output: Is Empty: 0 (false)

    // // Test removeAt
    // int removedValue = list.removeAt(1);

    // std::cout << "Removed value: " << removedValue << std::endl;          // Output: Removed value: 15
    // std::cout << "List after removeAt: " << list.toString() << std::endl; // Output: List after removeAt: [5, 20, 30]

    // // Test removeItem
    // bool removed30 = list.removeItem(30);
    // bool removed25 = list.removeItem(25);

    // std::cout << "Removed 30: " << removed30 << std::endl;                  // Output: Removed 30: 1 (true)
    // std::cout << "Removed 25: " << removed25 << std::endl;                  // Output: Removed 25: 0 (false)
    // std::cout << "List after removeItem: " << list.toString() << std::endl; // Output: List after removeItem: [5, 20]

    // // Test indexOf
    // int index20 = list.indexOf(20);
    // int index15 = list.indexOf(15);

    // std::cout << "Index of 20: " << index20 << std::endl; // Output: Index of 20: 1
    // std::cout << "Index of 15: " << index15 << std::endl; // Output: Index of 15: -1

    // // Test clear and empty
    // list.clear();
    // isEmpty = list.empty();

    // std::cout << "Is Empty after clear: " << isEmpty << std::endl; // Output: Is Empty after clear: 1 (true)

    // for (int idx = 0; idx < 10; idx++)
    // {
    //     list.add(idx);
    // }

    // DLinkedList<int>::Iterator it = list.begin();
    // while (it != list.end())
    // {
    //     it.remove();
    // }
    // cout << list.toString();

    DLinkedList<int> list;
    int size = 10;
    for (int idx = 0; idx < size; idx++)
    {
        list.add(idx);
    }

    DLinkedList<int>::Iterator it = list.begin();
    for (; it != list.end();)
    {
        it.remove();
        it++;
    }
    cout << list.toString();
}

void heap() {
    Heap test;

    test.add(5);
    test.add(7);
    test.add(9);
    test.add(11);
    test.add(14);
    test.add(16);

    test.add(4);
    test.add(6);
    test.poll();

    test.dump();
}

int main() {
    int choice = 3;
    //cin >> choice;

    switch (choice) {
        case 1:
            intList();
            break;
        case 2:
            linkedList();
            break;
        case 3:
            doubleLinkedList();
            break;
        case 4:
            heap();
            break;
    }

    return 0;
}

