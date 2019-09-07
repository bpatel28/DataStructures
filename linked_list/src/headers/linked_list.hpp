// linked_list.hpp : Defines the LinkedList class.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "linked_list_node.hpp"
	
namespace my_lib {

	template <class T>
	class LinkedList
	{
	public:
		explicit LinkedList() : mp_head(nullptr) {}
		~LinkedList() {}

		int size() const;
		void push(const T &data);
		T &pop();
		T& peek();
		void add(const T &data);
		void remove();

	private:
		LinkedListNode<T> *mp_head;
	};

}


#endif
