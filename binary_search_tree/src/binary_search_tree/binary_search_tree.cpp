//binary_tree.cpp : defines operations for binary_tree
//

#include "binary_search_tree.hpp"

namespace my_lib
{
	template<class T>
	BinarySearchTree<T>::BinarySearchTree(): mp_root(nullptr) {}
	
	template<class T>
	BinarySearchTree<T>::BinarySearchTree(BSTNode<T> *tp_node) : mp_root(tp_node) {}

	template<class T>
	BinarySearchTree<T>::~BinarySearchTree() { RemoveBranch(mp_root); }

	template<class T>
	BSTNode<T> BinarySearchTree<T>::GetRoot() const { return *mp_root; }

	template<class T>
	void BinarySearchTree<T>::RemoveBranch(BSTNode<T> *tp_node)
	{
		if (!tp_node) return;
		RemoveBranch(tp_node->GetLeftChild());
		RemoveBranch(tp_node->GetRightChild());
		delete tp_node;
	}

	template<class T>
	void BinarySearchTree<T>::Insert(const T t_data)
	{
		auto *p_data = new BSTNode<T>{ t_data };
		if (!mp_root)
		{
			mp_root = p_data;
			return;
		}
		Insert(p_data, mp_root, nullptr);
	}

	template<class T>
	void BinarySearchTree<T>::Insert(BSTNode<T> *tp_data, BSTNode<T> *tp_curr_node, BSTNode<T> *tp_parent_node)
	{
		if (!tp_curr_node)
		{
			if (tp_parent_node->GetData() <= tp_data->GetData()) tp_parent_node->SetRightChild(tp_data);
			if (tp_parent_node->GetData() > tp_data->GetData()) tp_parent_node->SetLeftChild(tp_data);
			return;
		}
		if (tp_data->GetData() < tp_curr_node->GetData())
			Insert(tp_data, tp_curr_node->GetLeftChild(), tp_curr_node);
		else if (tp_data->GetData() >= tp_curr_node->GetData())
			Insert(tp_data, tp_curr_node->GetRightChild(), tp_curr_node);
	}

	template<class T>
	bool BinarySearchTree<T>::Contains(const T t_data) const
	{
		return Contains(t_data, mp_root);
	}

	template<class T>
	bool BinarySearchTree<T>::Contains(const T t_data, const BSTNode<T> *tp_node) const
	{
		if (!tp_node) return false;
		if (tp_node->GetData() == t_data) return true;
		else if (tp_node->GetData() > t_data) return Contains(t_data, tp_node->GetLeftChild());
		else if (tp_node->GetData() < t_data) return Contains(t_data, tp_node->GetRightChild());
		return false;
	}

	template<class T>
	T BinarySearchTree<T>::GetMin() const
	{
		auto *p_min = GetMin(mp_root);
		if (p_min) return p_min->GetData();
		throw std::runtime_error("Empty tree!");
	}

	template<class T>
	BSTNode<T>* BinarySearchTree<T>::GetMin(BSTNode<T> *tp_node) const
	{
		BSTNode<T>* p_curr = tp_node;
		BSTNode<T>* p_prev = nullptr;
		while (p_curr)
		{
			p_prev = p_curr;
			p_curr = p_curr->GetLeftChild();
		}
		return p_prev;
	}

	template<class T>
	T BinarySearchTree<T>::GetMax() const
	{
		auto *p_max = GetMax(mp_root);
		if (p_max) return p_max->GetData();
		throw std::runtime_error("Empty tree!");
	}

	template<class T>
	BSTNode<T>* BinarySearchTree<T>::GetMax(BSTNode<T>* tp_node) const
	{
		BSTNode<T>* p_curr = tp_node;
		BSTNode<T>* p_prev = nullptr;
		while (p_curr)
		{
			p_prev = p_curr;
			p_curr = p_curr->GetRightChild();
		}
		return p_prev;
	}

	template<class T>
	size_t BinarySearchTree<T>::GetHeight() const
	{
		return GetHeight(mp_root);
	}

	template<class T>
	size_t BinarySearchTree<T>::GetHeight(const BSTNode<T> *tp_node) const
	{
		if (!tp_node) return 0;
		size_t left_height = 0;
		size_t right_height = 0;
		left_height += GetHeight(tp_node->GetLeftChild());
		right_height += GetHeight(tp_node->GetRightChild());
		return (left_height > right_height) ? ++left_height : ++right_height;
	}

	template<class T>
	void BinarySearchTree<T>::Remove(const T t_data)
	{
		Remove(t_data, mp_root, nullptr);
	}

	template<class T>
	void BinarySearchTree<T>::Remove(T t_data, BSTNode<T>* tp_node, BSTNode<T>* tp_parent_node)
	{
		if (!tp_node) return;
		else if (tp_node->GetData() == t_data)
		{
			Delete(tp_node, tp_parent_node);
		}
		else if (tp_node->GetData() > t_data)
		{
			Remove(t_data, tp_node->GetLeftChild(), tp_node);
		}
		else if (tp_node->GetData() < t_data) 
		{
			Remove(t_data, tp_node->GetRightChild(), tp_node);
		}
	}

	template<class T>
	void BinarySearchTree<T>::Delete(BSTNode<T> *tp_del_node, BSTNode<T> *tp_parent_node)
	{
		if (!tp_del_node) return;
		auto *p_left_child = tp_del_node->GetLeftChild();
		auto *p_right_child = tp_del_node->GetRightChild();
		if (!tp_parent_node)
		{
			auto *p_min = GetMin(p_right_child);
			mp_root = p_right_child;
			if (p_min) p_min->SetLeftChild(p_left_child);
			else if (p_right_child) p_right_child->SetLeftChild(p_left_child);
			else if (p_left_child) mp_root = p_left_child;
		}
		else if (tp_parent_node->GetData() > tp_del_node->GetData())
		{
			tp_parent_node->SetLeftChild(p_right_child);
			auto *p_min = GetMin(p_right_child);
			if (p_min) p_min->SetLeftChild(p_left_child);
			else if (p_right_child) p_right_child->SetLeftChild(p_left_child);
			else tp_parent_node->SetLeftChild(p_left_child);
		}
		else if (tp_parent_node->GetData() < tp_del_node->GetData())
		{
			tp_parent_node->SetRightChild(p_right_child);
			auto *p_min = GetMin(p_right_child);
			if (p_min) p_min->SetLeftChild(p_left_child);
			else if (p_right_child) p_right_child->SetLeftChild(p_left_child);
			else tp_parent_node->SetLeftChild(p_left_child);
		}
		delete tp_del_node;
	}
}