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
		~LinkedList();

		//returns no of items in list
		size_t count() const;
		//add item at the tail of the list
		void push_back(const T &t_data);
		//remove item from the tail of the list
		T pop_back();
		//returns value of the last item
		T peek_back() const;
		//adds item at the end of the list
		void add_last(const T &t_data);
		//removes item from the end of the list
		T remove_last();
		//add item at the head of the list
		void push_front(const T &t_data);
		//remove item from the head
		T pop_front();
		//returns value of the first element
		T LinkedList<T>::peek_first() const;
		//add item at the head of the list
		void add_first(const T& t_data);
		//remove item first item of the list
		T remove_first();
			//inserts item at given index
		void insert_at(int t_index, const T &t_data);
		//removes item at given index
		T remove_at(int t_index);
		//gives value of the item at given index
		T operator[](int t_index) const;
		//clears all the item from the list
		void clear();
		//returns true or false indicating list is empty or not
		bool is_empty() const;
		//reverse items in the list
		void reverse();

	private:
		LinkedListNode<T> *mp_head;
		LinkedListNode<T> *mp_tail;
		size_t m_count;
	};

}

#endif
