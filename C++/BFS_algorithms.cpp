// C++ program to print the DFS (Depth first search) of graph
#include<bits/stdc++.h>
#include<iostream> 
#include<list> 
using namespace std; 

//Graph class represent Directed graph
class Graph 
{ 
	int V; //no. of vertices

	// pointer to vector which store adjacency list
	list<int> *adj; 

	
    public: 
	    Graph(int V); // Constructor
	    void addEdge(int v, int w); // connect the node v and w
	    void BFS(int v);
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
}
void Graph::addEdge(int v,int w) 
{ 
	adj[v].push_back(w); //add the w to adjacency list of v
}
void Graph::BFS(int v)
{ 
	bool *visited = new bool[V];
	for(int i=0;i<V;i++){
		visited[i]=false;
	}
	list<int> queue;
	visited[v]=true;
	queue.push_back(v);
	list<int>::iterator i;
	while(!queue.empty()){
		v=queue.front();
		cout<<v<<" ";
		queue.pop_front();
		for(i=adj[v].begin();i!=adj[v].end();i++){
			if(!visited[*i]){
				visited[*i]=true;
				queue.push_back(*i);
			}
		}
	}
} 
int main() // main function
{
	Graph graph(4); 
	graph.addEdge(0,1);
	graph.addEdge(0,2);
	graph.addEdge(1,2);
	graph.addEdge(2,0);
	graph.addEdge(2,3);
	graph.addEdge(3,3);
    cout<<"Breadth First Traversal from vertex 2\n";
	graph.BFS(2);
    cout<<"\n";
	return 0; 
} 