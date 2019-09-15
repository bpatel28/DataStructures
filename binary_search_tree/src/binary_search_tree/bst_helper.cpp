//bst_node.cpp : function defined to help easy operations with binary search tree.
//

#include "binary_search_tree.hpp"

namespace my_lib
{
	//convert sorted array to balanced binary search tree.
	//requires sorted array.
	template<class T, class K>
	void BuildBalancedBST(BinarySearchTree<T, K> &t_tree, std::vector<T> &t_data_list, std::vector<K> &t_key_list, int t_start_index, int t_end_index)
	{
		if (t_start_index > t_end_index) return;
		int mid_index = (t_start_index + t_end_index)/ 2;
		t_tree.Insert(t_data_list[mid_index], t_key_list[mid_index]);
		BuildBalancedBST(t_tree, t_data_list, t_key_list, t_start_index, mid_index - 1);
		BuildBalancedBST(t_tree, t_data_list, t_key_list, mid_index + 1, t_end_index);
	}
	
	//traverse tree in order
	template<class T, class K>
	void TraverseInOrder(BinarySearchTree<T, K> &t_tree)
	{
		TraverseInOrder(t_tree.GetRoot());
	}

	//traverse node recursively
	template<class T, class K>
	void TraverseInOrder(BSTNode<T, K> &t_node)
	{
		if (!&t_node) return;
		TraverseInOrder(*t_node.GetLeftChild());
		std::cout << t_node.GetData() << std::endl;
		TraverseInOrder(*t_node.GetRightChild());
	}

	//convert tree to sorted LinkedList
	template<class T, class K>
	void ToList(std::vector<T> &t_data_list, std::vector<K> &t_key_list, BSTNode<T, K> &t_node)
	{
		if (!&t_node) return;
		ToList(t_data_list, t_key_list,*t_node.GetLeftChild());
		t_data_list.push_back(t_node.GetData());
		t_key_list.push_back(t_node.GetKey());
		ToList(t_data_list, t_key_list,*t_node.GetRightChild());
	}
	
}