#include <iostream>
#include <cstdlib>
#include "Array.h"
using namespace std;

class Queue
{
    int* arr;       
    int capacity;   // max capacity
    int front;     
    int rear;       
    int count;      //current size

public:
    Queue(int);     
    ~Queue();        
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
    int dequeue();
    void enqueue(int x);
    void readPic(Picture);
};

/*
Queue was made using the circular array implementation
*/