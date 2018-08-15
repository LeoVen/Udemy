/**
 * @file intro.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 14/08/2018
 * 
 * Intro to graphs
 */
#include <iostream>

int matrix[5][5] =
{
	{0, 0, 1, 0, 0},
	{0, 0, 1, 0, 0},
	{1, 1, 0, 1, 1},
	{0, 0, 1, 0, 1},
	{0, 0, 1, 1, 0}
};

bool is_connected(int X, int Y)
{
	return matrix[X][Y] == 1;
}

int main(int argc, char const *argv[])
{
	/**
	 * In the matrix:
	 * A = 0
	 * B = 1
	 * C = 2
	 * D = 3
	 * E = 4
	 *
	 * 
	 *     ( A )                        ( D )─┐
	 *       └────────┐ ┌─────────────────┘   │
	 *               ( C )                    │
	 *       ┌────────┘ └─────────────────┐   │
	 *     ( B )                        ( E )─┘
	 * 
	 */
	

	int A = 0, B = 1, C = 2, D = 3, E = 4;
	
	std::cout << "Is A and E connected? " << (is_connected(A, E) ? "Yes" : "No") << std::endl;
	std::cout << "Is C and B connected? " << (is_connected(C, B) ? "Yes" : "No") << std::endl;
	std::cout << "Is D and E connected? " << (is_connected(D, E) ? "Yes" : "No") << std::endl;
	std::cout << "Is B and D connected? " << (is_connected(B, D) ? "Yes" : "No") << std::endl;
	std::cout << "Is A and C connected? " << (is_connected(A, C) ? "Yes" : "No") << std::endl;

	return 0;
}
