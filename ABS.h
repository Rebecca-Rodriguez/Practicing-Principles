#pragma once
#include <iostream>
using namespace std;

template <class T>

class ABS
{
private:
    static double scale;
    unsigned int size;
    unsigned int capacity;
    T* data;
    void resize(double scale);
public:
    ABS();		                        // Default Constructor
    ABS(int capacity);		            // Constructor w/ starting max
    ABS(const ABS& d);		            // Copy Constructor
    ABS& operator=(const ABS& d);		// Assignment Operator
    ~ABS();		                        // Destructor
    void push(T data);		            // Add to Top of Stack
    T pop();		                    // Remove from Top
    T peek();		                    // Return top value
    unsigned int getSize();		        // Return # of items
    unsigned int getMaxCapacity();		// Return max capaity
    T* getData();		                // Return array representing stack
};

template <class T>
double ABS<T>::scale = 2.0;

/*---------- Default Constructor ----------*/
template <class T>
ABS<T>::ABS()
{
    capacity = 1;
    size = 0;
    data = new T[capacity];
}

/*---------- Constructor w/ starting max ----------*/
template <class T>
ABS<T>::ABS(int capacity)
{
    this->capacity = capacity;
    size = 0;
    data = new T[this->capacity];
}

/*---------- Copy Constructor ----------*/
template <class T>
ABS<T>::ABS(const ABS<T>& d)
{
    capacity = d.capacity;
    size = d.size;
    data = new T[capacity];
    for (int i = 0; i < size; i++)
    {
        data[i] = d.data[i];
    }
}

/*---------- Assignment Operator ----------*/
template <class T>
ABS<T>& ABS<T> ::operator=(const ABS<T>& d)
{
    if (this != &d)
    {
        delete[] data;
        capacity = d.capacity;
        size = d.size;
        data = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            data[i] = d.data[i];
        }
    }
    return *this;
}

/*---------- Destructor ----------*/
template <class T>
ABS<T>::~ABS()
{
    delete[] data;
}

/*---------- Add to Top of Stack ----------*/
template <class T>
void ABS<T>::push(T data)
{
    if (size == capacity)
    {
        resize(scale);
    }
    this->data[size] = data;
    size++;
}

/*---------- Remove from Top ----------*/
template <class T>
T ABS<T>::pop()
{
    if (size == 0)
    {
        throw runtime_error("An error has occured.");
    }
    T item = data[size - 1];
    size--;
    if (capacity > 1)
    {
        if ((((double)size) / capacity) < ((double)1 / scale))
        {
            resize((double)1 / scale);
        }
    }
    return item;
}

/*---------- Return top value ----------*/
template <class T>
T ABS<T>::peek()
{
    if (size == 0)
    {
        throw runtime_error("An error has occured.");
    }
    T item = data[size - 1];
    return item;
}

/*---------- Return # of items ----------*/
template <class T>
unsigned int ABS<T>::getSize()
{
    return size;
}

/*---------- Return max capaity ----------*/
template <class T>
unsigned int ABS<T>::getMaxCapacity()
{
    return capacity;
}

/*---------- Return array representing stack ----------*/
template <class T>
T* ABS<T>::getData()
{
    return data;
}


template <class T>
void ABS<T>::resize(double scale)
{
    T* tempData = new T[(int)(capacity * scale)];
    for (unsigned int i = 0; i < size; i++)
    {
        tempData[i] = data[i];
    }
    capacity = capacity * scale;
    delete[] data;
    data = tempData;
}