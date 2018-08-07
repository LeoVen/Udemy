/**
 * @file set.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 06/08/2018
 * 
 * Working with stl set
 */
#include <iostream>
#include <set>

using std::set;

int main(int argc, char const *argv[])
{
	int vet[10] = {1, 2, 4, 1, 3, 4, 5, 8, 2, 9};

	set<int> myset(vet, vet + 10);

	set<int>::iterator it = myset.begin();

	while (it != myset.end())
	{
		std::cout << *it++ << " ";
	}

	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
	{
		it = myset.find(i);

		if (it != myset.end())
			std::cout << "The element " << *it << " is in the set" << std::endl;
		else
			std::cout << "The element " << i << " is not in the set" << std::endl;

	}

	return 0;
}
