#ifndef DS_HEAP_H
#define DS_HEAP_H

#define HEAP_CAPACITY 10;
enum {
    MIN_HEAP,
    MAX_HEAP
};
typedef struct heap_s {
    int * data; //zero based indexing
    int count;  //0 means one item is there
    int capacity; //1 means space for one item is there
    int heap_type;
} Heap;

void heapInsert(Heap *h, int data);
void heapDeleteMax(Heap *h);
void printHeap(Heap *h);
Heap * createHeap();
void deleteHeap(Heap * h);
int heapGetMax(Heap *h);
#endif
