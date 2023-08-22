#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 6 // 정점의 수

// 최단 경로를 찾기 위한 다이크스트라 알고리즘 함수
void findShortestPath(int graph[V][V], int start) {
    int distance[V];
    bool visited[V];

    // 초기화
    for (int i = 0; i < V; i++) {
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    distance[start] = 0;

    for (int count = 0; count < V - 1; count++) {
        int min_distance = INT_MAX;
        int min_index = -1;

        // 최소 거리의 정점 선택
        for (int v = 0; v < V; v++) {
            if (!visited[v] && distance[v] <= min_distance) {
                min_distance = distance[v];
                min_index = v;
            }
        }

        int u = min_index;
        visited[u] = true;

        // 선택한 정점과 연결된 정점들의 거리 갱신
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && distance[u] != INT_MAX &&
                distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    // 결과 출력
    printf("Vertex\tDistance from Start\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, distance[i]);
    }
}

int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0},
        {4, 0, 8, 0, 0, 0},
        {0, 8, 0, 7, 0, 4},
        {0, 0, 7, 0, 9, 14},
        {0, 0, 0, 9, 0, 10},
        {0, 0, 4, 14, 10, 0}
    };

    int start = 0; // 시작 정점

    dijkstra(graph, start);

    return 0;
}