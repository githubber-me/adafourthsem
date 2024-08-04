#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

int minKey(int key[], int mstSet[], int V)  
{ 
    int min = INT_MAX, min_index; 
    int v; 

    for (v = 0; v < V; v++) 
        if (mstSet[v] == 0 && key[v] < min) 
            min = key[v], min_index = v; 

    return min_index; 
} 

void printMST(int parent[], int graph[MAX_VERTICES][MAX_VERTICES], int V)  
{ 
    int i; 
    printf("Edge \tWeight\n"); 
    for (i = 1; i < V; i++) 
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]); 
} 

void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int V)  
{ 
    int parent[MAX_VERTICES]; 
    int key[MAX_VERTICES]; 
    int mstSet[MAX_VERTICES]; 
    int u, v, i, count; 

    for (i = 0; i < V; i++)  
    { 
        key[i] = INT_MAX; 
        mstSet[i] = 0; 
    } 

    key[0] = 0; 
    parent[0] = -1; 

    for (count = 0; count < V - 1; count++)  
    { 
        u = minKey(key, mstSet, V); 
        mstSet[u] = 1; 

        for (v = 0; v < V; v++)  
        { 
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])  
            { 
                parent[v] = u; 
                key[v] = graph[u][v]; 
            } 
        } 
    } 

    printMST(parent, graph, V); 
} 

int main()  
{ 
    int V, i, j; 
    int graph[MAX_VERTICES][MAX_VERTICES]; 

    printf("Enter the number of vertices: "); 
    scanf("%d", &V); 

    if (V > MAX_VERTICES)  
    { 
        printf("Number of vertices exceeds the maximum allowed (%d)\n", MAX_VERTICES); 
        return -1; 
    } 

    printf("Enter the adjacency matrix:\n"); 
    for (i = 0; i < V; i++)  
    { 
        for (j = 0; j < V; j++)  
        { 
            scanf("%d", &graph[i][j]); 
        } 
    } 

    primMST(graph, V); 
    return 0; 
}
