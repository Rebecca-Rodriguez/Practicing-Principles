#pragma once
#include <iostream>
using namespace std;

template <class T>

class ABQ
{
private:
    static double scale;
    unsigned int size;
    unsigned int capacity;
    T* data;
    void resize(double scale);
public:
    ABQ();		                        // Default Constructor
    ABQ(int capacity);		            // Constructor w/ starting max
    ABQ(const ABQ& d);		            // Copy Constructor
    ABQ& operator=(const ABQ& d);		// Assignment Operator
    ~ABQ();		                        // Destructor
    void enqueue(T data);		        // Add to end of queue
    T dequeue();		                // Remove from front of queue
    T peek();		                    // Return item at front of queue
    unsigned int getSize();		        // Return # of items
    unsigned int getMaxCapacity();		// Return max capaity
    T* getData();		                // Return array representing queue
};

template <class T>
double ABQ<T>::scale = 2.0;

/*---------- Default Constructor ----------*/
template <class T>
ABQ<T>::ABQ()
{
    capacity = 1;
    size = 0;
    data = new T[capacity];
}

/*---------- Constructor w/ starting max ----------*/
template <class T>
ABQ<T>::ABQ(int capacity)
{
    this->capacity = capacity;
    size = 0;
    data = new T[this->capacity];
}

/*---------- Copy Constructor ----------*/
template <class T>
ABQ<T>::ABQ(const ABQ<T>& d)
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
ABQ<T>& ABQ<T>::operator=(const ABQ<T>& d)
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
ABQ<T>::~ABQ()
{
    delete[] data;
}

/*---------- Add to end of queue ----------*/
template <class T>
void ABQ<T>::enqueue(T data)
{
    if (size == capacity)
    {
        resize(scale);
    }
    this->data[size] = data;
    size++;
}

/*---------- Remove from front of queue ----------*/
template <class T>
T ABQ<T>::dequeue()
{
    if (size == 0)
    {
        throw runtime_error("An error has occured.");
    }
    T item = data[0];
    for (unsigned int i = 0; i < size - 1; i++)
    {
        data[i] = data[i + 1];
    }
    size--;
    if (capacity > 1)
    {
        if ((((double)size) / capacity) < ((double)1 / scale))
            resize((double)1 / scale);
    }
    return item;
}

/*---------- Return item at front of queue ----------*/
template <class T>
T ABQ<T>::peek()
{
    if (size == 0)
    {
        throw runtime_error("An error has occured.");
    }
    return data[0];
}

/*---------- Return # of items ----------*/
template <class T>
unsigned int ABQ<T>::getSize()
{
    return size;
}

/*---------- Return max capaity ----------*/
template <class T>
unsigned int ABQ<T>::getMaxCapacity()
{
    return capacity;
}

/*---------- Return array representing queue ----------*/
template <class T>
T* ABQ<T>::getData()
{
    return data;
}


template <class T>
void ABQ<T>::resize(double scale)
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