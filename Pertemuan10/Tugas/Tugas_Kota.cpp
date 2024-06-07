#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 100;

void floydWarshall(int M, int graph[MAX][MAX]) 
{
    for (int k = 0; k < M; k++) 
    {
        for (int i = 0; i < M; i++) 
        {
            for (int j = 0; j < M; j++) 
            {
                if (graph[i][k] + graph[k][j] < graph[i][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}


int cost(const vector<int>& variations, int M, int graph[MAX][MAX]) {
    int cost = 0;
    for (int i = 0; i < M - 1; i++) {
        cost += graph[variations[i]][variations[i + 1]];
    }
    cost += graph[variations[M - 1]][variations[0]]; 
    return cost;
}

void minimum(vector<int>& variations, int index, int M, int& minCost, int graph[MAX][MAX]) {
    if (index == M) {
        minCost = min(minCost, cost(variations, M, graph));
        return;
    }
    for (int i = index; i < M; i++) {
        swap(variations[i], variations[index]);
        minimum(variations, index + 1, M, minCost, graph);
        swap(variations[i], variations[index]);
    }
}

int main()
{
    int M;
    cout << "Masukkan Jumlah Kota : ";
    cin >> M;
    
    int graph[MAX][MAX];
    memset (graph, 0x3f, sizeof graph);
    
    cout << "Nilai Cost Matrix\n";
        
    for (int i = 0; i < M; i++) 
    {
        cout << "Cost Element Baris ke -  "<< i + 1 << endl;
            for (int j = 0; j < M; j++) 
            {
                int w;
                cin >> w;
                graph[i][j] = w;
            }
    }

    cout << "\nConst List : " << endl;
    for (int i = 0; i < M; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            cout << "\t" << graph[i][j] << " ";
        }
        cout << endl;
    }
    
    floydWarshall(M, graph);
    
    int start = 0;
    int end = M - 1;
    int initialize = -1;
    int min_cost = MAX;

    for (int i = 1; i < M - 1; i++) {
        int cost = graph[start][i] + graph[i][end] + graph[end][start];
        if (cost < min_cost) {
            min_cost = cost;
            initialize = i;
        }
    }

	cout << "\nJalur Terpendek : " << start + 1;
	if (initialize != -1) {
		cout << " ---> " << end << " --> " << initialize + 1 << " ---> " << end + 1 << " ---> " << start  + 1;
	}

    vector<int> variations(M);
    for (int i = 0; i < M; i++) {
        variations[i] = i;
    }

    int minCost = MAX;
    minimum(variations, 0, M, minCost, graph);

    cout << "\nMinimum Cost: " << minCost << endl;

    return 0;
}

