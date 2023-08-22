#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "rpi_1_dijkstra.h"

int graph[MAX_NODES][MAX_NODES];
int numNodes;

void readGraph(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fscanf(file, "%d", &numNodes);

    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            fscanf(file, "%d", &graph[i][j]);
        }
    }

    fclose(file);
}

void findShortestPath(int source, int destination, char buffer[], int *len) {
    int dist[MAX_NODES];
    int visited[MAX_NODES];
    int prev[MAX_NODES];
    for (int i = 0; i < numNodes; i++) {
        dist[i] = INF;
        visited[i] = 0;
        prev[i] = -1;
    }

    dist[source] = 0;

    for (int count = 0; count < numNodes - 1; count++) {
        int u = -1;
        for (int i = 0; i < numNodes; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < numNodes; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }

    *len = 0;
    
    int currentNode = destination;
    while (currentNode != -1) {
        (*len) += snprintf(buffer + (*len), MAX_NODES - (*len), "%d", currentNode);
        currentNode = prev[currentNode];
    }

}