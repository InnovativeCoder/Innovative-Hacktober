- Using std :: set :

void dijkstra(int v){
	fill(d,d + n, inf);
	d[v] = 0;
	int u;
	set<pair<int,int> > s;
	s.insert({d[v], v});
	while(!s.empty()){
		u = s.begin() -> second;
		s.erase(s.begin());
		for(auto p : adj[u]) //adj[v][i] = pair(vertex, weight)
			if(d[p.first] > d[u] + p.second){
				s.erase({d[p.first], p.first});
				d[p.first] = d[u] + p.second;
				s.insert({d[p.first], p.first});
			}
	}
}





- Using std :: priority_queue (better):

bool mark[MAXN];
void dijkstra(int v){
	fill(d,d + n, inf);
	fill(mark, mark + n, false);
	d[v] = 0;
	int u;
	priority_queue<pair<int,int>,vector<pair<int,int> >, less<pair<int,int> > > pq;
	pq.push({d[v], v});
	while(!pq.empty()){
		u = pq.top().second;
		pq.pop();
		if(mark[u])
			continue;
		mark[u] = true;
		for(auto p : adj[u]) //adj[v][i] = pair(vertex, weight)
			if(d[p.first] > d[u] + p.second){
				d[p.first] = d[u] + p.second;
				pq.push({d[p.first], p.first});
			}
	}
}
