#include <iostream>
#include <list>
#include <queue>
#include <climits>

#define INFINITY INT_MAX

class Graph
{
  private:
	int V; // Number of vertices

	// pair: first is the destination and second is the cost
	std::list<std::pair<int, int> > *adj; // Adjacency list

  public:

	Graph(int V)
	{
		this->V = V;

		adj = new std::list<std::pair<int, int> >[V];
	}

	// From, to, cost
	void add(int v1, int v2, int cost)
	{
		// v1 connects to v2 with a cost
		adj[v1].push_back(std::make_pair(v2, cost));
	}

	int dijkstra(int orig, int dest)
	{
		// Distances array
		int dist[V];

		// Visited array
		int visited[V];

		// Priority queue to choose which vertices will be expanded
		std::priority_queue<std::pair<int, int>,
							std::vector<std::pair<int, int> >, 
							std::greater<std::pair<int, int> > > pq;

		for (int i = 0; i < V; i++)
		{
			dist[i] = INFINITY;
			visited[i] = false;
		}

		dist[orig] = 0;

		pq.push(std::make_pair(dist[orig], orig));

		//Algorith loop

		while (!pq.empty())
		{
			// Extracts the topmost pair
			std::pair<int, int> p = pq.top();

			int u = p.second;

			pq.pop();

			// Verify if the vertex was not expanded
			if (!visited[u])
			{
				visited[u] = true;

				std::list<std::pair<int, int> >::iterator it;

				for (it = adj[u].begin(); it != adj[u].end(); it++)
				{
					int v = it->first;
					int cost = it->second;

					if (dist[v] > dist[u] + cost)
					{
						// Update the distance of v
						dist[v] = dist[u] + cost;

						pq.push(std::make_pair(dist[v], v));
					}
				}
			}
		}

		// minimum distance to dest
		return dist[dest];
	}
};

int main(int argc, char const *argv[])
{
	Graph g(6);

	// From, to, cost
	g.add(0, 1, 10);
	g.add(0, 2, 15);
	g.add(1, 3, 12);
	g.add(1, 5, 15);
	g.add(2, 4, 10);
	g.add(3, 5, 1);
	g.add(3, 4, 2);
	g.add(5, 4, 5);

	std::cout << "From 0 to 4: " << g.dijkstra(0, 4) << std::endl;
	std::cout << "From 4 to 0: " << g.dijkstra(4, 0) << std::endl;
	std::cout << "From 1 to 5: " << g.dijkstra(1, 5) << std::endl;
	
	return 0;
}
