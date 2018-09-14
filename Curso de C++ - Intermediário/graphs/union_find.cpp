/**
 * @file union_find.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 14/09/2018
 * 
 * Union-find is a way to detect cycles in undirected graphs
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>

int Find(int *subset, int v)
{
	if (subset[v] == -1)
		return v;
	
	return Find(subset, subset[v]);
}

void Union(int *subset, int v1, int v2)
{
	int v1_set = Find(subset, v1);
	int v2_set = Find(subset, v2);

	subset[v1_set] = v2_set;
}

bool UnionFind(int graph[3][3])
{
	int *subset = (int*)malloc(sizeof(int) * 3);

	memset(subset, -1, sizeof(int) * 3);

	for (int i = 0; i < 3; i++)
	{
		for (int j = i; j < 3; j++)
		{
			if (graph[i][j] == 1)
			{
				int v1 = Find(subset, i);
				int v2 = Find(subset, j);

				if (v1 == v2)
				{
					free(subset);
				
					return true;
				}

				Union(subset, v1, v2);
			}
		}
	}

	free(subset);

	return false;
}

int main(int argc, char const *argv[])
{
	int graph[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	graph[0][1] = 1;
	graph[1][0] = 1;
	graph[1][2] = 1;
	graph[2][1] = 1;
	graph[0][2] = 1;
	graph[2][0] = 1;

	if (UnionFind(graph))
		std::cout << "The graph has a cycle" << std::endl;
	else
		std::cout << "The graph doesn't have a cycle" << std::endl;

	return 0;
}
