#include <bits/stdc++.h>

using namespace std;

vector <int> adjList[100001];

int n, counter = 0;

bool used[100001];

void dfs(int v){
	used[v] = true;
	for(auto i: adjList[v]){
		if(!used[i]){
			dfs(i);
		}
	}
}

void connected_comp(){
	for(int i = 0; i < n; i++)
		used[i] = false;
	for(int i = 0; i < n; i++){
		if(!used[i]){
			dfs(i);
			counter++;
		}
	}

	cout << counter << endl;
}

	


int main(){
	int m;
	cin >> n >> m;
	int from, to;
	for(int i = 0; i < m; i++){
		cin >> from >> to;
		adjList[from].push_back(to);
		adjList[to].push_back(from);
	}

	connected_comp();


	return 0;
}
