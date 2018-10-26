/**
 * @file knapsack.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 14/09/2018
 * 
 * 0/1 Knapsack dynamic programming problem
 * 
 * 0/1 means you either pick the item or not
 * 
 * Each element has a value V and a weight W
 * Goal: maximize the value of elements inside the knapsack
 * knapsack has a maximum capacity
 */
#include <iostream>

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int KnapSack(int W, int wt[], int val[], int n)
{
	// If no items or knapsack capacity 0
	if (n == 0 || W == 0)
		return 0;

	// Item weight is greater than knapsack capacity - do not include that item
	if (wt[n - 1] > W)
		return KnapSack(W, wt, val, n - 1);
	else
	{
		// Return the maximum of two cases:
		// (1) nth item included
		// (2) not included
		return max(	val[n - 1] +
					KnapSack(W - wt[n - 1], wt, val, n - 1),
					KnapSack(W, wt, val, n - 1));
	}
}

int main(int argc, char const *argv[])
{
	int W = 20;                           // Maximum weight
	int val[] = {3, 5, 8, 4, 10};         // Values of each item
	int wt[] = {2, 4, 5, 3, 9};           // Weights of each item
	int n = sizeof(val) / sizeof(val[0]); // Number of elements

	int max_value = KnapSack(W, wt, val, n);

	std::cout << "Maximum value: " << max_value << std::endl;

	return 0;
}
