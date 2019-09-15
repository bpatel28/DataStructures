//main.cpp : entry point for project and testing lib.

#include "binary_search_tree/binary_search_tree.cpp"

int main()
{
	my_lib::BinarySearchTree<int> tree{};
	try
	{
		tree.Insert(7);
		tree.Insert(5);
		tree.Insert(2);
		tree.Insert(10);
		tree.Insert(45);
		tree.Remove(7);

		std::cout << tree.GetMax() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}