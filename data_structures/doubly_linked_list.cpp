#include "main.h"
#include "doubly_linked_list.h"

template <class T>
void DLinkedList<T>::checkIndex(int index)
{
    if (index < 0 || index > count)
        throw out_of_range("Index out of range");
}

template <class T>
DLinkedList<T>::DLinkedList()
{
    head = nullptr;
    tail = nullptr;
    count = 0;
}

template <class T>
DLinkedList<T>::~DLinkedList()
{
    this->clear();
}

template <class T>
void DLinkedList<T>::add(T element)
{
    this->add(count, element);
}

template <class T>
void DLinkedList<T>::add(int index, T element)
{
    this->checkIndex(index);

    Node *new_node = new Node(element);

    if (count == 0)
    {
        head = new_node;
        tail = new_node;
    }
    else if (index == 0)
    {
        new_node->next = head;
        head->pre = new_node;
        head = new_node;
    }
    else if (index == count)
    {
        new_node->pre = tail;
        tail->next = new_node;
        tail = new_node;
    }
    else
    {
        Node *temp = head;

        for (int i = 0; i < index - 1; i++)
            temp = temp->next;
        
        new_node->next = temp->next;
        new_node->pre = temp;
        temp->next->pre = new_node;
        temp->next = new_node;
    }

    count++;
}

template <class T>
T DLinkedList<T>::removeAt(int index)
{
    this->checkIndex(index);

    T result;
    Node *temp = head;

    for (int i = 0; i < index; i++)
        temp = temp->next;

    result = temp->data;

    if (count == 1)
    {
        head = nullptr;
        tail = nullptr;
    }
    else if (index == 0)
    {
        head = head->next;
        head->pre = nullptr;
    }
    else if (index == count - 1)
    {
        tail = tail->pre;
        tail->next = nullptr;
    }
    else
    {
        temp->next->pre = temp->pre;
        temp->pre->next = temp->next;

    }
    
    temp->next = nullptr;
    temp->pre = nullptr;
    delete temp;
    count--;
    return result;
}

template <class T>
bool DLinkedList<T>::removeItem(T item)
{
    Node *temp = head;
    int index = 0;

    while (temp != nullptr)
    {
        if (temp->data == item)
        {
            this->removeAt(index);
            return true;
        }

        index++;
        temp = temp->next;
    }

    return false;
}

template <class T>
T DLinkedList<T>::get(int index)
{
    Node *temp = head;

    for (int i = 0; i < index; i++)
        temp = temp->next;

    return temp->data;
}

template <class T>
void DLinkedList<T>::set(int index, T element)
{
    Node *temp = head;

    for (int i = 0; i < index; i++)
        temp = temp->next;

    temp->data = element;
}

template <class T>
bool DLinkedList<T>::contains(T item)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        if (temp->data == item)
            return true;
        temp = temp->next;
    }

    return false;
}

template <class T>
string DLinkedList<T>::toString()
{
    if (count == 0)
        return "[]";

    stringstream ss;
    ss << "[";

    Node *temp = head;

    for (int i = 0; i < count - 1; i++)
    {
        ss << temp->data << ", ";
        temp = temp->next;
    }

    ss << temp->data << "]";

    return ss.str();
}

template <class T>
int DLinkedList<T>::size()
{
    return count;
}

template<class T>
bool DLinkedList<T>::empty()
{
    return count == 0;
}

template<class T>
void DLinkedList<T>::clear()
{
    Node *temp = head;

    for (int i = 0; i < count; i++)
    {
        Node *del = temp;
        temp = temp->next;
        del->next = nullptr;
        del->pre = nullptr;
        delete del;
    }

    head = nullptr;
    tail = nullptr;
    count = 0;
}

template<class T>
int DLinkedList<T>::indexOf(T item)
{
    Node *temp = head;
    int index = 0;

    for (int i = 0; i < count; i++)
    {
        if (temp->data == item)
            return index;
        
        index++;
        temp = temp->next;
    }

    return -1;
}

template<class T>
void DLinkedList<T>::reverse()
{
    Node *current = head;
    Node *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = current->pre;
        current->pre = next;
        current = next;
    }

    Node *temp = head;
    head = tail;
    tail = temp;
}

template <class T>
DLinkedList<T>::Iterator::Iterator(DLinkedList<T> *pList, bool begin)
{
    this->pList = pList;

    if (begin)
    {
        current = (pList) ? pList->head : nullptr;
        index = 0;
    }
    else
    {
        current = nullptr;
        index = (pList) ? pList->size() : 0;
    }
}

template <class T>
typename DLinkedList<T>::Iterator &DLinkedList<T>::Iterator::operator=(const Iterator &iterator)
{
    if (this == &iterator)
    {
        return *this;
    }

    pList = iterator.pList;
    current = iterator.current;
    index = iterator.index;

    return *this;
}

template <class T>
void DLinkedList<T>::Iterator::set(const T &e)
{
    if (!current)
    {
        throw out_of_range("Segmentation Fault");
    }
    current->data = e;
}

template <class T>
T &DLinkedList<T>::Iterator::operator*()
{
    if (!current)
    {
        throw out_of_range("Segmentation Fault");
    }
    return current->data;
}

template <class T>
bool DLinkedList<T>::Iterator::operator!=(const Iterator &iterator)
{
    return current != iterator.current || index != iterator.index;
}

template <class T>
void DLinkedList<T>::Iterator::remove()
{
    if (!current)
    {
        throw out_of_range("Segmentation Fault");
    }

    Node * temp = current;
    current = new Node();
    current->next = temp->next;

    pList->removeAt(index);

    index--;

    // Node *temp = current;

    // if (temp == pList->head)
    // {
    //     pList->head = temp->next;
    //     if (temp->next)
    //     {
    //         temp->next->pre = nullptr;
    //     }
    // }
    // else if (temp == pList->tail)
    // {
    //     pList->tail = temp->pre;
    //     if (temp->pre)
    //     {
    //         temp->pre->next = nullptr;
    //     }
    //     index--;
    // }
    // else 
    // {
    //     temp->next->pre = temp->pre;
    //     temp->pre->next = temp->next;
    // }

    // current = new Node();
    // current->next = temp->next;
    // temp->next = nullptr;
    // temp->pre = nullptr;
    // delete temp;
    // pList->count--;
    // index--;
}

template <class T>
typename DLinkedList<T>::Iterator &DLinkedList<T>::Iterator::operator++()
{
    if (!current)
    {
        throw out_of_range("Segmentation Fault");
    }

    current = current->next;
    index++;

    return *this;
}

template <class T>
typename DLinkedList<T>::Iterator DLinkedList<T>::Iterator::operator++(int)
{
    if (!current)
    {
        throw out_of_range("Segmentation Fault");
    }

    Iterator temp = *this;
    current = current->next;
    index++;

    return temp;
}