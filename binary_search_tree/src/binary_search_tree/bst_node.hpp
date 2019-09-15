//b_node.hpp : defines defination for binary tree node.


#ifndef  BINARY_SEARCH_TREE_NODE
#define  BINARY_SEARCH_TREE_NODE

namespace my_lib
{
	template <class T>
	class BSTNode
	{
	public:
		BSTNode(T t_data) : m_data(t_data), mp_left_child(nullptr), mp_right_child(nullptr) {}
		BSTNode() : m_data(0), mp_left_child(nullptr), mp_right_child(nullptr) {}
		~BSTNode() {}

		//returns data
		T GetData() const { return m_data; }
		//set data
		void SetData(const T t_data) { m_data = t_data; }
		//get left child
		BSTNode<T> *GetLeftChild() const { return mp_left_child; }
		//set left child using pointer to node
		void SetLeftChild(BSTNode<T> *tp_node) { mp_left_child = tp_node; }
		//set left by creating new node
		void SetLeftChild(const T t_node) { mp_left_child = new BSTNode{ t_data }; }
		//get right child
		BSTNode<T> *GetRightChild() const { return mp_right_child; }
		//set right using pointer to node
		void SetRightChild(BSTNode<T> *tp_node) { mp_right_child = tp_node; }
		//set right child by creating new node
		void SetRightChild(const T t_node) { mp_right_child = new BSTNode{ t_data }; }
		

	private:
		T m_data;
		BSTNode<T>* mp_left_child;
		BSTNode<T>* mp_right_child;
	};
}

#endif // ! BINARY_Tree_Node
