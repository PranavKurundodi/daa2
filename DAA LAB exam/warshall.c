#include <stdio.h>

#define MAX_VERTICES 100

// Function to print the solution matrix
void printSolution(int reach[][MAX_VERTICES], int n) {
    printf("Transitive closure of the given graph is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", reach[i][j]);
        printf("\n");
    }
}

// Function to compute transitive closure using Warshall's algorithm
void transitiveClosure(int graph[][MAX_VERTICES], int n) {
    int reach[MAX_VERTICES][MAX_VERTICES], i, j, k;

    // Initialize the solution matrix same as input graph matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            reach[i][j] = graph[i][j];

    // Add all vertices one by one to the set of intermediate vertices
    for (k = 0; k < n; k++) {
        // Pick all vertices as source one by one
        for (i = 0; i < n; i++) {
            // Pick all vertices as destination for the above picked source
            for (j = 0; j < n; j++) {
                // If vertex k is on a path from i to j, then set reach[i][j] as 1
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }

    printSolution(reach, n);
}

int main() {
    int n;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    int graph[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix representing the directed graph (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    transitiveClosure(graph, n);

    return 0;
}
