#include <stdio.h> 

#define max 10 // Default number of vertices, can be changed as needed 

void printMatrix(int reach[][max], int V); 

// Function to implement Warshall's Algorithm 
void warshall(int graph[][max], int V)  
{ 
    int reach[max][max], i, j, k; 

    // Initialize the reachability matrix same as input graph matrix. 
    for (i = 0; i < V; i++) 
        for (j = 0; j < V; j++) 
            reach[i][j] = graph[i][j]; 

    // Add all vertices one by one to the set of intermediate vertices. 
    for (k = 0; k < V; k++)  
    { 
        // Pick all vertices as source one by one 
        for (i = 0; i < V; i++)  
        { 
            // Pick all vertices as destination for the above picked source 
            for (j = 0; j < V; j++)  
            { 
                // If vertex k is on the shortest path from i to j, then update reach[i][j] 
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]); 
            } 
        } 
    } 

    // Print the reachability matrix 
    printMatrix(reach, V); 
} 

// Function to print the matrix 
void printMatrix(int reach[][max], int V)  
{ 
    int i, j; 
    printf("Following matrix is the transitive closure of the given graph:\n"); 
    for (i = 0; i < V; i++)  
    { 
        for (j = 0; j < V; j++)  
        { 
            printf("%4d", reach[i][j]); 
        } 
        printf("\n"); 
    } 
} 

int main()  
{ 
    int V, graph[max][max], i, j; // Number of vertices 
    printf("Enter the number of vertices: "); 
    scanf("%d", &V); 
    printf("Enter the adjacency matrix (0 for no edge, 1 for edge):\n"); 
    for (i = 0; i < V; i++)  
    { 
        for (j = 0; j < V; j++)  
        { 
            scanf("%d", &graph[i][j]); 
        } 
    } 

    // Print the transitive closure 
    warshall(graph, V); 
    return 0; 
}
