#include <stdio.h>
#include <conio.h>
#define MAX 100
struct Edge
{
    int u, v, weight;
};
int parent[MAX];
int rank[MAX];
/* Find operation */
int find(int i)
{
    if (parent[i] != i)
        parent[i] = find(parent[i]);
    return parent[i];
}
/* Union operation */
void unionSet(int x, int y)
{
    int rootX, rootY;
    rootX = find(x);
    rootY = find(y);
    if (rootX != rootY)
    {
        if (rank[rootX] < rank[rootY])
           parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}
/* Sort edges using Bubble Sort */
void sortEdges(struct Edge edges[], int edgeCount)
{
    int i, j;
    struct Edge temp;

    for (i = 0; i < edgeCount - 1; i++)
    {
        for (j = 0; j < edgeCount - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

/* Kruskal's Algorithm */
void kruskal(struct Edge edges[], int vertices, int edgeCount)
{
    int i;
    int u, v;
    int edgeSelected = 0;
    int mstWeight = 0;
    /* Make Set */
    for (i = 0; i < vertices; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
    /* Sort edges */
    sortEdges(edges, edgeCount);
    printf("\nMinimum Spanning Tree:\n");
    printf("\nEdge\tWeight\n");
    printf("----------------\n");
    for (i = 0; i < edgeCount; i++)
    {
        u = edges[i].u;
        v = edges[i].v;
        /* Check for cycle */
        if (find(u) != find(v))
        {
            printf("%d - %d\t%d\n",
                   u + 1, v + 1, edges[i].weight);
            mstWeight = mstWeight + edges[i].weight;
            edgeSelected++;
            unionSet(u, v);
            /* MST has V-1 edges */
            if (edgeSelected == vertices - 1)
                break;
        }
    }
    printf("----------------\n");
    if (edgeSelected == vertices - 1)
        printf("Minimum Cost = %d", mstWeight);
    else
        printf("MST cannot be formed.");
}
void main()
{
    struct Edge edges[MAX];
    int vertices, edgeCount;
    int i;
    clrscr();
    printf("KRUSKAL'S ALGORITHM\n");
    printf("===================\n");
    printf("\nEnter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edgeCount);
    if (vertices > MAX || edgeCount > MAX)
    {
        printf("\nMaximum limit exceeded!");
        getch();
        return;
    }
    printf("\nEnter edges as: Source Destination Weight\n");
    for (i = 0; i < edgeCount; i++)
    {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d",
              &edges[i].u,
              &edges[i].v,
              &edges[i].weight);
        /* Convert to 0-based indexing */
        edges[i].u--;
        edges[i].v--;
    }
    kruskal(edges, vertices, edgeCount);
    getch();
}

