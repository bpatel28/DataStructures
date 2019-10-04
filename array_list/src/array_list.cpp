// array_list.cpp : Defines the operation of array list
//

#include "array_list.hpp"

namespace my_lib
{
	template<class T>
	ArrayList<T>::ArrayList() : m_count(0), m_capacity(INITIAL_CAPACITY), mp_data(nullptr) {}

	template<class T>
	template<size_t N>
	ArrayList<T>::ArrayList(const T(&t_data)[N]) : m_count(N), m_capacity(N * GROWTH_FACTOR) 
	{
		mp_data = new T[m_capacity];
		for (size_t i = 0; i < N; ++i)
		{
			mp_data[i] = t_data[i];
		}
	}

	template<class T>
	ArrayList<T>::~ArrayList()
	{
		delete[] mp_data;
	}

	template<class T>
	size_t ArrayList<T>::Count() const
	{
		return m_count;
	}

	template<class T>
	void ArrayList<T>::Add(T t_data)
	{
		GrowArray();
		mp_data[m_count] = t_data;
		m_count++;
	}

	template<class T>
	void ArrayList<T>::GrowArray()
	{
		if (m_count >= m_capacity)
		{
			m_capacity *= GROWTH_FACTOR;

			T *p_temp = mp_data;
			mp_data = new T[m_capacity];

			for (size_t i = 0; i < m_count; ++i)
			{
				mp_data[i] = p_temp[i];
			}

			delete[] p_temp;
			std::cout << m_count << " GROW " << m_capacity << std::endl;
		}
	}

	template<class T>
	void ArrayList<T>::Insert(size_t t_index, T t_data)
	{
		if (t_index < 0 || t_index > m_count)
		{
			throw std::runtime_error("Index Out of Range.");
		}
		else
		{
			GrowArray();
			if (t_index < m_count)
			{
				for (size_t i = m_count; i >= t_index; --i)
				{
					if (i > 0) mp_data[i] = mp_data[i - 1];
					else break;
				}
			}
			mp_data[t_index] = t_data;
			m_count++;
		}
	}
	
	template<class T>
	void ArrayList<T>::Remove()
	{
		if (m_count > 0)
		{
			m_count--;
			ShrinkArray();
		}
	}

	template<class T>
	void ArrayList<T>::ShrinkArray()
	{
		if (m_capacity - m_count > m_count * SHRINK_FACTOR)
		{
			size_t m_capacity = m_count * GROWTH_FACTOR;

			T* p_temp = mp_data;
			mp_data = new T[m_capacity];
			for (size_t i = 0; i < m_count; ++i)
			{
				mp_data[i] = p_temp[i];
			}
			std::cout << m_count << " shrink " << m_capacity << std::endl;
			delete[] p_temp;
		}
	}


	template<class T>
	void ArrayList<T>::Remove(T t_data)
	{
		int index = GetIndex(t_data);
		if (index >= 0 && index < m_count)
		{
			for (size_t i = index; i < m_count - 1; i++)
			{
				mp_data[i] = mp_data[i + 1];
			}
			m_count--;
		}
		ShrinkArray();
	}

	template<class T>
	T ArrayList<T>::operator[](size_t t_index) const
	{
		if (t_index < 0 || t_index >= m_count)
		{
			throw std::runtime_error("Index Out of Range.");
		}
		else
		{
			return mp_data[t_index];
		}
	}


	template<class T>
	int ArrayList<T>::GetIndex(T t_data) const
	{
		for (size_t i = 0; i < m_count; i++)
		{
			if (t_data == mp_data[i])
			{
				return i;
			}
		}
		return -1;
	}

	template<class T>
	bool ArrayList<T>::Contains(T t_data) const
	{
		for (size_t i = 0; i < m_count; i++)
		{
			if (t_data == mp_data[i])
			{
				return true;
			}
		}
		return false;
	}
}