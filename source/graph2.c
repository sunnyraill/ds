#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../include/stack.h"
#include "../include/Queue.h"
#include "../include/priorityQueue.h"
//#include "../include/graph.h"

typedef struct adj_node
{
    int data;
    int cost;
    struct adj_node* next;
} anode;

typedef struct adj_graph {
    anode * list;
    int V;
    int E;
} agraph;

anode * createANode(int data){
    anode * newNode = (anode*)malloc(1*sizeof(anode));
    if(!newNode){
        fprintf(stderr,"\nnot enough memory\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

agraph * createAGraph(){
    agraph * g = (agraph*)malloc(1*sizeof(agraph));
    if(g){
        g->E = 0;
        g->V = 0;
        g->list = NULL;
    }
    return g;
}

agraph * readAGraph(agraph* g){
    if(!g){
        printf("graph supplied is NULL\n");
        return g;
    }
    int isBidirectional;
    FILE *f = fopen("testdata/graphdata2.txt", "r");
    if(!f)
    {
        fprintf(stderr, "Can't open file\n");
        return NULL;
    }
    fscanf(f, "%d", &g->V);
    fscanf(f, "%d", &g->E);
    fscanf(f, "%d", &isBidirectional);

    int V1, V2;
    g->list = (anode*)malloc(g->V * sizeof(anode));
    if(!g->list){
        fprintf(stderr, "\nnot enough memory\n");
        return NULL;
    } else {
        for(int i=0;i<g->V;i++){
            anode *adj_list_node = g->list + i;
            adj_list_node->data = i;
        }
    }
    for(int i=0;i<g->E;i++){
        fscanf(f, "%d %d",&V1, &V2);
        anode* temp =  (g->list)[V1-1].next;
        anode* newNode = createANode(V2-1);
        (g->list)[V1-1].next = newNode;
        newNode->next = temp ? temp : &((g->list)[V1-1]);

        if(isBidirectional){
            anode* temp1 =  (g->list)[V2-1].next;
            anode* newNode1 = createANode(V1-1);
            (g->list)[V2-1].next = newNode1;
            newNode1->next = temp1 ? temp1 : &((g->list)[V2-1]);
        }
    }
    return g;
}  

int isEdge(agraph* g, int v1, int v2){
    anode * base = g->list + v1;
    int isConnected = 0;
    anode * curr = base->next;
    while(curr && curr != base){
        if(curr->data == v2){
            isConnected = 1;
            break;
        }
        curr = curr->next;
    }
    return isConnected;
}

void BFS_agraph(agraph* g){
    fprintf(stdout, "Running BFS\n");
    if(!g || !g->V)
        return;

    Queue *q = initQueue();
    if(!q)
        return;
    
    int * visited = (int*)malloc(g->V * sizeof(int));
    if(!visited){
        fprintf(stderr, "not enough memory\n");
        return;
    } else {
        for(int i=0;i<g->V;i++)
            visited[i]=0;
    }

    enqueue(0,q);
    visited[0]=1;
    printf("visited %d\n",0+1);

    while(!isQueueEmpty(q)){
        int currentNode = dequeue(q);
        
        anode * base = g->list+currentNode;
        anode* curr = base->next;
        while( curr != base){
            if(!visited[curr->data]){
                visited[curr->data]=1;
                printf("visited %d\n",curr->data+1);
                enqueue(curr->data, q);
            }
            curr = curr->next;
        }
    }
}

void DFS_agraph(agraph* g){
    fprintf(stdout, "Running DFS\n");
    if(!g || !g->V)
        return;

    Stack *s = CreateStack();
    if(!s)
        return;
    
    int * visited = (int*)malloc(g->V * sizeof(int));
    if(!visited){
        fprintf(stderr, "not enough memory\n");
        return;
    } else {
        for(int i=0;i<g->V;i++)
            visited[i]=0;
    }

    push(s, 0);
    visited[0]=1;
    printf("visited %d\n",0+1);

    while(!isStackEmpty(s)){
        int currentNode = pop(s);
        
        anode * base = g->list+currentNode;
        anode* curr = base->next;
        while( curr != base){
            if(!visited[curr->data]){
                visited[curr->data]=1;
                printf("visited %d\n",curr->data+1);
                push(s,curr->data);
            }
            curr = curr->next;
        }
    }
}

void Dijkstra(agraph *g){
    fprintf(stdout, "Running Dijkstra\n");
    if(!g || !g->V)
        return;
    
    int * removed = (int*)malloc(g->V * sizeof(int));
    if(!removed)
    {
        fprintf(stderr, "not Enough Memory");
        return;
    } else {
        for(int i=0;i<g->V;i++){
            removed[i]=0;
        }
    }

    int * parent = (int*)malloc(g->V * sizeof(int));
    if(!parent)
    {
        fprintf(stderr, "not Enough Memory");
        return;
    } else {
        for(int i=0;i<g->V;i++){
            parent[i]=-1;
        }
    }

    int * cost = (int*)malloc(g->V * sizeof(int));
    if(!cost)
    {
        fprintf(stderr, "not Enough Memory");
        return;
    } else {
        for(int i=0;i<g->V;i++){
            cost[i]=INT_MAX;
        }
    }

    anode ** heap_nodes = (anode**)malloc(g->V * sizeof(anode*));
    if(!heap_nodes)
    {
        fprintf(stderr, "not Enough Memory");
        return;
    } else {
        for(int i=0;i<g->V;i++){
            heap_nodes[i]=NULL;
        }
    }

    PQ * h = createPQ();
    enqueuePQ(h,0,0);
    int minCost = INT_MAX;
    while(h->count > 0){
        int node = dequePQ(h); //need to create min heap

        anode * base = g->list + node;
        anode * current_node = base->next;
        while(current_node != base){
            int newcost = cost[node] + current_node->data;
            if(newcost<cost[current_node->data]){
                cost[current_node->data] = newcost;
                parent[current_node->data] = node;
            }
        }

    }
}

int main(){
    agraph * g = createAGraph();

    g = readAGraph(g);

    //BFS_agraph(g);

    //DFS_agraph(g);

    Dijkstra(g);
}