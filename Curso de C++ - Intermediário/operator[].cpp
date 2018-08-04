/**
 * @file operator[].cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 03/08/2018
 * 
 * Overloading the [] operator
 */
#include <iostream>

// Overloading the operator [] for a linked list
// Look at line
template <class T>
class LinkedList
{
	class Node
	{
	  private:
		T _value;
		Node *_next;

	  public:
		Node(T value)
		{
			this->_value = value;
			this->_next = nullptr;
		}

		~Node() = default;

		T value()
		{
			return this->_value;
		}

		Node *get_next()
		{
			return this->_next;
		}

		void set_next(Node *next)
		{
			this->_next = next;
		}

		void print()
		{
			std::cout << this->_value << " -> ";
		}
	};

  private:
	Node *head;
	Node *tail;
	size_t _size;

	Node *iterate(int iter)
	{
		Node *scan = this->head;

		for (int i = 0; i < iter; i++)
			scan = scan->get_next();

		return scan;
	}

  public:
	LinkedList()
	{
		this->head = nullptr;
		this->tail = nullptr;
		this->_size = 0;
	}

	~LinkedList()
	{
		Node *scan = this->head;

		while (!this->empty())
		{
			this->head = this->head->get_next();

			delete scan;
			
			scan = this->head;
		}
	}

	bool empty()
	{
		return this->head == nullptr;
	}

	size_t size()
	{
		return this->_size;
	}

	void insert_front(T element)
	{
		Node *node = new Node(element);

		if (this->empty())
		{
			this->head = node;
			this->tail = node;
		}
		else
		{
			node->set_next(this->head);
			this->head = node;
		}
		this->_size++;
	}

	void insert_back(T element)
	{
		Node *node = new Node(element);

		if (this->empty())
		{
			this->head = node;
			this->tail = node;
		}
		else
		{
			this->tail->set_next(node);
			this->tail = node;
		}
	}

	T operator[](int i);
};

template <class T>
T LinkedList<T>::operator[] (int i)
{
	if (i > this->size() - 1 || i < 0)
		return 0;

	return this->iterate(i)->value();
}

int main(int argc, char const *argv[])
{
	LinkedList<int> list;

	for (int i = 0; i < 10; i++)
	{
		list.insert_back(i);
	}

	for (int i = 0; i < 10; i++)
	{
		std::cout << list[i] << " ";
	}

	return 0;
}
