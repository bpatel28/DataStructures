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
		size_t Count() const;
		//add item at the tail of the list
		void PushBack(const T &t_data);
		//remove item from the tail of the list
		T PopBack();
		//returns value of the last item
		T PeekBack() const;
		//adds item at the end of the list
		void AddLast(const T &t_data);
		//removes item from the end of the list
		T RemoveLast();
		//add item at the head of the list
		void PushFront(const T &t_data);
		//remove item from the head
		T PopFront();
		//returns value of the first element
		T LinkedList<T>::PeekFront() const;
		//add item at the head of the list
		void AddFirst(const T& t_data);
		//remove item first item of the list
		T RemoveFirst();
		//inserts item at given index
		void InsertAt(int t_index, const T &t_data);
		//removes item at given index
		T RemoveAt(int t_index);
		//gives value of the item at given index
		T operator[](int t_index) const;
		//clears all the item from the list
		void Clear();
		//returns true or false indicating list is empty or not
		bool IsEmpty() const;
		//reverse items in the list
		void Reverse();

	private:
		LinkedListNode<T> *mp_head;
		LinkedListNode<T> *mp_tail;
		size_t m_count;
	};

}

#endif
