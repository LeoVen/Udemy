/**
 * @file search.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 03/09/2018
 * 
 * URI problem 1905.
 */
#include <iostream>
#include <vector>

class Coord
{
	public:
	int x, y;
	bool visited;
};

int winner;

// i - row
// j - column
void search(std::vector<std::vector<int> > mat, std::vector<std::vector<Coord> > coord, int i, int j)
{
	if (i >= 0 && i < 5 && j >= 0 && j < 5 && !winner)
	{
		coord[i][j].visited = true;

		if (i == 4 && j == 4)
			winner = 1;
		else
		{
			if (i + 1 < 5 && mat[i + 1][j] == 0 && !coord[i + 1][j].visited)
				search(mat, coord, i + 1, j);
			if (i - 1 >= 0 && mat[i - 1][j] == 0 && !coord[i - 1][j].visited)
				search(mat, coord, i - 1, j);
			if (j + 1 < 5 && mat[i][j + 1] == 0 && !coord[i][j + 1].visited)
				search(mat, coord, i, j + 1);
			if (j - 1 >= 0 && mat[i][j - 1] == 0 && !coord[i][j - 1].visited)
				search(mat, coord, i, j - 1);
		}
	}
}

int main(int argc, char const *argv[])
{
	int T;

	std::cin >> T;

	for (int i = 0; i < T; i++)
	{
		std::vector<std::vector<int> > matrix(5);
		std::vector<std::vector<Coord> > coord_matrix(5);

		for (int a = 0; a < 5; a++)
		{
			matrix[a].resize(5);

			coord_matrix[a].resize(5);
		}
		
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				int e;
				
				std::cin >> e;

				matrix[j][k] = e;

				coord_matrix[j][k].x = j;
				coord_matrix[j][k].y = k;
				coord_matrix[j][k].visited = false;
			}
		}

		winner = 0;

		search(matrix, coord_matrix, 0, 0);

		if (winner)
			printf("COPS\n");
		else
			printf("ROBBERS\n");
	}
	

	return 0;
}
