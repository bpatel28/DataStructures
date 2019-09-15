//main.cpp : entry point for project and testing lib.

#include "binary_search_tree/binary_search_tree.cpp"

int main()
{
	std::vector<int> data { 1 , 2, 3, 4, 5, 6, 7, 8, 9, 10};
	my_lib::BinarySearchTree<int> tree {};
	my_lib::BuildBalancedBST(tree, data, 0, 9);

	try
	{
		tree.Insert(19);
		tree.Insert(21);
		tree.BalanceTree();
		my_lib::TraverseInOrder(tree);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}