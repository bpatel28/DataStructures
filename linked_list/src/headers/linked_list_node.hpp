// linked_list_node.hpp : Defines LinkedListNode class.
//

#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

namespace my_lib{

	template <class T>
	class LinkedListNode
	{
	public:
		LinkedListNode(const T &value) : m_data(value), mp_next(nullptr) {}
		~LinkedListNode() {}

		const T get_data() const { return m_data; }
		LinkedListNode<T> *get_next() const { return mp_next; }
		void set_data(const T &data) { m_data = data; }
		void set_next(LinkedListNode<T> *p_next) { mp_next = p_next; }

	private:
		T m_data;
		LinkedListNode<T> *mp_next;
	};

}

#endif