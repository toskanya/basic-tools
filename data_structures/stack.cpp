#include "main.h"
#include "stack.h"

template <class T>
Stack<T>::Stack()
{
}

template <class T>
void Stack<T>::push(T item)
{
    list.add(item);
}

template <class T>
T Stack<T>::top()
{
    if (list.empty())
    {
        throw runtime_error("Stack is empty");
    }

    return list.get(list.size() - 1);
}

template <class T>
T Stack<T>::pop()
{
    if (list.empty())
    {
        throw runtime_error("Stack is empty");
    }

    return list.removeAt(list.size() - 1);
}

template <class T>
bool Stack<T>::empty()
{
    return list.empty();
}

template <class T>
int Stack<T>::size()
{
    return list.size();
}

template <class T>
void Stack<T>::clear()
{
    list.clear();
}