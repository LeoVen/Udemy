/**
 * @file map.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 03/08/2018
 * 
 * Working with stl map
 */
#include <iostream>
#include <map>
#include <string>
#include <iomanip> // setw

using std::map;
using std::multimap;
using std::setw;
using std::string;

int main(int argc, char const *argv[])
{
	// My shopping cart
	// C++ 11 only
	map<string, double> cart = {
		{"lemon", 2.7},
		{"milk", 4.1},
		{"cookies", 1.5}};

	cart["soda"] = 2.5;
	cart["orange"] = 0.8;
	cart["steak"] = 9.9;

	map<string, double>::iterator it = cart.begin();

	std::cout << setw(10) << "Consumable" << setw(10) << "Price" << std::endl;
	std::cout << setw(10) << "----------" << setw(10) << "----------" << std::endl;

	while (it != cart.end())
	{
		std::cout << setw(10) << it->first << setw(10) << it->second << std::endl;
		it++;
	}

	std::cout << "\n";

	if (cart.count("soda") > 0)
	{
		cart.at("soda") = 2.2;
		std::cout << "The new value of soda is " << cart.at("soda") << std::endl;
	}

	if (cart.count("orange") > 0)
		std::cout << "orange is mapped" << std::endl;
	else
		std::cout << "orange is not mapped" << std::endl;

	if (cart.count("vodka") > 0)
		std::cout << "vodka is mapped" << std::endl;
	else
		std::cout << "vodka is not mapped" << std::endl;

	// find() returns an iterator
	if (cart.count("milk") > 0)
	{
		std::cout << "Removing milk" << std::endl;
		it = cart.find("milk");
		cart.erase(it);
	}

	std::cout << "\n";

	it = cart.begin();

	std::cout << setw(10) << "Consumable" << setw(10) << "Price" << std::endl;
	std::cout << setw(10) << "----------" << setw(10) << "----------" << std::endl;

	while (it != cart.end())
	{
		std::cout << setw(10) << it->first << setw(10) << it->second << std::endl;
		it++;
	}

	std::cout << "\n";

	it = cart.find("pork");

	if (it != cart.end())
		std::cout << "There is pork in the cart" << std::endl;
	else
		std::cout << "There is no pork in the cart" << std::endl;

	cart.insert({"pork", 5.7});

	it = cart.find("pork");

	if (it != cart.end())
		std::cout << "Now there is pork in the cart" << std::endl;
	else
		std::cout << "Now there is no pork in the cart" << std::endl;

	it = cart.begin();

	std::cout << "\n";

	std::cout << setw(10) << "Consumable" << setw(10) << "Price" << std::endl;
	std::cout << setw(10) << "----------" << setw(10) << "----------" << std::endl;

	while (it != cart.end())
	{
		std::cout << setw(10) << it->first << setw(10) << it->second << std::endl;
		it++;
	}

	std::cout << "\n";

	// multimap

	multimap<int, string> numbers = {
		{1, "one"},
		{1, "ein"},
		{2, "two"},
		{2, "zwei"},
		{3, "three"},
		{3, "drei"},
		{4, "four"},
		{4, "vier"},
		{5, "five"},
		{5, "funf"},
		{6, "six"},
		{6, "sechs"},
		{7, "seven"},
		{7, "sieben"}
	};

	multimap<int, string>::iterator iter = numbers.find(11);

	if (iter != numbers.end())
		std::cout << iter->second << std::endl;

	iter = numbers.find(4);
	
	if (iter == numbers.end())
		std::cout << "4 Is not mapped" << std::endl;

	std::cout << "\n";

	for (iter = numbers.begin(); iter != numbers.end(); iter++)
	{
		std::cout << setw(5) << iter->first << " -> " << setw(10) << iter->second << std::endl;
	}

	std::cout << "\n";

	multimap<int, string>::iterator lower, upper;

	upper = numbers.upper_bound(2);
	lower = numbers.lower_bound(6);

	for (iter = upper; iter != lower; iter++)
	{
		std::cout << setw(5) << iter->first << " -> " << setw(10) << iter->second << std::endl;
	}

	return 0;
}
