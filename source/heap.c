#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
//#include<math.h>
#include "../include/heap.h"





int getParent(int i){
    return (i-1)/2;
}
int getLeft(int i){
    return 2*i +1;
}
int getRight(int i){
    return 2*i+2;
}

void percolateUp(Heap *h, int index){
    int parentIndex = getParent(index);
    if(index<1 || parentIndex<0 || !h){
        return;
    }
    if(h->data[parentIndex] < h->data[index]){ //bubble up whichever is larger
        int temp = h->data[parentIndex];
        h->data[parentIndex] = h->data[index];
        h->data[index] = temp;
    }
    percolateUp(h,parentIndex);
}
void percolateDown(Heap *h, int index){
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
    
    if( hasLeftChild && (h->data[leftChildIndex] > h->data[index])){  //bubble up whichever is larger
        int temp = h->data[leftChildIndex];
        h->data[leftChildIndex] = h->data[index];
        h->data[index] = temp;
        max= leftChildIndex;
    }
    
   if( hasRightChild && (h->data[rightChildIndex] > h->data[index])){  //bubble up whichever is larger
       int temp = h->data[rightChildIndex];
       h->data[rightChildIndex] = h->data[index];
       h->data[index] = temp;
       max=rightChildIndex;
   }
    
    if(max>index)
      percolateDown(h,max);
}
      
void ensureCapacity(Heap * h){
    if(!h)
        return;
    if(h->capacity<1){  //no capacity to store even one item
        h->capacity = HEAP_CAPACITY; //10 items
        h->data = (int*)malloc(sizeof(int)*(h->capacity));
        if(!h->data){
            printf("Not enough memory !");
            return;
        }
        
    } else if(h->count+1 > h->capacity-1){
        int i=-1;
        int * newData = NULL;
        h->capacity = 2 * h->capacity;
        newData = (int*)malloc(sizeof(int)*(h->capacity));
        if(!newData){
            printf("Not enough memory !");
            return;
        }
        for(i=0;i<=h->count;i++){
            newData[i]=h->data[i];
        }
        free(h->data);
        h->data = newData;
    }
}
void insert(Heap *h, int data){
    ensureCapacity(h);
    h->count++;
    h->data[h->count] = data;
    percolateUp(h,h->count);
}

void deleteMax(Heap *h){
    if(h->count <0)
        return;
    h->data[0] = h->data[h->count];
    h->count--;
    percolateDown(h,0);
}
      
int getMax(Heap *h){
    if(h->count <0)
        return INT_MIN;
    return h->data[0];
}
void printHeap(Heap *h){
    //int height = ln(h->count+1);
    //int noOfLeaves = pow(2,height);
    for(int i=0;i<=h->count;i++){
        printf("%d ",h->data[i]);
    }
}
Heap * createHeap(){
        Heap * h = (Heap*)malloc(1 * sizeof(Heap));
        h->count = -1;
        h->data = NULL;
        h->capacity = 0;
        h->heap_type = MAX_HEAP;
    return h;
}

void deleteHeap(Heap * h){
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
