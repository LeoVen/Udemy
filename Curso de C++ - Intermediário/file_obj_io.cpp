/**
 * @file file_obj_io.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 06/08/2018
 * 
 * Writing objects in a file and retrieving its information
 */
#include <iostream>
#include <fstream> // ofstream & ifstream
#include <string>

using std::string;
using std::ofstream;
using std::ifstream;

class Person
{
  private:
	std::string name;
	int age;

  public:
	std::string &get_name()
	{
		return name;
	}

	int get_age()
	{
		return age;
	}

	std::string get_name() const
	{
		return name;
	}

	int get_age() const
	{
		return age;
	}

	void set_name(string &name)
	{
		this->name = name;
	}

	void set_age(int age)
	{
		this->age = age;
	}

	// Output stream
	friend std::ostream &operator<<(std::ostream &stream, const Person &p)
	{
		return stream << "\n" << p.get_name() << "\n" << p.get_age();
	}

	// Input stream
	friend std::istream &operator>>(std::istream &stream, Person &p)
	{
		return stream >> p.name >> p.age;
	}
};

int menu()
{
	std::cout << "\n\n1 - Add People" << std::endl;
	std::cout << "2 - List People" << std::endl;
	std::cout << "0 - Exit" << std::endl;

	int choice;

	std::cout << "> ";
	std::cin >> choice;

	Person p;
	string name;
	int age;

	if (choice == 1)
	{
		//app = append
		ofstream file("file.txt", std::fstream::app);

		std::cout << "Person's name: ";
		std::cin >> name;

		std::cout << "Person's age: ";
		std::cin >> age;

		p.set_name(name);
		p.set_age(age);

		file << p;

		file.close();
	}
	else if (choice == 2)
	{
		Person p;

		ifstream file("file.txt");

		std::cout << "\nListing people:" << std::endl;

		if (file.good())
		{
			while (!file.eof())
			{
				file >> p;

				std::cout << p;
			}
		}
		else
		{
			std::cout << "Failed to open file" << std::endl;
		}

		file.close();
	}
	else
	{
		return 0;
	}
	
	return choice;
}

int main(int argc, char const *argv[])
{

	while (menu())
	{
	}

	std::cout << "Goodbye!" << std::endl;

	return 0;
}
