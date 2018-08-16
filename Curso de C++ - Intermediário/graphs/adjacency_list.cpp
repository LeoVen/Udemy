/**
 * @file adjacency_list.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 16/08/2018
 * 
 * Adjacency List
 */
#include <iostream>
#include <list>
#include <algorithm> // find

// A directed graph
class Graph
{
	int V;				 // Vertex number
	std::list<int> *adj; // Adjacency list
  public:
	Graph(int V);						// Constructor where V = number of vertices
	~Graph();							// Destructor
	void add(int v1, int v2);			// Adds an edge connecting v1 and v2
	int get_indegree(int v);			// Returns indegree of vertex v
	int get_outdegree(int v);			// Returns outdegree of vertex v
	bool are_connected(int v1, int v2); // Returns true if v1 points to v2, false otherwise
};

Graph::Graph(int V)
{
	this->V = V;
	this->adj = new std::list<int>[V];
}

Graph::~Graph()
{
	delete this->adj;
}

void Graph::add(int v1, int v2)
{
	this->adj[v1].push_back(v2);
}

int Graph::get_indegree(int v)
{
	int total = 0;

	for (int i = 0; i < this->V; i++)
	{
		if (this->are_connected(i, v))
			total++;
	}

	return total;
}

int Graph::get_outdegree(int v)
{
	return this->adj[v].size();
}

bool Graph::are_connected(int v1, int v2)
{
	if (find(this->adj[v1].begin(), this->adj[v1].end(), v2) != this->adj[v1].end())
		return true;

	return false;
}

int main(int argc, char const *argv[])
{
	/**
	 * 0 -> 1
	 * 0 -> 3
	 * 1 -> 2
	 * 3 -> 1
	 * 3 -> 2
	 * 
	 */

	Graph g(4);

	// From -> To
	g.add(0, 1);
	g.add(0, 3);
	g.add(1, 2);
	g.add(3, 1);
	g.add(3, 2);

	for (int i = 0; i < 4; i++)
	{
		std::cout << "Vertex " << i << ": In: " << g.get_indegree(i) << " Out: " << g.get_outdegree(i) << std::endl;
	}

	return 0;
}
