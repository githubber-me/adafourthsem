#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 100

// Global variables
int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int stack[MAX_VERTICES];
int top = -1;

// Function to perform Depth First Search (DFS)
void dfs(int u, int n) {
    int v;
    visited[u] = 1;
    for(v = 0; v < n; v++) {
        if(graph[u][v] && !visited[v]) {
            dfs(v, n);
        }
    }
    stack[++top] = u;
}

// Function to perform Topological Sort
void topologicalSort(int n) {
    int i,u;
    for(i = 0; i < n; i++) {
        visited[i] = 0;
    }
    for(u = 0; u < n; u++) {
        if(!visited[u]) {
            dfs(u, n);
        }
    }
    printf("Topological Ordering: ");
    while(top != -1) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    int n,i,j;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    printf("Topological Sorting:\n");
    topologicalSort(n);
    
    return 0;
}
