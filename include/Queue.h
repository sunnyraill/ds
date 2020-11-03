#ifndef QUEUE_H
#define QUEUE_H
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#define QueueCapacity 10
typedef struct queue_s {
    int front;
    int rear;
    int capacity;
    int * data;
} Queue;

int isQueueFull (Queue* queue);
int isQueueEmpty (Queue* queue);

void enqueue (int data, Queue * queue);
int dequeue (Queue* queue);
Queue * initQueue();


void printQueue(Queue *queue);

#endif
