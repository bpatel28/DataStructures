//b_node.hpp : defination for binary tree node.
//T - datatype, K - keytype
//requires comparison implemented in keytype


#ifndef  BINARY_SEARCH_TREE_NODE
#define  BINARY_SEARCH_TREE_NODE

namespace my_lib
{
	template <class T, class K>
	class BSTNode
	{
	public:
		BSTNode(T t_data, K t_key) : m_key(t_key), m_data(t_data), mp_left_child(nullptr), mp_right_child(nullptr) {}
		BSTNode(K t_key) : m_key(t_key), m_data(0), mp_left_child(nullptr), mp_right_child(nullptr) {}
		~BSTNode() {}

		//returns data
		T GetData() const { return m_data; }
		//set data
		void SetData(const T t_data) { m_data = t_data; }
		//get key
		K GetKey() const { return m_key; }
		//set key
		void SetKey(const K t_key) { m_key = t_key}
		//get left child
		BSTNode<T, K> *GetLeftChild() const { return mp_left_child; }
		//set left child using pointer to node
		void SetLeftChild(BSTNode<T, K> *tp_node) { mp_left_child = tp_node; }
		//set left by creating new node
		void SetLeftChild(const T t_node) { mp_left_child = new BSTNode{ t_data }; }
		//get right child
		BSTNode<T, K> *GetRightChild() const { return mp_right_child; }
		//set right using pointer to node
		void SetRightChild(BSTNode<T, K> *tp_node) { mp_right_child = tp_node; }
		//set right child by creating new node
		void SetRightChild(const T t_node) { mp_right_child = new BSTNode{ t_data }; }

	private:
		T m_data;
		K m_key;
		BSTNode<T, K>* mp_left_child;
		BSTNode<T, K>* mp_right_child;
	};
}

#endif // ! BINARY_TREE_NODE
