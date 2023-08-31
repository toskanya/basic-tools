#include "main.h"
#include "singly_linked_list.h"

IntSLinkedList::IntSLinkedList() {
    this->head = new Node();
    this->tail = new Node();
    count = 0;
}

void IntSLinkedList::checkIndex(int index) {
    if (index < 0 || index >= this->count)
        throw out_of_range("Index is out of range");
}

void IntSLinkedList::add(int element) {
    if (this->count == 0) {
        Node * temp = new Node();
        temp->data = element;

        this->head->next = temp;
        this->tail->next = temp;
    }
    else {
        Node * temp = new Node();
        temp->data = element;
        Node * current = this->head;

        while (current != tail->next) {
            current = current->next;
        }

        current->next = temp;
        this->tail->next = temp;
    }

    this->count++;
}

void IntSLinkedList::add(int index, int element) {
    checkIndex(index);

    if (index == count - 1)
        add(element);
    else {
        Node * temp = new Node();
        temp->data = element;
        Node * current = this->head;

        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        temp->next = current->next;
        current->next = temp;

        this->count++;
    } 
}

int IntSLinkedList::removeAt(int index) {
    checkIndex(index);

    Node * temp;
    Node * current = this->head;

    if (index == 0 && count == 1) {
        temp = current->next;
        this->head = new Node();
        this->tail = new Node();
    }
    else {
        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        temp = current->next;

        if (index == count - 1) {
            this->tail->next = current;
            current->next = nullptr;
        }
        else {
            current->next = current->next->next;
        }
    }

    this->count--;
    return temp->data;
}

bool IntSLinkedList::removeItem(int item) {
    Node * current = this->head;
    int index = 0;

    while (current != nullptr) {
        if (current->data == item) {
            removeAt(index - 1);
            return true;
        }

        index++;
        current = current->next;
    }

    return false;
}

int IntSLinkedList::get(int index) {
    checkIndex(index);

    Node * current = this->head;

    for (int i = 0; i <= index; i++) {
        current = current->next;
    }

    return current->data;
}

void IntSLinkedList::set(int index, int element) {
    checkIndex(index);

    Node * current = this->head;

    for (int i = 0; i <= index; i++) {
        current = current->next;
    }

    current->data = element;
}

bool IntSLinkedList::contains(int item) {
    Node * current = this->head;

    while (current != nullptr) {
        if (current->data == item) {
            return true;
        }
        
        current = current->next;
    }

    return false;
}

int IntSLinkedList::size() {
    return this->count;
}

string IntSLinkedList::toString() {
    stringstream ss;
    ss << "[";

    Node * current = this->head->next;

    for (int i = 0; i < count - 1; i++) {
        ss << current->data << ", ";
        
        current = current->next;
    }

    if (count > 0) {
        ss << current->data << "]";
    }
    else ss << "]";

    return ss.str();
}

void IntSLinkedList::clear() {
    Node * temp;
    Node * current = this->head;

    while (current != nullptr) {
        temp = current->next;
        delete current;
        current = temp;
    }

    this->head = new Node();
    this->tail = new Node();
    this->count = 0;
}

bool IntSLinkedList::empty() {
    return this->count == 0;
}

int IntSLinkedList::indexOf(int item) {
    Node * current = this->head;
    int index = 0;
    
    while (current != tail->next) {
        if (current->data == item) {
            return index;
        }
        
        current = current->next;
    }

    return -1;
} 