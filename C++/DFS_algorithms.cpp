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

	// A recursive function used by DFS 
	void DFS_helper(int v, bool visited[]); 
    public: 
	    Graph(int V); // Constructor
	    void addEdge(int v, int w); // connect the node v and w
	    void DFS(int v);
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
void Graph::DFS_helper(int v,bool visited[]) 
{
	visited[v] = true;
	cout << v << " ";
	list<int>::iterator i; 
	for (i = adj[v].begin();i != adj[v].end();++i)
		if (!visited[*i])
			DFS_helper(*i, visited);
}
void Graph::DFS(int v)
{ 
	bool *visited = new bool[V];  //create array of type bool check whether a node is visited or not
	for (int i=0;i<V;i++)
		visited[i]=false;
    

    // It may be possible that draph may be disconnect
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            DFS_helper(i,visited);  // helper function for travarsal of graph using dfs
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
    cout<<"Depth First Traversal from vertex 2\n";
	graph.DFS(2);
    cout<<"\n";
	return 0; 
} 