#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../include/stack.h"
#include "../include/Queue.h"
typedef struct Graph_s {
    int V; // number of vertices
    int E; // number of Edges
    int ** Adj;
} Graph;

Graph * readGraph(Graph *g){
    if(!g){
         return g;
    }
    int isDirectional=0;
    FILE * f = fopen("../testdata/graphdata2.txt", "r");
    if(!f)
    {
        printf("Can't open file\n");
        return g;
    }
    
    fscanf(f, "%d", &(g->V));
    fscanf(f, "%d", &(g->E));
    fscanf(f, "%d", &(isDirectional));
    g->Adj = (int**) malloc (g->V * sizeof(int*));
    for(int i=0;i<g->V;i++){
        g->Adj[i] = (int*)malloc(g->V * sizeof(int));
    }
    for(int i = 0 ;i<g->V;i++){
        for(int j=0;j<g->V;j++)
        {
            g->Adj[i][j]=0;
        }
    }
    int v1, v2;
    for(int i=0;i<g->E;i++){
        fscanf(f, "%d %d", &v1, &v2);
        g->Adj[v1-1][v2-1] = 1;
        if(isDirectional)
            g->Adj[v2-1][v1-1] = 1;
    }
    if(isDirectional)
        g->E=2*g->E;
    return g;
}

void printGraph(Graph *g){
    if(!g)
        return;

    printf("No of Vertices = %d\n",g->V);
    printf("No of Edges = %d\nEdges:\n",g->E);

    for(int i=0;i<g->V;i++){
        for(int j=0;j<g->V;j++){
            if(g->Adj[i][j]==1){
                printf("%d - > %d\n",i+1,j+1);
            }
        }
    }

    printf("-----\n");
    return;
}
int isConnected(Graph *g,int base, int destination){
    if(base>(g->V-1) || destination>(g->V-1) || base<0 || destination <0){
        return -1;
    }
    if(g->Adj[base][destination])
        return 1;

    return 0;
}

void BFS(Graph *g){
    if(!g || !g->V)
        return;
    printf("Doing Bredth First Search\n");
    Queue *q = initQueue();

    int *visited = (int*)malloc(g->V*sizeof(int));
    for(int i=0;i<g->V;i++){
        visited[i] = 0;
    }

    enqueue(0, q);
    while(!isQueueEmpty(q)){
        int node = dequeue(q);
        if(!visited[node]){
            printf("Visited %d\n",node+1);
            visited[node] =1;
            for(int i=0;i<g->V;i++){
                if(isConnected(g, node, i)){
                    enqueue(i,q);
                }
            }
        }
    }

}
void DFS(Graph *g){
    if(!g || !g->V)
        return;

    printf("Doing Depth First Search\n");
    Stack *s = CreateStack();
    int * visited = (int*)malloc(g->V*sizeof(int));
    for(int i=0;i<g->V;i++){
        visited[i]=0;
    }

    push(s,0);
   
    while(!isStackEmpty(s)){
        int node = pop(s);
        if(!visited[node]){
             visited[node]=1;
             printf("visited %d \n",node+1);
        }
        for(int i=0;i<g->V;i++){
            if(isConnected(g,node,i) && !visited[i])
            {
                push(s,i);
                break;
            }
        }
    }
}
int main(){
    Graph * g = (Graph*)malloc(1*sizeof(Graph));
    g->V =0;
    g->E =0;
    g->Adj = NULL;
    g = readGraph(g);
    
    printGraph(g);

    DFS(g);
    BFS(g);
}