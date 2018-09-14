/**
 * @file kadane.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 14/09/2018
 * 
 * Kadane algorithm O(n)
 * Maximum subarray problem
 */
#include <iostream>
#include <vector>

int kadane(std::vector<int>& vec)
{
	int max_curr = 0, max_total = -1;
	int vec_size = vec.size();

	for(int i = 0; i < vec_size; i++)
	{
		max_curr += vec[i];

		if (max_curr < 0)
			max_curr = 0;
		
		if (max_curr > max_total)
			max_total = max_curr;
	}
	
	return max_total;
}

int main(int argc, char const *argv[])
{
	std::vector<int> vec = {-2, 5, -1, 2, -3};

	std::cout << "Maximum subarray is " << kadane(vec) << std::endl;

	return 0;
}


