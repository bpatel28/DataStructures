//binary_tree.hpp : defines binary tree
//
//template parameter requires operator overload for comparison.
//

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include "bst_node.hpp"

namespace my_lib
{
	template<class T>
	class BinarySearchTree
	{
	public :
		BinarySearchTree();
		BinarySearchTree(BSTNode<T> *tp_node);
		~BinarySearchTree();

		//get the root node
		BSTNode<T> GetRoot() const;
		//Insert an element
		void Insert(const T t_data);
		//search element by data
		bool Contains(const T t_data) const;
		//Get Min value element
		T GetMin() const;
		//Get Max value element
		T GetMax() const;
		//Get Height of the tree
		size_t GetHeight() const;
		//Remove an element
		void Remove(const T t_data);

	private:
		BSTNode<T> *mp_root;

		//Remove branch
		void RemoveBranch(BSTNode<T> *tp_node);
		//Insert element recursively
		void Insert(BSTNode<T> *tp_data, BSTNode<T> *tp_curr_node, BSTNode<T> *tp_parent_node);
		//search recursively elemenet
		bool Contains(const T t_data, const BSTNode<T> *tp_node) const;
		//find height recursively
		size_t GetHeight(const BSTNode<T> *tp_node) const;
		//Get Min Value Node
		BSTNode<T>* GetMin(BSTNode<T> *tp_node) const;
		//Get Max Value Node
		BSTNode<T>* GetMax(BSTNode<T> *tp_node) const;
		//remove node
		void Remove(T t_data, BSTNode<T> *tp_node, BSTNode<T> *tp_parent_node);
		//delete node and rearrange subtrees
		void Delete(BSTNode<T> *tp_del_node, BSTNode<T> *tp_parent_node);
	};
}

#endif