/**
 * @file stack.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 06/08/2018
 * 
 * Working with stl stack
 */
#include <iostream>
#include <stack>

using std::stack;

int main(int argc, char const *argv[])
{
	stack<int> mystack;

	std::cout << "Insertion Order" << std::endl;

	for (int i = 0; i < 10; i++)
	{
		mystack.push(i);

		std::cout << i << " ";
	}

	std::cout << std::endl;

	std::cout << "Removal Order" << std::endl;

	while (!mystack.empty())
	{
		std::cout << mystack.top() << " ";
		mystack.pop();
	}

	std::cout << std::endl;

	return 0;
}
