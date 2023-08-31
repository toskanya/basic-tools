#include "main.h"
#include "integer_array.h"

IntArrayList::IntArrayList() {
    this->capacity = 10;
    this->data = new int[capacity];
    this->count = 0;
}

IntArrayList::~IntArrayList() {
    delete[] this->data;
}

void IntArrayList::ensureCapacity(int capacity) {
    if (capacity > this->capacity) {
        // create the new maximum length
        int new_capacity = this->capacity * 3 / 2; 

        int * new_data = new int[new_capacity];

        // copy "data" to "new_data" with a size of count * bytes(int)
        memmove(new_data, this->data, this->count * sizeof(int));

        // delete the array of pointer "data"
        delete[] this->data; 
        this->data = new_data;
    }
}

void IntArrayList::checkIndex(int index) {
    if (index < 0 || index >= this->count)
        throw out_of_range("Index is out of range");
}

void IntArrayList::add(int element) {
    ensureCapacity(this->count + 1);

    this->data[this->count] = element;
    this->count++;
}

void IntArrayList::add(int index, int element) {
    checkIndex(index);
    ensureCapacity(this->count + 1);

    //calculate total length needed to right shift
    int moveCount = this->count - index; 
    
    //check if it needs to be shifted
    if (moveCount > 0) {
        memmove(this->data + index + 1, this->data + index, moveCount * sizeof(int));
    }

    this->data[index] = element;
    count++;
}

int IntArrayList::removeAt(int index) {
    checkIndex(index);

    int remove_element = this->data[index];

    int moveCount = this->count - index;
    if (moveCount > 0) {
        memmove(this->data + index, this->data + index + 1, moveCount * sizeof(int));
    }

    this->count--;
    return remove_element;
}

bool IntArrayList::removeItem(int element) {
    for (int index = 0; index < this->count; index++) {
        if (this->data[index] == element) {
            removeAt(index);
            return true;
        }
    }
    return false;
}

bool IntArrayList::empty() {
    return this->count == 0;
}

int IntArrayList::size() {
    return this->count;
}

void IntArrayList::clear() {
    delete[] this->data;

    this->capacity = 10;
    this->data = new int[this->capacity];
    this->count = 0;
}

int IntArrayList::get(int index) {
    checkIndex(index);

    return this->data[index];
}

void IntArrayList::set(int index, int element) {
    checkIndex(index);

    this->data[index] = element;
}

int IntArrayList::indexOf(int element) {
    for (int index = 0; index < this->count; index++) {
        if (this->data[index] == element)
            return index;
    }
    return -1;
}

bool IntArrayList::contains(int element) {
    return indexOf(element) != -1;
}

string IntArrayList::toString() {
    stringstream ss;
    ss << "[";

    for (int index = 0; index < count - 1; index++) {
        ss << this->data[index] << ", ";
    }

    if (count > 0) ss << this->data[count - 1] << "]";
    else ss << "]";

    return ss.str();
}

void IntArrayList::dump() {
    string line(50, '=');
    cout << line << endl;
    cout << "Integer list's information: " << endl;
    cout << "Capacity: " << this->capacity << endl;
    cout << "Size: " << this->count << endl;
    cout << "Data: " << toString() << endl;
    cout << line << endl;
}