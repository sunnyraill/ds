#ifndef DS_PQ_H
#define DS_PQ_H

#define PQ_CAPACITY 10;
enum {
    MIN_PQ,
    MAX_PQ
};
typedef struct dataPQ_s {
    int data;
    int priority;
} DataPQ;
typedef struct pq_s {
    DataPQ * data; //zero based indexing
    int count;  //0 means one item is there
    int capacity; //1 means space for one item is there
    int pq_type;
} PQ;

void enqueuePQ(PQ *h, int data, int priority);
int dequePQ(PQ *h);
void printPQ(PQ *h);
PQ * createPQ();
void deletePQ(PQ * h);
int PQGetMin(PQ *h);
#endif
