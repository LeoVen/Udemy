/**
 * @file static.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 03/08/2018
 * 
 * Using static keyword
 */
#include <iostream>

// Notice how once declared, the variable value won't change after the scope is changed
int next()
{
	static int number = 0;
	return number++;
}

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << next() << " ";
	}


	return 0;
}
