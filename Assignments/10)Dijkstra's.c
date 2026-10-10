
#include <stdio.h>

#define MAX 20
#define INF 999999

int main()
{
    int n, graph[MAX][MAX];
    int dist[MAX], visited[MAX];
    int source, i, j, count;
    int min, u;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter weighted adjacency matrix:\n");
    printf("(Enter 0 if there is no road)\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);

            if (graph[i][j] < 0)
            {
                printf("Negative weights are not allowed.\n");
                return 1;
            }
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);

    if (source < 0 || source >= n)
    {
        printf("Invalid source vertex.\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    for (count = 0; count < n; count++)
    {
        min = INF;
        u = -1;

        for (i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (j = 0; j < n; j++)
        {
            if (!visited[j] &&
                graph[u][j] > 0 &&
                dist[u] != INF &&
                dist[u] + graph[u][j] < dist[j])
            {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    printf("\nShortest distances from source %d:\n", source);
    printf("Destination\tDistance\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t\t", i);

        if (dist[i] == INF)
            printf("Unreachable\n");
        else
            printf("%d\n", dist[i]);
    }

    return 0;
}
