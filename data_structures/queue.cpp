#include "queue.h"
#include "main.h"

template <class T>
Queue<T>::Queue() 
{

}

template <class T>
void Queue<T>::push(T item)
{
    list.add(item);
}

template <class T>
T Queue<T>::pop()
{
    if (list.empty())
    {
        throw runtime_error("Queue is empty");
    }

    return list.removeAt(0);
}

template <class T>
T Queue<T>::top()
{
    if (list.empty())
    {
        throw runtime_error("Queue is empty");
    }

    return list.get(0);
}

template <class T>
int Queue<T>::size()
{
    return list.size();
}

template <class T>
void Queue<T>::clear()
{
    list.clear();
}

template <class T>
bool Queue<T>::empty()
{
    return list.empty();
}