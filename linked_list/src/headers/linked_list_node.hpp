// linked_list_node.hpp : Defines LinkedListNode class.
//

#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

namespace my_lib{

	template <class T>
	class LinkedListNode
	{
	public:
		LinkedListNode(const T &t_value) : m_data(t_value), mp_next(nullptr), mp_prev(nullptr) {}
		~LinkedListNode() {}
		LinkedListNode(const LinkedListNode &) = delete;
		LinkedListNode &operator=(const LinkedListNode &) = default;

		const T get_data() const { return m_data; }
		LinkedListNode<T> *get_next() const { return mp_next; }
		LinkedListNode<T> *get_prev() const { return mp_prev; }
		void set_data(const T &t_data) { m_data = t_data; }
		void set_next(LinkedListNode<T> *tp_next) { mp_next = tp_next; }
		void set_prev(LinkedListNode<T> *tp_prev) { mp_prev = tp_prev; }

	private:
		T m_data;
		LinkedListNode<T> *mp_next;
		LinkedListNode<T> *mp_prev;
	};

}

#endif