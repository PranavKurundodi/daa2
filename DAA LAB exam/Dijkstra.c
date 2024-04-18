#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100 // Max number of vertices

int minDistance(int dist[], int sptSet[], int numVertices) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < numVertices; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void printSolution(int dist[], int numVertices) {
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < numVertices; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int src, int numVertices) {
    int dist[MAX_VERTICES]; // The output array. dist[i] will hold the shortest distance from src to i
    int sptSet[MAX_VERTICES]; // sptSet[i] will be true if vertex i is included in shortest path tree or shortest distance from src to i is finalized

    for (int i = 0; i < numVertices; i++)
        dist[i] = INT_MAX, sptSet[i] = 0;

    dist[src] = 0; // Distance of source vertex from itself is always 0

    for (int count = 0; count < numVertices - 1; count++) {
        int u = minDistance(dist, sptSet, numVertices);
        sptSet[u] = 1;
        for (int v = 0; v < numVertices; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist, numVertices);
}

int main() {
    int numVertices;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    int graph[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix representing the weighted graph (%d x %d):\n", numVertices, numVertices);
    for (int i = 0; i < numVertices; i++)
        for (int j = 0; j < numVertices; j++)
            scanf("%d", &graph[i][j]);

    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, src, numVertices);

    return 0;
}
