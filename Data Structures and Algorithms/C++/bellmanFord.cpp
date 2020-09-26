#include<iostream>
using namespace std;
const int V = 5;

void bellmanFord(int graph[V][V]) {
    int dist[V];
    for(int i = 0;i < V;i++) {
        dist[i] = INT16_MAX;
    }
    dist[0] = 0;

    for(int i = 0;i < V;i++) {
        for(int j = 0;j < V;j++) {
            if(graph[i][j] != 0 && dist[i] != INT16_MAX && graph[i][j] + dist[i] < dist[j]) {
                dist[j] = graph[i][j] + dist[i];
            }
        }
    }
    for(int i = 0;i < V;i++) {
        for(int j = 0;j < V;j++) {
            if(graph[i][j] != 0 && dist[i] != INT16_MAX && graph[i][j] + dist[i] < dist[j]) {
                cout<<"Graph contains negative weight cycle"<<endl;
            }
        }
    }
    for(int i = 0; i < V; i++) {
        cout<<i<<" "<<dist[i]<<endl;
    }
}

int main() {
    int graph[V][V] = {
        {0, -1, 4, 0, 0},
        {0, 0, 3, 2, 2},
        {0, 0, 0, 0, 0},
        {0, 1, 5, 0, 0},
        {0, 0, 0, -3, 0}
    };
    bellmanFord(graph);
	return 0;
}
