// rpi_1_dijkstra.h

#define MAX_NODES 100
#define INF INT_MAX

extern int graph[MAX_NODES][MAX_NODES];
extern int numNodes;

void readGraph(const char *filename);
void findShortestPath(int source, int destination, char buffer[], int *len);