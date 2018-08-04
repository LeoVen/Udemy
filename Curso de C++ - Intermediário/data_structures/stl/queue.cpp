/**
 * @file queue.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 03/08/2018
 * 
 * Working with stl queue
 */
#include <iostream>
#include <queue>

using std::queue;

int main(int argc, char const *argv[])
{
	queue<int> q;
	int len, i, j, value;

	std::cout << "First-in, first-out\n" << std::endl;

	for (i = 0; i < 10; i++)
	{
		q.push(i);
		len = q.size();

		// Sadly there is no iterator for queue :(
		for (j = 0; j < len; j++)
		{
			value = q.front();
			q.pop();
			std::cout << value << " ";
			q.push(value);
		}

		std::cout << std::endl;
	}

	while (!q.empty())
	{
		q.pop();
		len = q.size();

		for (j = 0; j < len; j++)
		{
			value = q.front();
			q.pop();
			std::cout << value << " ";
			q.push(value);
		}

		std::cout << std::endl;
	}

	return 0;
}
