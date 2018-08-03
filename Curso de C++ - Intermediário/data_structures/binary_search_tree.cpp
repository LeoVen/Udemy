/**
 * @file binary_search_tree.cpp
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 02/08/2018
 * 
 * Templated Binary Search Tree implementation example
 */
#include <iostream>

template <class T>
class binary_search_tree
{
	class Node
	{
	  private:
		Node *left;
		Node *right;
		Node *parent;
		T key;
		size_t level;

	  public:
		Node(T key, Node *parent = nullptr, size_t level = 0, Node *right = nullptr, Node *left = nullptr)
		{
			this->key = key;
			this->parent = parent;
			this->level = level;
			this->right = right;
			this->left = left;
		}

		T get_key()
		{
			return this->key;
		}

		Node *get_right()
		{
			return this->right;
		}

		Node *get_left()
		{
			return this->left;
		}

		Node *get_parent()
		{
			return this->parent;
		}

		void set_right(Node *right)
		{
			this->right = right;
		}

		void set_left(Node *left)
		{
			this->left = left;
		}

		void set_parent(Node *parent)
		{
			this->parent = parent;
		}

		size_t get_level()
		{
			return this->level;
		}

		void set_level(size_t level)
		{
			this->level = level;
		}

		bool has_parent()
		{
			return this->parent != nullptr;
		}

		friend std::ostream &operator<<(std::ostream &stream, const class Node &c)
		{
			if (c.parent != nullptr)
				return stream << "P<" << c.parent->get_key() << ">K" << c.key << ">L" << c.level << ">";
			else
				return stream << "P<" << "root" << ">K" << c.key << ">L" << c.level << ">";
		}
	};

  private:
	Node *root;
	size_t size;

	int add_key(T key)
	{
		Node *scan = this->root;
		Node *prev = nullptr;

		while (scan != nullptr)
		{
			prev = scan;

			if (scan->get_key() < key)
				scan = scan->get_left();
			else if (scan->get_key() > key)
				scan = scan->get_right();
			else
				return -1; // No duplicates
		}

		Node *new_node = new Node(key, prev, prev->get_level() + 1);

		if (prev->get_key() < key)
			prev->set_left(new_node);
		else
			prev->set_right(new_node);

		this->size++;

		return 0;
	}

	void delete_tree(Node *node)
	{
		if (node->get_left() != nullptr)
			delete_tree(node->get_left());

		if (node->get_right() != nullptr)
			delete_tree(node->get_right());

		delete node;
	}

	void display_tree(Node *node)
	{
		if (node == nullptr)
			return;

		display_tree(node->get_left());

		for (size_t i = 0; i < node->get_level(); i++)
			std::cout << "|     ";

		std::cout << *node << std::endl;

		display_tree(node->get_right());
	}

  public:
	binary_search_tree()
	{
		this->root = nullptr;
		this->size = 0;
	}

	~binary_search_tree()
	{
		if (!this->empty())
			this->delete_tree(this->root);
	}

	bool empty()
	{
		return this->root == nullptr;
	}

	void add(T key)
	{
		if (this->empty())
		{
			this->root = new Node(key, nullptr, 0);
			this->size++;
		}
		else
			this->add_key(key);
	}

	void display()
	{
		if (this->empty())
			std::cout << "Binary Search Tree is empty" << std::endl;
		else
			display_tree(this->root);
	}
};

int main(int argc, char const *argv[])
{
	binary_search_tree<int> bst;

	bst.add(8);
	bst.add(10);
	bst.add(14);
	bst.add(13);
	bst.add(3);
	bst.add(1);
	bst.add(6);
	bst.add(4);
	bst.add(7);

	bst.display();

	std::cout << "\n\n";

	binary_search_tree<std::string> str_bst;

	std::string strs[10] = {"Hello", "Lorem", "Ipsum", "Michael", "Douglas", "Penny", "Alan", "Albert", "Zacharias", "Xerxes"};

	for (int i = 0; i < 10; i++)
		str_bst.add(strs[i]);

	str_bst.display();

	return 0;
}
