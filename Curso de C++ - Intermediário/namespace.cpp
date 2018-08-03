/**
 * @file namespace.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 02/08/2018
 * 
 * Explaining templates
 */
#include <iostream>
#include <list>
#include <string>

namespace my_namespace
{

template <class T>
class list
{
	T element;

  public:
	list()
	{
		std::cout << "Hey! This is my implementation of a list!" << std::endl;
	}
};

const std::string namespace_name = "my_namespace";

} // namespace my_namespace

namespace another_namespace
{
	const std::string namespace_name = "another_namespace";
}

int main(int argc, char const *argv[])
{
	std::list<int> list;
	my_namespace::list<int> my_list;

	std::cout << "Namespace name: " << my_namespace::namespace_name << std::endl;
	std::cout << "Namespace name: " << another_namespace::namespace_name << std::endl;

	return 0;
}
