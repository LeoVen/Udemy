/**
 * @file dfs.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 16/08/2018
 * 
 * Depth First Search
 */
#include <iostream>
#include <list>
#include <stack> // For DFS

class Graph
{
	int V;				 // Vertex number
	std::list<int> *adj; // Adjacency list
  public:
	Graph(int V);			  // Constructor where V = number of vertices
	~Graph();				  // Destructor
	void add(int v1, int v2); // Adds an edge connecting v1 and v2
	void dfs(int v);		  // Interactive DFS that starts with root v
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

void Graph::dfs(int v)
{
	std::stack<int> s;	   // Stack used for DFS
	bool visited[this->V]; // Array of visited vertices

	for (int i = 0; i < this->V; i++)
		visited[i] = false;

	while (true)
	{
		// If the given vertex was not visited, print a message and push it to the stack
		if (!visited[v])
		{
			std::cout << "Visiting " << v << std::endl;
			visited[v] = true;
			s.push(v); // Add to the stack
		}

		bool found = false;
		std::list<int>::iterator it;

		// Find someone that this vertex points to that has not been visited yet
		for (it = adj[v].begin(); it != adj[v].end(); it++)
		{
			if (!visited[*it])
			{
				found = true;

				break;
			}
		}

		// If it found someone then v is the next vertex
		// If stack is empty end of dfs
		// If not found and stack is not empty, pop from stack and backtrack
		if (found)
			v = *it;
		else
		{
			s.pop();

			if (s.empty())
				break;

			v = s.top();
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
	g.dfs(0);

	std::cout << "\n\n";

	// Subtree
	g.dfs(2);

	return 0;
}
