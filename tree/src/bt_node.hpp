//b_node.hpp : defines defination for binary tree node.


#ifndef  BINARY_TREE_NODE
#define  BINARY_TREE_NODE

#include <stdlib.h>
#include "iostream"

namespace my_lib
{
	template <class T>
	class BTNode
	{
	public:
		BTNode(T t_data) : m_data(t_data), mp_left_child(nullptr), mp_right_child(nullptr) {}
		BTNode() : m_data(0), mp_left_child(nullptr), mp_right_child(nullptr) {}
		~BTNode() 
		{
			delete mp_left_child;
			delete mp_right_child;
		}

		//returns data
		T GetData() const { return m_data; }
		//set data
		void SetData(const T t_data) { m_data = t_data; }
		//get left child
		BTNode GetLeftChild() const { return *mp_left_child; }
		//set left child using pointer to node
		void SetLeftChild(const BTNode* tp_node) { mp_left_child = tp_node; }
		//set left by creating new node
		void SetLeftChild(const T t_node) { mp_left_child = new BTNode{ t_data }; }
		//get right child
		BTNode GetRightChild() const { return *mp_right_child; }
		//set right using pointer to node
		void SetRightChild(const BTNode* tp_node) { mp_right_child = tp_node; }
		//set right child by creating new node
		void SetRightChild(const T t_node) { mp_right_child = new BTNode{ t_data }; }

	private:
		T m_data;
		BTNode* mp_left_child;
		BTNode* mp_right_child;
	};
}

#endif // ! BINARY_Tree_Node
