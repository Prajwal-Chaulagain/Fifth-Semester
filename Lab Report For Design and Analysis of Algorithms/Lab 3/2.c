// Write a c program to implement for Kruskal Algorithm.    
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Edge
{
    int src, dest, weight;
};

struct Subset
{
    int parent;
    int rank;
};

int find(struct Subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y)
{
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else
    {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

int compare(const void *a, const void *b)
{
    struct Edge *e1 = (struct Edge *)a;
    struct Edge *e2 = (struct Edge *)b;
    return e1->weight - e2->weight;
}

void kruskal(struct Edge edges[], int V, int E)
{
    qsort(edges, E, sizeof(edges[0]), compare);

    struct Subset subsets[V];
    for (int v = 0; v < V; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    struct Edge result[V];
    int e = 0; // result index
    int i = 0; // sorted edges index
    while (e < V - 1 && i < E)
    {
        struct Edge next = edges[i++];

        int x = find(subsets, next.src);
        int y = find(subsets, next.dest);

        if (x != y)
        {
            result[e++] = next;
            Union(subsets, x, y);
        }
    }
    printf("Edges in MST:\n");
    int total = 0;
    for (i = 0; i < e; i++)
    {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        total += result[i].weight;
    }
    printf("Total cost of MST = %d\n", total);
}

int main()
{
    int V, E;
    clock_t start, end;
    double cpu_time_used;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);
    struct Edge edges[E];
    printf("Enter each edge (src dest weight):\n");
    for (int i = 0; i < E; i++)
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    kruskal(edges, V, E);
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}
