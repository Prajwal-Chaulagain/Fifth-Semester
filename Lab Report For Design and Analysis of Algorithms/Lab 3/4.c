// Write a c program to implement for Dijkstra Algorithm.
#include <stdio.h>
#include <limits.h>
#include <time.h>

#define MAX 100

int minDistance(int dist[], int visited[], int V)
{
    int min = INT_MAX, min_index;

    for (int i = 0; i < V; i++)
        if (!visited[i] && dist[i] <= min)
        {
            min = dist[i];
            min_index = i;
        }

    return min_index;
}

void dijkstra(int graph[MAX][MAX], int V, int src)
{
    int dist[V];
    int visited[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited, V);
        visited[u] = 1;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] &&
                graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);
}

int main()
{
    int V, src;
    int graph[MAX][MAX];
    clock_t start, end;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &src);

    start = clock();

    dijkstra(graph, V, src);

    end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", time_taken);

    return 0;
}
