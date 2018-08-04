/**
 * @file deque.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 03/08/2018
 * 
 * Working with stl deque
 */
#include <iostream>
#include <deque>

using std::deque;

int main(int argc, char const *argv[])
{
	deque<int> dqueue;

	if (dqueue.empty())
		std::cout << "Deque is empty" << std::endl;

	for (int i = 0; i < 8; i++)
		dqueue.push_back(i);

	for (int i = 0; i < 8; i++)
		dqueue.push_front(i);

	deque<int>::iterator it = dqueue.begin();

	while (it != dqueue.end())
	{
		std::cout << *it++ << " ";
	}

	std::cout << "\n\n";

	dqueue.clear();

	for (int i = 0; i < 20; i++)
	{
		if (i % 2 == 0)
			dqueue.push_back(i);
		else
			dqueue.push_front(i);
	}

	it = dqueue.begin();

	while (it != dqueue.end())
	{
		std::cout << *it++ << " ";
	}

	return 0;
}
