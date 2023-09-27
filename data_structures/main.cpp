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
    IntSDoubleLinkedList test;

    test.add(1);
    test.add(2);
    test.add(3);
    test.add(4);
    test.add(5);
    test.add(6);
    cout << test.toString() << endl;

    test.reverse();
    cout << test.toString() << endl;

    test.add(2, 10);
    cout << test.toString() << endl;

    test.set(3, 100);
    cout << test.toString() << endl;

    test.removeAt(0);
    test.removeItem(1);
    cout << test.toString() << endl;

    cout << test.indexOf(100) << " " << test.size() << " " << test.contains(10) << endl;

    test.reverse();
    cout << test.toString() << endl;

    test.clear();
    cout << test.toString() << endl;

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
    int choice = 2;
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

