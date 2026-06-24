#ifndef STACK_H
#define STACK_H

#define MAX 100

class stack
{
private:
    int top;
    int arr[100];

public:
    stack();
    void push(int x);
    int pop();
    int peek();
    bool isEmpty();
};
#endif