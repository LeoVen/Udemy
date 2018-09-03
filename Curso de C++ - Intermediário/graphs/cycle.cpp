/**
 * @file cycle.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 03/09/2018
 * 
 * Cycle detection in a graph
 */
#include <iostream>
#include <list>
#include <stack>

class Graph
{
	int V;				 // Number of vertices
	std::list<int> *adj; // Adjacency list
	bool dfs(int v);	 // Detects cycle
  public:
	Graph(int V);			  // Constructor where V = number of vertices
	~Graph();				  // Destructor
	void add(int v1, int v2); // Adds an edge connecting v1 to v2
	bool has_cycle();		  // Detects cycles from all vertices
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
	// For non-directed graph:
	// this->adj[v2].push_back(v1);
}

bool Graph::dfs(int v)
{
	std::stack<int> s;		// Stack used for DFS
	bool visited[this->V];  // Array of visited vertices
	bool in_stack[this->V]; // Array of vertices that ar in the stack to avoid searching in the stack

	for (int i = 0; i < this->V; i++)
		visited[i] = in_stack[i] = false;

	while (true)
	{
		// If the given vertex was not visited, push it to the stack
		if (!visited[v])
		{
			visited[v] = true;
			s.push(v); // Add to the stack
			visited[v] = in_stack[v] = true;
		}

		bool found = false;
		std::list<int>::iterator it;

		// Find someone that this vertex points to that has not been visited yet
		for (it = adj[v].begin(); it != adj[v].end(); it++)
		{
			// If neighbour is already in the stack then there is a cycle
			if (in_stack[*it])
				return true;
			else if (!visited[*it])
			{
				found = true;

				break;
			}
		}

		// If it found someone then v is the next vertex
		// If stack is empty end of dfs (no cycle)
		// If not found and stack is not empty, pop from stack and backtrack
		if (!found)
		{
			// Update in_stack
			in_stack[s.top()] = false;

			s.pop();

			if (s.empty())
				break;

			v = s.top();
		}
		else
			v = *it;
	}

	// No cycle found
	return false;
}

bool Graph::has_cycle()
{
	for (int i = 0; i < this->V; i++)
	{
		if (dfs(i))
			return true;
	}

	return false;
}

int main(int argc, char const *argv[])
{

	/**
	 *
	 * 0 -> 2
	 * 0 -> 1
	 * 1 -> 3
	 * 3 -> 0
	 *
	 */

	Graph graph(4);

	graph.add(0, 1);
	graph.add(0, 2);
	graph.add(1, 3);
	graph.add(3, 0);

	if (graph.has_cycle())
		std::cout << "\nThe graph has a cycle\n" << std::endl;
	else
		std::cout << "\nThe graph has no cycles\n" << std::endl;

	return 0;
}
