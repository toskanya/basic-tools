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
    IntSLinkedList test;

    test.add(2);
    test.add(3);
    cout << test.size() << endl;
    cout << test.toString() << endl;

    test.clear();
    cout << test.size() << endl;
    cout << test.toString() << endl << endl;

    for (int i = 0; i < 6; i++) {
        test.add(rand() % 10);
    }
    
    cout << test.toString() << endl;

    test.removeAt(0);
    test.removeAt(2);
    cout << test.toString() << endl;
    test.removeItem(4);
    cout << test.toString() << endl;
    test.removeItem(4);
    cout << test.toString() << endl;
    test.removeAt(1);
    cout << test.toString() << endl;
    test.removeItem(7);

    cout << test.toString() << endl;

    cout << test.empty() << endl;

    cout << test.size() << endl;

    test.add(7);

    cout << test.toString() << endl;

    cout << test.indexOf(4) << endl;
    cout << test.contains(7) << endl;
    cout << test.contains(2) << endl;
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

