#include <iostream>
#include <cstdlib>
#include "Array.h"
using namespace std;

class Stack
{
    int* arr;
    int capacity;   // max capacity
    int front;      //same as top or head
    int rear;       //simple base
    int count;      //current size

public:
    Stack(int);
    ~Stack();
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
    int pop();
    void push(int x);
    void readPic(Picture);
};

/*
Stack was made using the circular array implementation
*/