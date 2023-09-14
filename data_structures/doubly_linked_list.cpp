#include "main.h"
#include "doubly_linked_list.h"

IntSDoubleLinkedList::IntSDoubleLinkedList() {
    this->head = new Node();
    this->count = 0;
}

void IntSDoubleLinkedList::checkIndex(int index) {
    if (index < 0 || index >= count) {
        throw out_of_range("Index is out of range");
    }
}

void IntSDoubleLinkedList::add(int element) {
    Node *temp = new Node;
    temp->data = element;

    if (this->count == 0) {
        this->head->next = temp;
    }
    else {
        Node * current = this->head;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = temp;
        temp->pre = current;
    }

    this->count++;
}

void IntSDoubleLinkedList::add(int index, int element) {
    checkIndex(index);

    Node * temp = new Node();
    temp->data = element;
    Node * current = this->head;

    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    temp->next = current->next;
    temp->pre = current;
    current->next = temp;
    current->next->pre = temp;

    this->count++;
}

int IntSDoubleLinkedList::removeAt(int index) {
    checkIndex(index);

    Node * temp;
    Node * current = this->head;

    if (index == 0 && count == 1) {
        temp = current->next;
        this->head = new Node();
    }
    else {
        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        temp = current->next;
        current->next = current->next->next;

        if (index != count - 1) {
            current->next->pre = current;
        }
    }

    int data = temp->data;
    delete temp;
    this->count--;

    return temp->data;
}

bool IntSDoubleLinkedList::removeItem(int item) {
    Node * current = this->head->next;
    int index = 0;

    while (current != nullptr) {
        if (current->data == item) {
            removeAt(index);
            return true;
        }
        
        index++;
        current = current->next;
    }

    return false;
} 

int IntSDoubleLinkedList::get(int index) {
    checkIndex(index);

    Node * current = this->head->next;

    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    return current->data;
}   

void IntSDoubleLinkedList::set(int index, int element) {
    checkIndex(index);

    Node * current = this->head->next;
    
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    current->data = element;
}

bool IntSDoubleLinkedList::contains(int item) {
    Node * current = this->head;

    while (current != nullptr) {
        if (current->data == item) {
            return true;
        }
        
        current = current->next;
    }
    
    return false;
}

string IntSDoubleLinkedList::toString() {
    stringstream ss;
    ss << "[";

    Node * current = this->head->next;

    for (int i = 0; i < this->count - 1; i++) {
        ss << current->data << ", ";
        current = current->next;
    }

    if (count == 0) {
        ss << "]";
    }
    else {
        ss << current->data << "]";
    }

    return ss.str();
}

int IntSDoubleLinkedList::size() {
    return this->count;
}

bool IntSDoubleLinkedList::empty() {
    return this->count == 0;
}

void IntSDoubleLinkedList::clear() {
    Node * current = this->head->next;
    Node * next = nullptr;

    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }

    delete current;
    delete next;

    this->head = new Node();
    this->count = 0;
}

int IntSDoubleLinkedList::indexOf(int item) {
    Node * current = this->head->next;
    int index = 0;

    while (current != nullptr) {
        if (current->data == item) {
            return index;
        }

        index++;
        current = current->next;
    }

    return -1;
}

void IntSDoubleLinkedList::reverse() {
    Node * current = this->head->next;
    Node * previous = nullptr;

    while (current != nullptr) {
        current->pre = current->next;
        current->next = previous;
        previous = current;
        current = current->pre;
    }

    this->head->next = previous;
}

IntSDoubleLinkedList::~IntSDoubleLinkedList() {
    this->clear();
}