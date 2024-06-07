#include <iostream>
#include <vector>
using namespace std;

const int MAX = 5;
const int LIMIT = 100; 

void matrix(int graph[MAX][MAX])
{
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            graph[i][j] = LIMIT; 
        }
    }
}

void addEdge(int graph[MAX][MAX], int u, int v, int weight)
{
    graph[u][v] = weight;
}

void print(int graph[MAX][MAX])
{
    for (int i = 0; i < MAX; ++i) {
        cout << "vertex " << i << " : -> ";
        bool first = true;
        for (int j = 0; j < MAX; ++j) {
            if (graph[i][j] != LIMIT) {
                if (!first) {
                    cout << " -> ";
                }
                cout << " (" << j << ", " << graph[i][j] << ")";
                first = false;
            }
        }
        cout << endl;
    }
}

int main()
{
    int graph[MAX][MAX];

    matrix(graph);

    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 4, 20);
    addEdge(graph, 1, 2, 30);
    addEdge(graph, 1, 3, 40);
    addEdge(graph, 1, 4, 50);
    addEdge(graph, 2, 3, 60);
    addEdge(graph, 3, 4, 70);

    cout << "Weighted Graph :" << endl;
    print(graph);

    return 0;
}

