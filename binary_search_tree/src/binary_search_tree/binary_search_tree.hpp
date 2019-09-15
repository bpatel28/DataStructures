//binary_tree.hpp : defines binary tree
//
//template parameter requires operator overload for comparison.
//

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <stdlib.h>
#include "iostream"
#include <vector>

#include "bst_node.hpp"

namespace my_lib
{
	template<class T, class K>
	class BinarySearchTree
	{
	public :
		BinarySearchTree();
		BinarySearchTree(BSTNode<T, K> *tp_node);
		~BinarySearchTree();

		//get the root node
		BSTNode<T, K> GetRoot() const;
		//Insert an element
		void Insert(const T t_data, const K t_key);
		//search element by data
		bool Contains(const K t_key) const;
		//Get Min value element
		T GetMin() const;
		//Get Max value element
		T GetMax() const;
		//Get Height of the tree
		size_t GetHeight() const;
		//Remove an element
		void Remove(const K t_key);
		//Make Balanced Tree
		void BalanceTree();

	private:
		BSTNode<T, K> *mp_root;

		//Remove branch
		void RemoveBranch(BSTNode<T, K> *tp_node);
		//Insert element recursively
		void Insert(BSTNode<T, K> *tp_data, BSTNode<T, K> *tp_curr_node, BSTNode<T, K> *tp_parent_node);
		//search recursively elemenet
		bool Contains(const K t_key, const BSTNode<T, K> *tp_node) const;
		//find height recursively
		size_t GetHeight(const BSTNode<T, K> *tp_node) const;
		//Get Min Value Node
		BSTNode<T, K>* GetMin(BSTNode<T, K> *tp_node) const;
		//Get Max Value Node
		BSTNode<T, K>* GetMax(BSTNode<T, K> *tp_node) const;
		//remove node
		void Remove(K t_key, BSTNode<T, K> *tp_node, BSTNode<T, K> *tp_parent_node);
		//delete node and rearrange subtrees
		void Delete(BSTNode<T, K> *tp_del_node, BSTNode<T, K> *tp_parent_node);
	};
}

#endif