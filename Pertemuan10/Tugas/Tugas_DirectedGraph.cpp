#include <iostream>
#include <vector>
using namespace std;

const int MAX = 5;
const int LIMIT = 100; 

void matrix(int graph[MAX][MAX])
{
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int graph[MAX][MAX], int u, int v)
{
    graph[u][v] = 1;
}

void print(int graph[MAX][MAX])
{
     for (int i = 0; i < MAX; ++i) {
        cout << "vertex " << i << " : -> ";
        bool first = true;
        for (int j = 0; j < MAX; ++j) {
            if (graph[i][j] == 1) {
                if (!first) {
                    cout << " -> ";
                }
                cout << " " << j;
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

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    cout << "Directed Graph :" << endl;
    print(graph);

    return 0;
}

