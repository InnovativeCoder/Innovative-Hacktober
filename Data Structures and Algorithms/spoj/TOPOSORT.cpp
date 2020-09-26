#include <bits/stdc++.h>

using namespace std;


vector <int> adjList[10001];
vector <bool> visited;
vector <int> ans;

void dfs(int v){
	visited[v] = true;
	for(auto u: adjList[v])
		if(!visited[u])
			dfs(u);
	ans.push_back(v);
}

void topological_sort(){
	visited.assing(n, false);
	ans.clear();
	for(int i = 1; i <= n; i++){
		if(!visited[i])
			dfs[i];
	}
	reverse(ans.begin(), ans.end());
}


int main(){
	int n, m;
	cin >> n >> m;

	for(int i =0 ; i < m; i++){
		cin >> from >> to;
		adjList[from].push_back(to);
	}
	




	return 0;
}
