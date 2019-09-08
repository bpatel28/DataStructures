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

		//get data
		const T GetData() const { return m_data; }
		//get next element
		LinkedListNode<T> *GetNext() const { return mp_next; }
		//get prev element
		LinkedListNode<T> *GetPrev() const { return mp_prev; }
		//set data
		void SetData(const T &t_data) { m_data = t_data; }
		//set next element
		void SetNext(LinkedListNode<T> *tp_next) { mp_next = tp_next; }
		//set prev element
		void SetPrev(LinkedListNode<T> *tp_prev) { mp_prev = tp_prev; }

	private:
		T m_data;
		LinkedListNode<T> *mp_next;
		LinkedListNode<T> *mp_prev;
	};

}

#endif