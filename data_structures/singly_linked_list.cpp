#include "main.h"
#include "singly_linked_list.h"

template <class T>
LinkedList<T>::LinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
    count = 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    this->clear();
}

template <class T>
void LinkedList<T>::checkIndex(int index)
{
    if (index < 0 || index >= this->count)
        throw out_of_range("Index is out of range");
}

template <class T>
void LinkedList<T>::add(T element)
{
    this->add(this->count, element);
}

template <class T>
void LinkedList<T>::add(int index, T element)
{
    this->checkIndex(index);

    Node * temp = new Node(element, nullptr);

    if (count == 0) {
        this->head = temp;
        this->tail = temp;
    }
    else if (index == 0) {
        temp->next = this->head;
        this->head = temp;
    }
    else if (index == count) {
        tail->next = temp;
        tail = temp;
    }
    else {
        Node * current = this->head;

        for (int i = 1; i < index; i++) {
            current = current->next;
        }

        temp->next = current->next;
        current->next = temp;
    }

    this->count++;
}

template <class T>
int LinkedList<T>::removeAt(int index)
{
    this->checkIndex(index);

    T remove_element;

    if (index == 0) {
        remove_element = this->head->data;
        this->head = this->head->next;

        if (this->head == nullptr) {
            this->tail = nullptr;
        }
    }
    else {
        Node * current = this->head;

        for (int i = 1; i < index; i++){
            current = current->next;
        }

        remove_element = current->data;

        if (current->next == this->tail) {
            this->tail = current;
            this->tail->next = nullptr;
        }
        else {
            current->next = current->next->next;
        }
    }

    this->count--;
    return remove_element;
}

template <class T>
bool LinkedList<T>::removeItem(T item)
{
    Node * current = this->head;
    Node * previous = nullptr;

    while (current != nullptr) {
        if (current->data == item) {
            if (current == this->head) {
                this->head = this->head->next;
            }
            else {
                previous->next = current->next;
            }

            this->count--;
            if (this->count == 0) {
                this->tail = nullptr;
            }

            return true;
        }
        previous = current;
        current = current->next;
    }

    return false;
}

template <class T>
int LinkedList<T>::get(int index)
{
    this->checkIndex(index);

    Node * current = this->head;

    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    return current->data;
}

template <class T>
void LinkedList<T>::set(int index, T element)
{
    checkIndex(index);

    Node * current = this->head;

    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    current->data = element;
}

template <class T>
bool LinkedList<T>::contains(T item)
{
    Node * current = this->head;

    while (current != nullptr) {
        if (current->data == item) {
            return true;
        }
        
        current = current->next;
    }

    return false;
}

template <class T>
int LinkedList<T>::size()
{
    return this->count;
}

template <class T>
string LinkedList<T>::toString()
{
    if (this->empty()) {
        return "[]";
    }

    stringstream ss;
    ss << "[";

    Node * current = this->head;

    while (current->next != nullptr) {
        ss << current->data << ", ";
        
        current = current->next;
    }

    ss << current->data << "]";

    return ss.str();
}

template <class T>
void LinkedList<T>::clear()
{
    Node * current = this->head;
    Node * temp = nullptr;

    while (current != nullptr) {
        temp = current;
        current = current->next;
        delete temp;
    }

    this->tail = nullptr;
    this->count = 0;
}

template <class T>
bool LinkedList<T>::empty()
{
    return this->count == 0;
}

template <class T>
int LinkedList<T>::indexOf(T item)
{
    Node * current = this->head;
    int index = 0;
    
    while (current != nullptr) {
        if (current->data == item) {
            return index;
        }
        
        current = current->next;
        index++;
    }

    return -1;
}
     