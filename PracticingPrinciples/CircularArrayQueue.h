#pragma once
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class CircularArrayQueue {

private:
    // private data member
    int front;
    int back;
    int items[CAPACITY];
    int counter;
public:
    CircularArrayQueue();
    bool isEmpty() const;
    void enqueue(int x);
    void dequeue();
    int peekFront() const;
};
