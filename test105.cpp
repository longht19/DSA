/**
 * @file test105.cpp
 * @author long (you@domain.com)
 * @brief DFS directed graph
 * @version 0.1
 * @date 2023-04-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <bits/stdc++.h>
using namespace std;

// Graph class represents a directed graph
// using adjacency list representation
class Graph {
public:
	map<int, bool> visited;
	map<int, list<int> > adj;

	// function to add an edge to graph
	void addEdge(int v, int w);

	// DFS traversal of the vertices
	// reachable from v
	void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
    adj[w].push_back(v); // Add w to v's list
}

void Graph::DFS(int v)
{
	// Mark the current node as visited and
	// print it
	visited[v] = true;
	cout << v << " ";

	// Recur for all the vertices adjacent
	// to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFS(*i);
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        Graph g;
        int V, E, u;
        cin >> V >> E >> u;
        for(int i=0; i < E; i++) {
            int v, w;
            cin >> v >> w;
            g.addEdge(v,w);
        }
        g.DFS(u);
        cout << endl;
    }
	return 0;
}
