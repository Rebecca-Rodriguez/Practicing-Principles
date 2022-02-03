#include "CircularArrayQueue.h"

CircularArrayQueue::CircularArrayQueue()
{
    front = 0;
    back = CAPACITY - 1;
    counter = 0;
}

bool CircularArrayQueue::isEmpty() const
{
    return counter == 0;
}

void CircularArrayQueue::enqueue(int x)
{
    if (counter < CAPACITY) {
        back = (back + 1) % CAPACITY;
        items[back] = x;
        counter++;
    }
}

void CircularArrayQueue::dequeue()
{
    front = (front + 1) % CAPACITY;
    counter--;
}

int CircularArrayQueue::peekFront() const
{
    return items[front];
}