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
#include <vector>
#include <string>
#include <iomanip>	// setw
#include <functional> // std::greater

using std::priority_queue;
using std::setw;
using std::string;

class Person
{
  public:
	string name;
	int age;

	Person(){};

	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
};

struct PersonComparator
{
	bool operator()(Person &p1, Person &p2)
	{
		return p1.age < p2.age;
	}
};

int main(int argc, char const *argv[])
{
	priority_queue<int> q;

	int len, i, j, value;

	for (i = 0; i < 10; i++)
	{
		q.push(i);
	}

	// Sadly there is no iterator for queue :(
	while (!q.empty())
	{
		value = q.top();
		q.pop();
		std::cout << value << " ";
	}

	std::cout << std::endl;

	// Using other means to compare
	priority_queue<Person, std::vector<Person>, PersonComparator> qu;

	Person p1("John", 19), p2("Lukas", 30), p3("Eliza", 73), p4("Ross", 22), p5("Claire", 25), p6("Viktor", 55);

	qu.push(p1);
	qu.push(p2);
	qu.push(p3);
	qu.push(p4);
	qu.push(p5);
	qu.push(p6);

	Person top;

	std::cout << "\n   Higher Priority\n" << std::endl;

	while (!qu.empty())
	{
		top = qu.top();
		std::cout << setw(10) << top.name << setw(5) << top.age << std::endl;
		qu.pop();
	}

	std::cout << "\n   Lower Priority" << std::endl;

	return 0;
}
