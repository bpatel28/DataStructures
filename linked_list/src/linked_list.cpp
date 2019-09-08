// linked_list.cpp : Defines the functions for linked_list class.
//

#include "headers/linked_list.hpp"

namespace my_lib {

	//destroy list.
	template <class T>
	LinkedList<T>::~LinkedList()
	{
		LinkedListNode<T> *current = mp_head;
		LinkedListNode<T> *next = nullptr;
		while (current)
		{
			next = current->get_next();
			delete current;
			current = next;
		}
	}

	//return count.
	template <class T>
	int LinkedList<T>::count() const
	{
		return m_count;
	}

	//push item at the tail of the list.
	template<class T>
	void LinkedList<T>::push_back(const T& t_data)
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

	//pop item from tail of the list.
	template<class T>
	T LinkedList<T>::pop_back() 
	{
		if (!mp_tail) throw std::runtime_error("Empty List.");
		auto p_data = mp_tail->get_data();
		auto p_prev = mp_tail->get_prev();
		delete mp_tail;
		mp_tail = p_prev;
		if (m_count == 1) mp_head = p_prev;
		m_count--;
		return p_data;
	}

	//return item at the tail of the list.
	template<class T>
	T LinkedList<T>::peek_back() const
	{
		if (!mp_tail) throw "Empty List.";
		auto data = mp_tail->get_data();
		return data;
	}

	//add item at the tail of the list.
	template<class T>
	void LinkedList<T>::add_last(const T &t_data)
	{
		push_back(t_data);
	}

	//remove item frome tail of the list.
	template<class T>
	T LinkedList<T>::remove_last()
	{
		return pop_back();
	}

	//push element at front
	template<class T>
	void LinkedList<T>::push_front(const T &t_data) {
		if (!mp_head)
		{
			mp_head = new LinkedListNode<T>{ t_data };
			mp_tail = mp_head;
		}
		else
		{
			auto* p_data = new LinkedListNode<T>{ t_data };
			p_data->set_next(mp_head);
			mp_head->set_prev(p_data);
			mp_head = p_data;
		}
		m_count++;
	}

	//remove element from front
	template<class T>
	T LinkedList<T>::pop_front() 
	{
		if (!mp_head) throw std::runtime_error("Empty List.");
		auto data = mp_head->get_data();
		auto* p_next = mp_head->get_next();
		delete mp_head;
		mp_head = p_next;
		if (m_count == 1) mp_tail = p_next;
		m_count--;
		return data;
	}

	//show first element
	template<class T>
	T LinkedList<T>::peek_first() const
	{
		if (!mp_head) throw std::runtime_error("Empty List.");
		auto data = mp_head->get_data();
		return data;
	}

	//add element to the head
	template<class T>
	void LinkedList<T>::add_first(const T& t_data)
	{
		push_front(t_data);
	}

	//remove element from the head
	template<class T>
	T LinkedList<T>::remove_first()
	{
		return pop_front();
	}

	//insert element at specified index
	template<class T>
	void LinkedList<T>::insert_at(int t_index, const T& t_data)
	{
		if (t_index < 0 || t_index > m_count) throw std::runtime_error("Index Out of Range.");
		if (t_index == m_count) 
		{
			push_back(t_data);
		}
		else if (t_index == 0)
		{
			add_first(t_data);
		}
		else
		{
			LinkedListNode<T>* p_curr = mp_head;
			for (size_t i = 1; i != t_index; i++)
			{
				p_curr = p_curr->get_next();
			}
			auto* p_data = new LinkedListNode<T>{ t_data };
			p_data->set_prev(p_curr->get_prev());
			p_data->set_next(p_curr);
			p_curr = p_data;
			m_count++;
		}
	}

	//removed element from at index
	template<class T>
	T LinkedList<T>::remove_at(int t_index)
	{
		if (t_index < 0 || t_index > m_count) throw std::runtime_error("Index Out of Range.");
		if (t_index == m_count) return pop_back();
		if (t_index == 0) return remove_first();
		LinkedListNode<T>* p_curr = mp_head;
		for (size_t i = 1; i != t_index; i++)
		{
			p_curr = p_curr->get_next();
		}
		auto *p_data = p_curr;
		auto data = p_data->get_data();
		p_curr->set_prev(p_curr->get_next());
		delete p_data;
		m_count--;
		return data;
	}

	//access element at specified index
	template<class T>
	T LinkedList<T>::operator[](int t_index) const
	{
		if (t_index < 0 || t_index >= m_count) throw std::runtime_error("Index Out of Range.");
		if (t_index == m_count - 1) return peek_back();
		if (t_index == 0) return peek_first();
		LinkedListNode<T>* p_curr = mp_head;
		for (size_t i = 1; i != t_index; i++)
		{
			p_curr = p_curr->get_next();
		}
		return p_curr->get_data();
	}

	//clear all the items from the list
	template<class T>
	void LinkedList<T>::clear()
	{
		if (m_count == 0) return;
		auto *p_curr = mp_head;
		LinkedListNode<T>* p_next = nullptr;
		while (p_curr)
		{
			p_next = p_curr->get_next();
			delete p_curr;
			p_curr = p_next;
		}
		mp_head = nullptr;
		mp_tail = nullptr;
		m_count = 0;
	}

	//returns true or false indicating list is empty or not
	template<class T>
	bool LinkedList<T>::is_empty() const
	{
		return m_count == 0;
	}

	//reverse items
	template<class T>
	void LinkedList<T>::reverse()
	{
		auto* p_curr_head = mp_head;
		auto* p_curr_tail = mp_tail;
		for (int i = 0; i < m_count / 2; i++)
		{
			T temp_data = p_curr_head->get_data();
			p_curr_head->set_data(p_curr_tail->get_data());
			p_curr_tail->set_data(temp_data);
			p_curr_head = p_curr_head->get_next();
			p_curr_tail = p_curr_tail->get_prev();
		}
	}
}