#pragma once
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class CircularArrayQueue {

private:
    // private data member
    int CAPACITY = 30;
    int front;
    int back;
    int items[30];
    int counter;
public:
    CircularArrayQueue();
    bool isEmpty() const;
    void enqueue(int x);
    void dequeue();
    int peekFront() const;
};
