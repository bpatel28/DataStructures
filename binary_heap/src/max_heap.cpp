//max_heap.cpp : defination for max heap operations.
//T - datatype, K - keytype
//requires comparison implemented in keytype.

#include "max_heap.hpp"

namespace my_lib
{
	template<class T, class K>
	MaxHeap<T, K>::MaxHeap(const size_t t_size) : m_count(0), m_size(t_size)
	{
		assert(t_size > 0 && t_size < SIZE_MAX);
		mp_elements = new HElement<T, K>[t_size];
	}

	template<class T, class K>
	MaxHeap<T, K>::~MaxHeap()
	{
		delete[] mp_elements;
	}

	template<class T, class K>
	const size_t MaxHeap<T, K>::Count() const
	{
		return m_count;
	}

	template<class T, class K>
	void MaxHeap<T, K>::Insert(T t_data, K t_key)
	{
		CheckSize(++m_count);
		mp_elements[m_count - 1].SetData(t_data);
		mp_elements[m_count - 1].SetKey(t_key);
		ShiftUp(m_count - 1);
	}

	template<class T, class K>
	void MaxHeap<T, K>::CheckSize(size_t t_index)
	{
		assert(t_index < SIZE_MAX);
		if (t_index > m_size)
		{
			m_size += t_index; //new capacity of heap
			HElement<T, K> *p_temp_arr = new HElement<T, K>[m_size];
			for (size_t i = 0; i < m_count; i++)
			{
				p_temp_arr[i] = mp_elements[i];
			}
			delete[] mp_elements;
			mp_elements = p_temp_arr;
		}
	}

	template<class T, class K>
	void MaxHeap<T, K>::ShiftUp(size_t t_index)
	{
		while (t_index > 0)
		{
			size_t parent_index = (t_index - 1) / 2;
			if (mp_elements[parent_index].GetKey() < mp_elements[t_index].GetKey())
			{
				Swap(t_index, parent_index);
			} 
			else
			{
				break;
			}
			t_index = parent_index;
		}
	}

	template<class T, class K>
	HElement<T,K>* MaxHeap<T, K>::GetRoot() const
	{
		return mp_elements;
	}

	template<class T, class K>
	T MaxHeap<T, K>::GetMax() const
	{
		assert(m_count != 0);
		return mp_elements->GetData();
	}

	template<class T, class K>
	T MaxHeap<T, K>::ExtractMax()
	{
		T data = GetMax();
		if (m_count == 1)
		{
			m_count--;
		}
		else if (m_count > 1)
		{
			m_count--;
			mp_elements[0].SetData(mp_elements[m_count].GetData());
			mp_elements[0].SetKey(mp_elements[m_count].GetKey());
			ShiftDown(0);
		}
		return data;
	}

	template<class T, class K>
	void MaxHeap<T, K>::ShiftDown(size_t t_index)
	{
		while (((t_index * 2) + 1) < m_count)
		{
			size_t left_child_index = (t_index * 2) + 1;
			size_t right_child_index = (t_index * 2) + 2;
			size_t largest_index;
			if (right_child_index < m_count && mp_elements[right_child_index].GetKey() > mp_elements[left_child_index].GetKey())
				largest_index = right_child_index;
			else
				largest_index = left_child_index;
			if (mp_elements[t_index].GetKey() < mp_elements[largest_index].GetKey())
			{
				Swap(t_index, largest_index);
			}
			else
			{
				break;
			}
			t_index = largest_index;
		}
	}

	template<class T, class K>
	void MaxHeap<T, K>::Swap(size_t t_index1, size_t t_index2)
	{
		K temp_key = mp_elements[t_index1].GetKey();
		T temp_data = mp_elements[t_index1].GetData();
		mp_elements[t_index1].SetKey(mp_elements[t_index2].GetKey());
		mp_elements[t_index1].SetData(mp_elements[t_index2].GetData());
		mp_elements[t_index2].SetKey(temp_key);
		mp_elements[t_index2].SetData(temp_data);
	}

	template<class T, class K>
	void MaxHeap<T, K>::Remove(T t_data)
	{
		size_t remove_index = -1;
		for (size_t i = 0; i < m_count; i++)
		{
			if (t_data == mp_elements[i].GetData())
			{
				remove_index = i;
				break;
			}
		}
		if (remove_index < 0) return;
		m_count--;
		mp_elements[remove_index].SetData(mp_elements[m_count].GetData());
		mp_elements[remove_index].SetKey(mp_elements[m_count].GetKey());
		ShiftDown(remove_index);
	}
}

