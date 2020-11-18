#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
//#include<math.h>
#include "../include/priorityQueue.h"


static int getParent(int i){
    return (i-1)/2;
}
static int getLeft(int i){
    return 2*i +1;
}
static int getRight(int i){
    return 2*i+2;
}

static void percolateUp(PQ *h, int index){
    int parentIndex = getParent(index);
    if(index<1 || parentIndex<0 || !h){
        return;
    }
    if(h->data[parentIndex].priority > h->data[index].priority){ //bubble up whichever is smaller
        DataPQ temp = h->data[parentIndex];
        h->data[parentIndex] = h->data[index];
        h->data[index] = temp;
    }
    percolateUp(h,parentIndex);
}
static void percolateDown(PQ *h, int index){
    if(!h)
        return;
    int leftChildIndex = getLeft(index);
    int rightChildIndex = getRight(index);
    int hasLeftChild = leftChildIndex>h->count?0:1;
    int hasRightChild = rightChildIndex > h->count?0:1;
    int max=index;
    
    if(!(hasLeftChild && hasRightChild)){  //if both absent then return
        return;
    }
    
    if( hasLeftChild && (h->data[leftChildIndex].priority < h->data[index].priority)){  //bubble up whichever is smaller
        DataPQ temp = h->data[leftChildIndex];
        h->data[leftChildIndex] = h->data[index];
        h->data[index] = temp;
        max= leftChildIndex;
    }
    
   if( hasRightChild && (h->data[rightChildIndex].priority < h->data[index].priority)){  //bubble up whichever is smaller
       DataPQ temp = h->data[rightChildIndex];
       h->data[rightChildIndex] = h->data[index];
       h->data[index] = temp;
       max=rightChildIndex;
   }
    
    if(max>index)
      percolateDown(h,max);
}
      
static void ensureCapacity(PQ * h){
    if(!h)
        return;
    if(h->capacity<1){  //no capacity to store even one item
        h->capacity = PQ_CAPACITY; //10 items
        h->data = (DataPQ*)malloc(sizeof(DataPQ)*(h->capacity));
        if(!h->data){
            printf("Not enough memory !");
            return;
        }
        
    } else if(h->count+1 > h->capacity-1){
        int i=-1;
        DataPQ * newData = NULL;
        h->capacity = 2 * h->capacity;
        newData = (DataPQ*)malloc(sizeof(DataPQ)*(h->capacity));
        if(!newData){
            printf("Not enough memory !");
            return;
        }
        for(i=0;i<=h->count;i++){
            newData[i].data=h->data[i].data;
            newData[i].priority=h->data[i].priority;
        }
        free(h->data);
        h->data = newData;
    }
}
void enqueuePQ(PQ *h, int data, int priority){
    ensureCapacity(h);
    h->count++;
    h->data[h->count].data = data;
    h->data[h->count].priority = priority;
    percolateUp(h,h->count);
}

int dequePQ(PQ *h){
    if(h->count <0)
        return INT_MAX;
    int dataToBeReturned = h->data[0].data;
    h->data[0] = h->data[h->count];
    h->count--;
    percolateDown(h,0);
    return dataToBeReturned;
}
      
int PQGetMin(PQ *h){
    if(h->count <0)
        return INT_MAX;
    return h->data[0].data;
}
void printPQ(PQ *h){
    //int height = ln(h->count+1);
    //int noOfLeaves = pow(2,height);
    for(int i=0;i<=h->count;i++){
        printf("%d ",h->data[i].data);
    }
}
PQ * createPQ(){
        PQ * h = (PQ*)malloc(1 * sizeof(PQ));
        h->count = -1;
        h->data = NULL;
        h->capacity = 0;
        h->pq_type = MIN_PQ;
    return h;
}

void deletePQ(PQ * h){
    if(h){
        if(h->data)
        {
            free(h->data);
            h->data = NULL;
        }
        free(h);
        h=NULL;
    }
}
/*int main(){
    Heap *h = createHeap();
    
    for(int i=100;i<110;i++){
        insert(h,i);
    }
    for(int i=0;i<100;i++){
        insert(h,i);
        
    }
    printHeap(h);
    printf("\n");
    insert(h,11);
    
    printf("\n");
    for(int i=0;i<120;i++){
        deleteMax(h);
        //printHeap(h);
        //printf("\n");
    }
    printHeap(h);
    deleteHeap(h);
    return 0;
}*/
