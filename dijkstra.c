#include <stdio.h> 
#include <limits.h> 

#define MAX_VERTICES 100 

int minDistance(int dist[], int sptSet[], int V)  
{ 
    int min = INT_MAX, min_index, v; 
    for (v = 0; v < V; v++) 
        if (sptSet[v] == 0 && dist[v] <= min) 
            min = dist[v], min_index = v; 
    return min_index; 
} 

void printSolution(int dist[], int n)  
{ 
    int i; 
    printf("Vertex \t\t Distance from Source\n"); 
    for (i = 0; i < n; i++) 
        printf("%d \t\t %d\n", i, dist[i]); 
} 

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int src, int V)  
{ 
    int dist[MAX_VERTICES]; 
    int sptSet[MAX_VERTICES]; 
    int i, count, v; 

    for (i = 0; i < V; i++)  
    { 
        dist[i] = INT_MAX; 
        sptSet[i] = 0; 
    } 

    dist[src] = 0; 

    for (count = 0; count < V - 1; count++)  
    { 
        int u = minDistance(dist, sptSet, V); 
        sptSet[u] = 1; 

        for (v = 0; v < V; v++) 
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) 
                dist[v] = dist[u] + graph[u][v]; 
    } 

    printSolution(dist, V); 
} 

int main()  
{ 
    int V; 
    int graph[MAX_VERTICES][MAX_VERTICES]; 
    int src, i, j; 

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

    printf("Enter the source vertex: "); 
    scanf("%d", &src); 

    if (src < 0 || src >= V)  
    { 
        printf("Invalid source vertex\n"); 
        return -1; 
    } 

    dijkstra(graph, src, V); 
    return 0; 
}
