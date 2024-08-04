#include <stdio.h> 

#define INF 99999 
#define max 10 

// Function to print the solution matrix 
void printSolution(int dist[][max], int V); 

// Function to implement Floyd's Algorithm 
void floydWarshall(int graph[][max], int V)  
{ 
    int dist[max][max], i, j, k; 

    // Initialize the solution matrix same as input graph matrix. 
    for (i = 0; i < V; i++) 
        for (j = 0; j < V; j++) 
            dist[i][j] = graph[i][j]; 

    // Add all vertices one by one to the set of intermediate vertices. 
    for (k = 0; k < V; k++)  
    { 
        // Pick all vertices as source one by one 
        for (i = 0; i < V; i++)  
        { 
            // Pick all vertices as destination for the above picked source 
            for (j = 0; j < V; j++)  
            { 
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j]) 
                    dist[i][j] = dist[i][k] + dist[k][j]; 
            } 
        } 
    } 

    // Print the shortest distance matrix 
    printSolution(dist, V); 
} 

// Function to print the solution 
void printSolution(int dist[][max], int V)
{ 
    int i, j; 
    printf("Following matrix shows the shortest distances between every pair of vertices:\n"); 
    for (i = 0; i < V; i++)  
    { 
        for (j = 0; j < V; j++)  
        { 
            if (dist[i][j] == INF) 
                printf("%7s", "INF"); 
            else 
                printf("%7d", dist[i][j]); 
        } 
        printf("\n"); 
    } 
} 

int main()  
{ 
    int V, graph[max][max], i, j; // Number of vertices 
    printf("Enter the number of vertices: "); 
    scanf("%d", &V);     
    printf("Enter the cost adjacency matrix (enter %d for infinity):\n", INF); 

    for (i = 0; i < V; i++)  
    { 
        for (j = 0; j < V; j++)  
        { 
            scanf("%d", &graph[i][j]); 
            // Replace input value -1 with INF to represent no direct edge 
            if (graph[i][j] == -1)  
                graph[i][j] = INF; 
        } 
    } 

    // Print the solution 
    floydWarshall(graph, V); 
    return 0; 
}
