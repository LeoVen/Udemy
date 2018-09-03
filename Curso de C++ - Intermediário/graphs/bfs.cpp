/**
 * @file bfs.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 16/08/2018
 * 
 * Breadth First Search
 */
#include <iostream>
#include <list>
#include <queue> // For BFS

class Graph
{
	int V;				 // Number of vertices
	std::list<int> *adj; // Adjacency list
  public:
	Graph(int V);			  // Constructor where V = number of vertices
	~Graph();				  // Destructor
	void add(int v1, int v2); // Adds an edge connecting v1 and v2
	void bfs(int v);		  // Interactive BFS that starts with root v
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

void Graph::bfs(int v)
{
	std::queue<int> q;	   // Queue used for BFS
	bool visited[this->V]; // Array of visited vertices

	for (int i = 0; i < this->V; i++)
		visited[i] = false;

	// The root vertex is marked as visited
	std::cout << "Visiting " << v << std::endl;
	visited[v] = true;

	while (true)
	{
		std::list<int>::iterator it;

		// Go through all connections of v
		for (it = adj[v].begin(); it != adj[v].end(); it++)
		{
			// If not visited, mark as visited and enqueue
			if (!visited[*it])
			{
				std::cout << "Visiting " << *it << std::endl;
				visited[*it] = true;
				q.push(*it);
			}
		}

		// If queue is not empty, get next vertex
		// If queue is empty end of BFS
		if (!q.empty())
		{
			v = q.front();
			q.pop();
		}
		else
		{
			break;
		}
	}
}

int main(int argc, char const *argv[])
{
	/**
	 * Making a binary tree
	 * Root -> 0
	 */

	int V = 8;

	Graph g(V);

	// From -> To
	g.add(0, 1);
	g.add(1, 3);
	g.add(1, 4);
	g.add(0, 2);
	g.add(2, 5);
	g.add(2, 6);
	g.add(6, 7);

	// Root
	g.bfs(0);

	return 0;
}
