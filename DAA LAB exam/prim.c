#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100 // Max number of vertices

int minKey(int key[], int mstSet[], int numVertices) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < numVertices; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void printMST(int parent[], int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < numVertices; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    int parent[MAX_VERTICES]; // Array to store constructed MST
    int key[MAX_VERTICES]; // Key values used to pick minimum weight edge in cut
    int mstSet[MAX_VERTICES]; // To represent set of vertices not yet included in MST

    for (int i = 0; i < numVertices; i++)
        key[i] = INT_MAX, mstSet[i] = 0;

    key[0] = 0; // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of MST

    for (int count = 0; count < numVertices - 1; count++) {
        int u = minKey(key, mstSet, numVertices);
        mstSet[u] = 1;

        for (int v = 0; v < numVertices; v++)
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph, numVertices);
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

    primMST(graph, numVertices);

    return 0;
}
