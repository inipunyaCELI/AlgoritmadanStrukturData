#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
private:
    int arr[100];
    int front;
    int rear;
    int size;
public:
    Queue();
    void enqueue(int x);
    int dequeue();
    bool isEmpty();
};
#endif