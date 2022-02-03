#include "Stack_LL.h"
Stack_LL::Stack_LL() {
    topPtr = nullptr;
}

Stack_LL::~Stack_LL() {
    while (!isEmpty()) {
        pop();
    }
}

bool Stack_LL::isEmpty() const {
    return topPtr == nullptr;
}

void Stack_LL::push(int newItem) {
    Node* newNode = new Node(newItem, topPtr);
    topPtr = newNode;
    newNode = nullptr;
}

void Stack_LL::pop() {
    Node* nodeToPop = topPtr;
    topPtr = topPtr->next;
    nodeToPop->next = nullptr;
    delete nodeToPop;
    nodeToPop = nullptr;
}

int Stack_LL::peek() const {
    return topPtr->data;
}