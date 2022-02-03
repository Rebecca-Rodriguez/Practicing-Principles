#pragma once
class Node {
public:
    int data;
    Node* next;
    Node(int val) { data = val; next = nullptr; }
    Node(int val, Node* node) { data = val; next = node; }
};

class Stack_LL {
private:
    // topPtr points to the top element of the stack
    Node* topPtr;
public:
    Stack_LL();
    ~Stack_LL();

    bool isEmpty() const;
    void push(int newItem);
    void pop();
    int peek() const;
};
