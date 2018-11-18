#include <iostream>
#include <algorithm>
#include <vector>

int greedy_coins(std::vector<int>& coins, int change)
{
	int temp, N = 0;

	int length = coins.size();

	for (int i = length - 1; i >= 0; i--)
	{
		temp = change / coins[i];

		change -= temp * coins[i];

		N += temp;
	}

	return N;
}

int main(int argc, char const *argv[])
{
	std::vector<int> coins;

	int N = 26;
	
	coins.push_back(20);
	coins.push_back(1);
	coins.push_back(5);
	coins.push_back(10);
	coins.push_back(2);
	
	std::sort(coins.begin(), coins.end());

	std::cout << "Available coins:" << std::endl;

	for(auto var : coins)
	{
		std::cout << "Coin " << var << std::endl;
	}

	std::cout << "Amount of coins: " << greedy_coins(coins, N) << std::endl;

	return 0;
}
