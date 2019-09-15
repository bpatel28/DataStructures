//main.cpp : entry point for project and testing lib.

#include "binary_search_tree/binary_search_tree.cpp"

int main()
{
	std::vector<int> data { 11 , 12, 13, 14, 15, 16, 17, 18, 19, 20};
	std::vector<int> key {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	my_lib::BinarySearchTree<int, int> tree {};
	my_lib::BuildBalancedBST(tree, data, key, 0, 9);

	try
	{
		tree.Insert(19, 9);
		tree.Insert(21, 11);
		tree.BalanceTree();
		std::cout << tree.Contains(12) << std::endl;
		std::cout << std::endl;
		my_lib::TraverseInOrder(tree);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}