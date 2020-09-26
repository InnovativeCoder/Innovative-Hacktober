#include<iostream>
using namespace std;
const int V = 5; 

int getMinKey(int key[], bool isPresent[]) {
    int min = INT16_MAX, minIdx = -1;
    for(int i = 0;i < V;i++) {
        if(min > key[i] && isPresent[i] == false) {
            min = key[i];
            minIdx = i;
        }
    }
    return minIdx;
} 

void displayMST(int graph[][V], int parent[]) {
    for(int i = 1;i < V;i++) {
        cout<<parent[i]<<" "<<i<<" "<<graph[i][parent[i]]<<endl;
    }
}

void primMST(int graph[][V]) {
    int parent[V], key[V];
    bool visited[V];
    for(int i = 0;i < V;i++) {
        key[i] = INT16_MAX;
        visited[i] = false;
    }
    parent[0] = -1;
    key[0] = 0;
    for(int i = 0;i < V - 1;i++) {
        int u = getMinKey(key, visited);
        visited[u] = true;
        for(int j = 0;j < V;j++) {
            if(graph[u][j] && key[j] > graph[u][j] && visited[j] == false) {
                parent[j] = u;
                key[j] = graph[u][j];
            }
        }
    }
    displayMST(graph, parent);
}


int main() {
    int graph[V][V] = { 
        { 0, 2, 0, 6, 0 },
        { 2, 0, 3, 8, 5 },
        { 0, 3, 0, 0, 7 },
        { 6, 8, 0, 0, 9 },
        { 0, 5, 7, 9, 0 }
    };
    primMST(graph);
    return 0;
}
