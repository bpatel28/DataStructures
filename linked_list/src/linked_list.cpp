// linked_list.cpp : Defines the functions for linked_list class.
//

#include "headers/linked_list.hpp"

namespace my_lib {

	template <class T>
	int LinkedList<T>::count() const
	{
		return m_count;
	}

	template<class T>
	void LinkedList<T>::push(const T& t_data)
	{
		auto *data = new LinkedListNode<T> { t_data };

		if (!mp_head)
		{
			mp_head = data;
			mp_tail = data;
		}
		else
		{
			mp_tail->set_next(data);
			auto p_prev = mp_tail;
			mp_tail = mp_tail->get_next();
			mp_tail->set_prev(p_prev);
		}
		m_count++;
	}

	template<class T>
	T LinkedList<T>::pop() 
	{
		if (!mp_tail) 
		{
			throw std::runtime_error("Empty List.");
		}
		auto data = mp_tail->get_data();
		auto p_prev = mp_tail->get_prev();
		delete mp_tail;
		mp_tail = p_prev;
		if (mp_tail == mp_head) mp_head = p_prev;
		m_count--;
		return data;
	}

	template<class T>
	T LinkedList<T>::peek()
	{
		if (!mp_tail)
		{
			throw "Empty List.";
		}
		auto data = mp_tail->get_data();
		return data;
	}

	template<class T>
	void LinkedList<T>::add(const T &t_data)
	{
		this->push(t_data);
	}

	template<class T>
	T LinkedList<T>::remove()
	{
		return this->pop();
	}
}