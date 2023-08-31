#ifndef __INTEGER_ARRAY__
#define __INTEGER_ARRAY__
#include "array.h"

class IntArrayList : public Ilist<int> {
private:
    void checkIndex(int index);
    void ensureCapacity(int capacity);
    
protected:
    int * data;
    int capacity;
    int count;

public:
    IntArrayList();
    ~IntArrayList();
    void add(int element);
    void add(int infex, int element);
    int removeAt(int index);
    bool removeItem(int item);
    bool empty();
    int size();
    void clear();
    int get(int index);
    void set(int index, int element);
    int indexOf(int item);
    bool contains(int item);
    string toString();
    void dump();
};

#endif