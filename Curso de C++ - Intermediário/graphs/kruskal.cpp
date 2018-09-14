/**
 * @file kruskal.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 14/09/2018
 * 
 * Kruskal algorithm O(E * log(V) ) -> [Edges, Vertices]
 * It is a greedy algorithm
 */
#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <string.h>  // memset
#include <string>

class Edge
{
	int src, dest, weight;

  public:
	Edge(int src, int dest, int weight)
	{
		this->src = src;
		this->dest = dest;
		this->weight = weight;
	}

	int get_src()
	{
		return this->src;
	}

	int get_dest()
	{
		return this->dest;
	}

	int get_weight()
	{
		return this->weight;
	}

	bool operator<(const Edge &comp) const
	{
		return (this->weight < comp.weight);
	}
};

class Graph
{
	int V;
	std::vector<Edge> edges;

  public:
	Graph(int V)
	{
		this->V = V;
	}

	void add(int src, int dest, int weight)
	{
		Edge e(src, dest, weight);
		edges.push_back(e);
	}

	int find(int *subset, int i)
	{
		if (subset[i] == -1)
			return i;

		return find(subset, subset[i]);
	}

	// union
	void merge(int *subset, int v1, int v2)
	{
		int v1_set = find(subset, v1);
		int v2_set = find(subset, v2);

		subset[v1_set] = v2_set;
	}

	void Kruskal()
	{
		std::vector<Edge> tree;
		int total = this->edges.size();

		// sort edges
		std::sort(this->edges.begin(), this->edges.end());

		// V subsets
		int *subset = new int[V];

		// set all positions to -1
		memset(subset, -1, sizeof(int) * this->V);

		for (int i = 0; i < total; i++)
		{
			int v1 = find(subset, this->edges[i].get_src());
			int v2 = find(subset, this->edges[i].get_dest());

			if (v1 != v2)
			{
				// no cycle
				tree.push_back(this->edges[i]);

				// Union
				this->merge(subset, v1, v2);
			}
		}

		int tree_size = tree.size();

		// Display result
		for (int i = 0; i < tree_size; i++)
		{
			char n1 = 'A' + tree[i].get_src();
			char n2 = 'A' + tree[i].get_dest();

			std::cout << "(" << n1 << ", " << n2 << ") = " << tree[i].get_weight() << std::endl;
		}

		delete subset;
	}
};

int main(int argc, char const *argv[])
{
	Graph g(7);

	/* A -> 0
	 * B -> 1
	 * C -> 2
	 * D -> 3
	 * E -> 4
	 * F -> 5
	 * G -> 6
	 */

	g.add(0, 1, 7);
	g.add(0, 3, 5);
	g.add(1, 2, 8);
	g.add(1, 3, 9);
	g.add(1, 4, 7);
	g.add(2, 4, 5);
	g.add(3, 4, 15);
	g.add(3, 5, 6);
	g.add(4, 5, 8);
	g.add(4, 6, 9);
	g.add(5, 6, 11);

	g.Kruskal();

	return 0;
}
