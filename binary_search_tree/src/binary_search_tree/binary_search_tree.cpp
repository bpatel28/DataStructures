//binary_tree.cpp : defines operations for binary_tree
//T - datatype, K - keytype
//requires comparison implemented in keytype


#include "binary_search_tree.hpp"
#include "bst_helper.cpp"

namespace my_lib
{
	template<class T, class K>
	BinarySearchTree<T, K>::BinarySearchTree(): mp_root(nullptr) {}
	
	template<class T, class K>
	BinarySearchTree<T, K>::BinarySearchTree(BSTNode<T, K> *tp_node) : mp_root(tp_node) {}

	template<class T, class K>
	BinarySearchTree<T, K>::~BinarySearchTree() { RemoveBranch(mp_root); }

	template<class T, class K>
	BSTNode<T, K>* BinarySearchTree<T, K>::GetRoot() const { return mp_root; }

	template<class T, class K>
	void BinarySearchTree<T, K>::RemoveBranch(BSTNode<T, K> *tp_node)
	{
		if (!tp_node) return;
		RemoveBranch(tp_node->GetLeftChild());
		RemoveBranch(tp_node->GetRightChild());
		delete tp_node;
		mp_root = nullptr;
	}

	template<class T, class K>
	void BinarySearchTree<T, K>::Insert(const T t_data, const K t_key)
	{
		auto *p_data = new BSTNode<T, K>{ t_data, t_key };
		if (!mp_root)
		{
			mp_root = p_data;
			return;
		}
		Insert(p_data, mp_root, nullptr);
	}

	template<class T, class K>
	void BinarySearchTree<T, K>::Insert(BSTNode<T, K> *tp_data, BSTNode<T, K> *tp_curr_node, BSTNode<T, K> *tp_parent_node)
	{
		if (!tp_curr_node)
		{
			if (tp_parent_node->GetKey() <= tp_data->GetKey()) tp_parent_node->SetRightChild(tp_data);
			if (tp_parent_node->GetKey() > tp_data->GetKey()) tp_parent_node->SetLeftChild(tp_data);
			return;
		}
		if (tp_data->GetKey() < tp_curr_node->GetKey())
			Insert(tp_data, tp_curr_node->GetLeftChild(), tp_curr_node);
		else if (tp_data->GetKey() >= tp_curr_node->GetKey())
			Insert(tp_data, tp_curr_node->GetRightChild(), tp_curr_node);
	}

	template<class T, class K>
	T BinarySearchTree<T, K>::Find(const K t_key) const
	{
		return Find(t_key, mp_root);
	}

	template<class T, class K>
	T BinarySearchTree<T, K>::Find(const K t_key, const BSTNode<T, K> *tp_node) const
	{
		if (!tp_node) throw std::runtime_error("No element found!");
		else if (tp_node->GetKey() == t_key) return tp_node->GetData();
		else if (tp_node->GetKey() > t_key) return Find(t_key, tp_node->GetLeftChild());
		else return Find(t_key, tp_node->GetRightChild());
		throw std::runtime_error("No element found!");
	}

	template<class T, class K>
	bool BinarySearchTree<T, K>::Contains(const T t_data) const
	{
		return Contains(t_data, mp_root);
	}

	template<class T, class K>
	bool BinarySearchTree<T, K>::Contains(const T t_data, const BSTNode<T, K>* tp_node) const
	{
		if (!tp_node) return false;
		else if (tp_node->GetData() == t_data) return true;
		else if (Contains(t_data, tp_node->GetLeftChild()) == false)
			return Contains(t_data, tp_node->GetRightChild());
		return true;
	}

	template<class T, class K>
	K BinarySearchTree<T, K>::GetKey(const T t_data) const
	{
		K key;
		GetKey(key, t_data, mp_root);
		return key;
	}

	template<class T, class K>
	void BinarySearchTree<T, K>::GetKey(K &t_key, const T t_data, const BSTNode<T, K> *tp_node) const
	{
		if (!tp_node) return;
		if (tp_node->GetData() == t_data)
		{
			t_key = tp_node->GetKey();
			return;
		}
		GetKey(t_key, t_data, tp_node->GetLeftChild());
		GetKey(t_key, t_data, tp_node->GetRightChild());
	}

	template<class T, class K>
	T BinarySearchTree<T, K>::GetMin() const
	{
		auto *p_min = GetMin(mp_root);
		if (p_min) return p_min->GetData();
		throw std::runtime_error("Empty tree!");
	}

	template<class T, class K>
	BSTNode<T, K>* BinarySearchTree<T, K>::GetMin(BSTNode<T, K> *tp_node) const
	{
		BSTNode<T, K>* p_curr = tp_node;
		BSTNode<T, K>* p_prev = nullptr;
		while (p_curr)
		{
			p_prev = p_curr;
			p_curr = p_curr->GetLeftChild();
		}
		return p_prev;
	}

	template<class T, class K>
	T BinarySearchTree<T, K>::GetMax() const
	{
		auto *p_max = GetMax(mp_root);
		if (p_max) return p_max->GetData();
		throw std::runtime_error("Empty tree!");
	}

	template<class T, class K>
	BSTNode<T, K>* BinarySearchTree<T, K>::GetMax(BSTNode<T, K>* tp_node) const
	{
		BSTNode<T, K>* p_curr = tp_node;
		BSTNode<T, K>* p_prev = nullptr;
		while (p_curr)
		{
			p_prev = p_curr;
			p_curr = p_curr->GetRightChild();
		}
		return p_prev;
	}

	template<class T, class K>
	size_t BinarySearchTree<T, K>::GetHeight() const
	{
		return GetHeight(mp_root);
	}

	template<class T, class K>
	size_t BinarySearchTree<T, K>::GetHeight(const BSTNode<T, K> *tp_node) const
	{
		if (!tp_node) return 0;
		size_t left_height = 0;
		size_t right_height = 0;
		left_height += GetHeight(tp_node->GetLeftChild());
		right_height += GetHeight(tp_node->GetRightChild());
		return (left_height > right_height) ? ++left_height : ++right_height;
	}

	template<class T, class K>
	void BinarySearchTree<T, K>::Remove(const K t_key)
	{
		Remove(t_key, mp_root, nullptr);
	}

	template<class T, class K>
	void BinarySearchTree<T, K>::Remove(K t_key, BSTNode<T, K> *tp_node, BSTNode<T, K> *tp_parent_node)
	{
		if (!tp_node) return;
		else if (tp_node->GetKey() == t_key)
		{
			Delete(tp_node, tp_parent_node);
		}
		else if (tp_node->GetKey() > t_key)
		{
			Remove(t_key, tp_node->GetLeftChild(), tp_node);
		}
		else if (tp_node->GetKey() < t_key)
		{
			Remove(t_key, tp_node->GetRightChild(), tp_node);
		}
	}

	template<class T, class K>
	void BinarySearchTree<T, K>::Delete(BSTNode<T, K> *tp_del_node, BSTNode<T, K> *tp_parent_node)
	{
		if (!tp_del_node) return;
		auto *p_left_child = tp_del_node->GetLeftChild();
		auto *p_right_child = tp_del_node->GetRightChild();
		//compare with parent node and rearrange nodes.
		if (!tp_parent_node)
		{
			auto *p_min = GetMin(p_right_child);
			mp_root = p_right_child;
			if (p_min) p_min->SetLeftChild(p_left_child);
			else if (p_right_child) p_right_child->SetLeftChild(p_left_child);
			else if (p_left_child) mp_root = p_left_child;
		}
		else if (tp_parent_node->GetKey() > tp_del_node->GetKey())
		{
			tp_parent_node->SetLeftChild(p_right_child);
			auto *p_min = GetMin(p_right_child);
			if (p_min) p_min->SetLeftChild(p_left_child);
			else if (p_right_child) p_right_child->SetLeftChild(p_left_child);
		}
		else if (tp_parent_node->GetKey() < tp_del_node->GetKey())
		{
			tp_parent_node->SetRightChild(p_right_child);
			auto *p_min = GetMin(p_right_child);
			if (p_min) p_min->SetLeftChild(p_left_child);
			else if (p_right_child) p_right_child->SetLeftChild(p_left_child);
		}
		delete tp_del_node;
	}

	template<class T, class K>
	void BinarySearchTree<T, K>::BalanceTree()
	{
		std::vector<T> data;
		std::vector<K> keys;
		ToList(data, keys,*mp_root);
		RemoveBranch(mp_root);
		BuildBalancedBST(*this, data, keys, 0, data.size() - 1);
	}
}