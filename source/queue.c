#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#define queueCapacity 10
typedef struct queue_s {
    int * data;
    int front;
    int rear;
    int capacity;
} Queue;

int isFull (Queue* queue){
    if(queue->front == (queue->rear + 1)%queue->capacity)
        return 1;
    
    return 0;
}

int isEmpty (Queue* queue){
    if(queue->front == -1)
        return 1;
        
    return 0;
}

void enqueue (int data, Queue * queue){
    if(!isFull(queue))
    {
        queue->rear = (queue->rear +1)%queue->capacity;
        queue->data[queue->rear] = data;
        if(queue->front==-1)
            queue->front=0;
    }
}

int dequeue (Queue* queue) {
    if(!isEmpty(queue))
    {
        int data = queue->data[queue->front];
        
        if(queue->rear == 0 && queue->front ==0){
            queue->front = queue->rear = -1;
        } else {
            queue->front = (queue->front -1)%queue->capacity;
        }
        return data;
    }
    return INT_MIN;
}
Queue * initQueue() {
    Queue * queue = (Queue*)malloc(sizeof(queue));
    if(!queue)
    {
        printf("not enough memory");
        return NULL;
    }
    queue->front = queue->rear = -1;
    queue->data = (int*)malloc(sizeof(int)*queueCapacity);
    if(!queue->data) {
        free(queue);
        printf("not enough memory");
        return NULL;
    }
    queue->capacity = queueCapacity;
    
    return queue;
}

void printQueue(Queue *queue){
    if(isEmpty(queue))
        return;
    int i=0;
    for(i=queue->front;i<=queue->rear;i++){
        printf("->%d",queue->data[i]);
    }
    
}
int main (){
    Queue * queue = initQueue();
    int i=0;
    for(int i=0; i<2; i++){
        enqueue( i, queue);
    }
//    dequeue(queue);
//    printQueue(queue);
}
