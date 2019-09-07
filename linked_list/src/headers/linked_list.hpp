// linked_list.hpp : Defines the LinkedList class.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "linked_list_node.hpp"
#include <stdlib.h>
#include <iostream>
	
namespace my_lib {

	template <class T>
	class LinkedList
	{
	public:
		explicit LinkedList() : mp_head(nullptr), mp_tail(nullptr), m_count(0) {}
		~LinkedList() {}

		int count() const;
		void push(const T &t_data);
		T pop();
		T peek();
		void add(const T &t_data);
		T remove();

	private:
		LinkedListNode<T> *mp_head;
		LinkedListNode<T> *mp_tail;
		int m_count;
	};

}


#endif
