#include <iostream>

struct QueueNode {
    int data;
    QueueNode* next;
};

QueueNode* front = nullptr; 
QueueNode* rear = nullptr;  

void enqueue(int value) {
    QueueNode* new_node = new QueueNode{value, nullptr};
    
    // If the queue is empty, the new node is both the front and rear
    if (rear == nullptr) {
        front = rear = new_node; 
        return;
    }

    rear->next = new_node;
    rear = new_node;
}

int dequeue() {
    if (front == nullptr) {
        return -1;
    }
    
    // The person leaving is at the FRONT of the line!
    QueueNode* bookmarked = front; 
    int value = bookmarked->data;

    front = front->next;
    
    // Safety check: if the line is now empty, rear must also be cleared
    if (front == nullptr) {
        rear = nullptr;
    }
    
    delete bookmarked;
    return value;
}