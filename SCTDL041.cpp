// A C++ Program to check whether a graph is tree or not
#include<iostream>
#include <list>
#include <limits.h>
using namespace std;

// Class for an undirected graph
class Graph
{
	int V; // No. of vertices
	int E; // No. of edges
	list<int> *adj; // Pointer to an array for adjacency lists
	void dfsTraversal(int v, bool visited[], int parent);
public:
	Graph(int V); // Constructor
	void addEdge(int v, int w); // to add an edge to graph
	bool isConnected(); // returns true if graph is connected
	bool isTree();	 // returns true of the graph is tree
    void printListEdges();
};

Graph::Graph(int V)
{
	E = 0;
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	E++;				 // increase the number of edges
	adj[v].push_back(w); // Add w to v’s list.
	adj[w].push_back(v); // Add v to w’s list.
}

// A recursive dfs function that uses visited[] and parent to
// traverse the graph and mark visited[v] to true for visited nodes
void Graph::dfsTraversal(int v, bool visited[], int parent)
{
	// Mark the current node as visited
	visited[v] = true;

	// Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
	{
		// If an adjacent is not visited, then recur for
		// that adjacent
		if (!visited[*i])
		{
		    dfsTraversal(*i, visited, v);
		}
	}
}

// Returns true if the graph is connected, else false.
bool Graph::isConnected()
{
	// Mark all the vertices as not visited and not part of
	// recursion stack
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Performing DFS traversal of the graph and marking
	// reachable vertices from 0 to true
	dfsTraversal(0, visited, -1);

	// If we find a vertex which is not reachable from 0
	// (not marked by dfsTraversal(), then we return false
	// since graph is not connected
	for (int u = 0; u < V; u++)
		if (!visited[u])
		return false;

	// since all nodes were reachable so we returned true and
	// and hence graph is connected
	return true;
}

bool Graph::isTree()
{
	// as we proved earlier if a graph is connected and has
	// V - 1 edges then it is a tree i.e. E = V - 1
	return isConnected() and E == V - 1;
}

void Graph::printListEdges() {
    list<int>::iterator i;
    for(int k = 0; k < this->V; k++) {
        cout << "D" << k+1 << ": ";
        for (i = adj[k].begin(); i != adj[k].end(); ++i)
        {
            cout << *i + 1 << " ";
        }
        cout << endl;
    }

}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int vertices, edges;
        cin >> vertices >> edges;
        Graph g(vertices);
        int u, v;
        for (int i = 0; i < edges; i++)
        {
            cin >> u >> v;
            g.addEdge(u-1,v-1);
        }
        g.printListEdges();
    }
	return 0;
}
