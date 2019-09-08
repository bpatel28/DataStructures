// linked_list.cpp : Defines the functions for linked_list class.
//

#include "headers/linked_list.hpp"

namespace my_lib {

	//destroy list.
	template <class T>
	LinkedList<T>::~LinkedList()
	{
		LinkedListNode<T> *p_current = mp_head;
		LinkedListNode<T> *p_next = nullptr;
		while (p_current)
		{
			p_next = p_current->GetNext();
			delete p_current;
			p_current = p_next;
		}
	}

	//return count.
	template <class T>
	size_t LinkedList<T>::Count() const
	{
		return m_count;
	}

	//push item at the tail of the list.
	template<class T>
	void LinkedList<T>::PushBack(const T& t_data)
	{
		auto *data = new LinkedListNode<T> { t_data };

		if (!mp_head)
		{
			mp_head = data;
			mp_tail = data;
		}
		else
		{
			mp_tail->SetNext(data);
			auto p_prev = mp_tail;
			mp_tail = mp_tail->GetNext();
			mp_tail->SetPrev(p_prev);
		}
		m_count++;
	}

	//pop item from tail of the list.
	template<class T>
	T LinkedList<T>::PopBack() 
	{
		if (!mp_tail) throw std::runtime_error("Empty List.");
		auto p_data = mp_tail->GetData();
		auto p_prev = mp_tail->GetPrev();
		delete mp_tail;
		mp_tail = p_prev;
		if (m_count == 1) mp_head = p_prev;
		m_count--;
		return p_data;
	}

	//return item at the tail of the list.
	template<class T>
	T LinkedList<T>::PeekBack() const
	{
		if (!mp_tail) throw "Empty List.";
		auto data = mp_tail->GetData();
		return data;
	}

	//add item at the tail of the list.
	template<class T>
	void LinkedList<T>::AddLast(const T &t_data)
	{
		PushBack(t_data);
	}

	//remove item frome tail of the list.
	template<class T>
	T LinkedList<T>::RemoveLast()
	{
		return PopBack();
	}

	//push element at front
	template<class T>
	void LinkedList<T>::PushFront(const T &t_data) {
		if (!mp_head)
		{
			mp_head = new LinkedListNode<T>{ t_data };
			mp_tail = mp_head;
		}
		else
		{
			auto* p_data = new LinkedListNode<T>{ t_data };
			p_data->SetNext(mp_head);
			mp_head->SetPrev(p_data);
			mp_head = p_data;
		}
		m_count++;
	}

	//remove element from front
	template<class T>
	T LinkedList<T>::PopFront() 
	{
		if (!mp_head) throw std::runtime_error("Empty List.");
		auto data = mp_head->GetData();
		auto* p_next = mp_head->GetNext();
		delete mp_head;
		mp_head = p_next;
		if (m_count == 1) mp_tail = p_next;
		m_count--;
		return data;
	}

	//show first element
	template<class T>
	T LinkedList<T>::PeekFront() const
	{
		if (!mp_head) throw std::runtime_error("Empty List.");
		auto data = mp_head->GetData();
		return data;
	}

	//add element to the head
	template<class T>
	void LinkedList<T>::AddFirst(const T& t_data)
	{
		PushFront(t_data);
	}

	//remove element from the head
	template<class T>
	T LinkedList<T>::RemoveFirst()
	{
		return PopFront();
	}

	//insert element at specified index
	template<class T>
	void LinkedList<T>::InsertAt(int t_index, const T& t_data)
	{
		if (t_index < 0 || t_index > m_count) throw std::runtime_error("Index Out of Range.");
		if (t_index == m_count) 
		{
			PushBack(t_data);
		}
		else if (t_index == 0)
		{
			AddFirst(t_data);
		}
		else
		{
			LinkedListNode<T>* p_curr = mp_head;
			for (size_t i = 1; i != t_index; i++)
			{
				p_curr = p_curr->GetNext();
			}
			auto* p_data = new LinkedListNode<T>{ t_data };
			p_data->SetPrev(p_curr->GetPrev());
			p_data->SetNext(p_curr);
			p_curr = p_data;
			m_count++;
		}
	}

	//removed element from at index
	template<class T>
	T LinkedList<T>::RemoveAt(int t_index)
	{
		if (t_index < 0 || t_index > m_count) throw std::runtime_error("Index Out of Range.");
		if (t_index == m_count) return PopBack();
		if (t_index == 0) return RemoveFirst();
		LinkedListNode<T>* p_curr = mp_head;
		for (size_t i = 1; i != t_index; i++)
		{
			p_curr = p_curr->GetNext();
		}
		auto *p_data = p_curr;
		auto data = p_data->GetData();
		p_curr->SetPrev(p_curr->GetNext());
		delete p_data;
		m_count--;
		return data;
	}

	//access element at specified index
	template<class T>
	T LinkedList<T>::operator[](int t_index) const
	{
		if (t_index < 0 || t_index >= m_count) throw std::runtime_error("Index Out of Range.");
		if (t_index == m_count - 1) return PeekBack();
		if (t_index == 0) return PeekFront();
		LinkedListNode<T>* p_curr = mp_head;
		for (size_t i = 1; i != t_index; i++)
		{
			p_curr = p_curr->GetNext();
		}
		return p_curr->GetData();
	}

	//clear all the items from the list
	template<class T>
	void LinkedList<T>::Clear()
	{
		if (m_count == 0) return;
		auto *p_curr = mp_head;
		LinkedListNode<T>* p_next = nullptr;
		while (p_curr)
		{
			p_next = p_curr->GetNext();
			delete p_curr;
			p_curr = p_next;
		}
		mp_head = nullptr;
		mp_tail = nullptr;
		m_count = 0;
	}

	//returns true or false indicating list is empty or not
	template<class T>
	bool LinkedList<T>::IsEmpty() const
	{
		return m_count == 0;
	}

	//reverse items
	template<class T>
	void LinkedList<T>::Reverse()
	{
		LinkedListNode<T> *p_prev = nullptr;
		LinkedListNode<T> *p_curr = mp_head;
		LinkedListNode<T> *p_next = nullptr;
		while (p_curr) {
			p_next = p_curr->GetNext();
			p_curr->SetNext(p_prev);
			p_curr->SetPrev(p_next);
			p_prev = p_curr;
			p_curr = p_next;
		}
		mp_tail = mp_head;
		mp_head = p_prev;
	}

}