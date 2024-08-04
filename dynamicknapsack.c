#include <stdio.h> 

int max(int a, int b)  
{ 
    return (a > b) ? a : b; 
} 

void knapsack(int W, int n, int weights[], int values[])  
{ 
    int dp[n + 1][W + 1], i; 
    int res; 
    int w; 
    int solution[n]; 

    for (i = 0; i <= n; i++)  
    { 
        for (w = 0; w <= W; w++)  
        { 
            if (i == 0 || w == 0) 
                dp[i][w] = 0; 
            else if (weights[i - 1] <= w) 
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]); 
            else 
                dp[i][w] = dp[i - 1][w]; 
        } 
    } 

    printf("The maximum value that can be carried in the knapsack is: %d\n", dp[n][W]); 

    for (i = 0; i < n; i++)  
    { 
        solution[i] = 0; 
    } 

    res = dp[n][W]; 
    w = W; 
    printf("Items included in the knapsack (weight, value):\n"); 

    for (i = n; i > 0 && res > 0; i--)  
    { 
        if (res != dp[i - 1][w])  
        { 
            solution[i - 1] = 1; 
            printf("Item %d (Weight: %d, Value: %d)\n", i, weights[i - 1], values[i - 1]); 
            res = res - values[i - 1]; 
            w = w - weights[i - 1]; 
        }
    } 

    printf("\nSolution vector (1 indicates the item is included):\n"); 
    for (i = 0; i < n; i++)  
    { 
        printf("%d ", solution[i]); 
    } 
    printf("\n"); 
} 

int main()  
{ 
    int W; 
    int n, i; 
    int weights[20], values[20]; 

    printf("Enter the number of items: "); 
    scanf("%d", &n); 

    printf("Enter the weights of the items:\n"); 
    for (i = 0; i < n; i++)  
    { 
        scanf("%d", &weights[i]); 
    } 

    printf("Enter the values of the items:\n"); 
    for (i = 0; i < n; i++)  
    { 
        scanf("%d", &values[i]); 
    } 

    printf("Enter the maximum capacity of the knapsack: "); 
    scanf("%d", &W); 

    knapsack(W, n, weights, values); 

    return 0; 
}
