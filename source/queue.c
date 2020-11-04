//#include "Queue.h"
#include "../include/Queue.h"

int isQueueFull (Queue* queue){
    if(queue->front == (queue->rear + 1)%queue->capacity)
        return 1;
    
    return 0;
}

int isQueueEmpty (Queue* queue){
    if(queue->front == -1)
        return 1;
        
    return 0;
}

int expandQueue(Queue *queue) {
    int * newData = (int*)malloc(2 * queue->capacity * sizeof(int));
    int i;
    
    if(!newData)
    {
        return 0;
    }
    
    for( i=queue->front; i<queue->capacity; i++){
        newData[i] = queue->data[i];
    }
    if(queue->rear < queue->front)
    {
        for( i=0; i<=queue->rear; i++){
            newData[queue->capacity + i] = queue->data[i];
        }
        queue->rear = queue->capacity + queue->rear;
    }
    queue->capacity = 2 * queue->capacity;
    return 1;
}

void enqueue (int data, Queue * queue){
    if(isQueueFull(queue))
    {
        int success = expandQueue(queue);
        if(!success){
            printf("Queue Expansion Failed ! \n");
            printf("Enqueuing Failed ! \n");
            return;
        }
            //
    }
    queue->rear = (queue->rear +1)%queue->capacity;
    queue->data[queue->rear] = data;
    if(queue->front==-1)
        queue->front=queue->rear; //or 0
    
    
}

int dequeue (Queue* queue) {
    if(!isQueueEmpty(queue))
    {
        int data = queue->data[queue->front];
        
        if(queue->rear == queue->front){
            queue->front = queue->rear = -1; //reset empty queue
        } else {
            queue->front = (queue->front + 1)%queue->capacity;
        }
        return data;
    }
    return INT_MIN;
}
Queue * initQueue() {
    Queue * queue = (Queue*)malloc(1 * sizeof(Queue));
    int i;
    if(!queue)
    {
        printf("not enough memory");
        return NULL;
    }
    queue->front = queue->rear = -1;
    queue->data = (int*)malloc(QueueCapacity * sizeof(int));
    if(!queue->data) {
        free(queue);
        printf("not enough memory");
        return NULL;
    }

    for(i=0;i<2;i++){
        queue->data[i] = '\0';
    }
    queue->capacity = QueueCapacity;
    
    return queue;
}

void printQueue(Queue *queue){
    if(isQueueEmpty(queue))
        return;
    int i=0;
    for(i=queue->front;i<=queue->rear;i++){
        printf("->%d",queue->data[i]);
    }
    
}

void deleteQueue(Queue *q){
    if(!q)
        return;
    if(q->data){
        free(q->data);
        q->data = NULL;
    }
    free(q);
    q= NULL;
    return;
}
/*int main (){
    Queue * queue = initQueue();
    int i=0;
    for(int i=0; i<100; i++){
        enqueue( i, queue);
    }
    printQueue(queue);
    printf("\n");
    for(int i=0; i<34; i++){
        dequeue(queue);
    }
    printQueue(queue);
}*/
