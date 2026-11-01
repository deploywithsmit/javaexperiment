#include <stdio.h>
#include <conio.h>

#define N 6
#define M 3

int graph[N][N] = {
    {0,1,1,0,0,1},
    {1,0,1,1,0,0},
    {1,1,0,0,1,0},
    {0,1,0,0,1,1},
    {0,0,1,1,0,1},
    {1,0,0,1,1,0}
};

int color[N];

char *colorName[M] = {"Red", "Green", "Blue"};

int isSafe(int v, int c)
{
    int i;

    for (i = 0; i < N; i++)
    {
        if (graph[v][i] == 1 && color[i] == c)
            return 0;
    }

    return 1;
}

int mColoring(int v)
{
    int c;

    if (v == N)
        return 1;

    for (c = 1; c <= M; c++)
    {
        if (isSafe(v, c))
        {
            color[v] = c;

            if (mColoring(v + 1))
                return 1;

            color[v] = 0;
        }
    }

    return 0;
}

int main()
{
    int i;

    clrscr();

    if (mColoring(0))
    {
        printf("GRAPH COLOURING PROBLEM");
        printf("\n-----------------------\n\n");

        printf("Number of vertices = %d\n\n", N);

        for (i = 0; i < N; i++)
            printf("Vertex %d : %s\n", i + 1, colorName[color[i] - 1]);
    }
    else
    {
        printf("No valid coloring possible.");
    }

    printf("\n\nPress any key to exit...");
    getch();

    return 0;
}
