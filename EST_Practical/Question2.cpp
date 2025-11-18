#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) { data = d; next = NULL; }
};

class Queue {
    Node* front;
    Node* rear;
public:
    Queue() { front = rear = NULL; }

    void enqueue(int x) {
        Node* n = new Node(x);
        if (rear == NULL) {
            front = rear = n;
            return;
        }
        rear->next = n;
        rear = n;
    }

    void dequeue() {
        if (front == NULL) return;
        Node* temp = front;
        front = front->next;
        if (front == NULL) rear = NULL;
        delete temp;
    }

    int peek() {
        if (front == NULL) return -1;
        return front->data;
    }

    bool isEmpty() {
        return front == NULL;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.dequeue();
    cout << q.peek();
}
