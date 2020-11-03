#ifndef MY_GRAPH_H
#define MY_GRAPH_H
typedef struct Graph_s {
    int V; // number of vertices
    int E; // number of Edges
    int ** Adj;
} Graph;
Graph * initGraph();
Graph * readGraph(Graph *g);
void printGraph(Graph *g);
int isConnected(Graph *g,int base, int destination);
void BFS(Graph *g);
void DFS(Graph *g);
#endif