#include <iostream>
#include <limits.h>
#define V 9
#define MAX INT_MAX

using namespace std;

int minimum(int dist[], bool path[])
{
    int min = MAX, index;

    for (int v = 0; v < V; v++)
        if (path[v] == false && dist[v] <= min)
            min = dist[v], index = v;

    return index;
}

void print(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t" << dist[i] << endl;
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V]; 

    bool path[V]; 

    for (int i = 0; i < V; i++)
        dist[i] = MAX, path[i] = false;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minimum(dist, path);
        path[u] = true;
        
        for (int v = 0; v < V; v++)
            if (!path[v] && graph[u][v]
                && dist[u] != MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    print(dist);
}

int main()
{
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph, 0);

    return 0;
}

