// array_list.cpp : Defines the operation of array list
//

#include "array_list.hpp"

namespace my_lib
{
	// constructor 
	template<class T>
	ArrayList<T>::ArrayList() : m_count(0), m_capacity(INITIAL_CAPACITY), mp_data(nullptr) 
	{
		mp_data = new T[m_capacity]; // allocate new array with initial capacity.
	}

	//destructor
	template<class T>
	ArrayList<T>::~ArrayList()
	{
		delete[] mp_data; //clean memory
	}

	//Function to check size of array.
	template<class T>
	size_t ArrayList<T>::Count() const
	{
		return m_count;
	}

	//function to append element at the end of the array.
	template<class T>
	void ArrayList<T>::Add(T t_data)
	{
		GrowArray(); // increase size of array if needed.
		mp_data[m_count] = t_data; // add element at last empty position.
		m_count++; //increase array counts
	}

	//Grow array size if count equals to capacity
	template<class T>
	void ArrayList<T>::GrowArray()
	{
		if (m_count == m_capacity) // if count equals to capacity.
		{
			m_capacity *= GROWTH_FACTOR; //multiply capacity with growth factor.

			T *p_temp = mp_data; // copy data to temp array.
			mp_data = new T[m_capacity]; //allocate new array.

			//copy data from temp to new array.
			for (size_t i = 0; i < m_count; ++i)
			{
				mp_data[i] = p_temp[i];
			}

			//delete temp memory.
			delete[] p_temp;
		}
	}

	//function to insert an element at given index.
	template<class T>
	void ArrayList<T>::Insert(size_t t_index, T t_data)
	{
		// check for valid index.
		if (t_index < 0 || t_index > m_count)
		{
			throw std::runtime_error("Index Out of Range.");
		}
		else
		{
			GrowArray(); // increase size of array if needed.
			
			if (t_index < m_count) // if index is less than last element index.
			{
				// loop from array size to given index.
				// copy elements to next positions
				for (size_t i = m_count; i >= t_index; --i)
				{
					if (i > 0) mp_data[i] = mp_data[i - 1];
					else break;
				}
			}
			mp_data[t_index] = t_data; // add element at given index.
			m_count++; // increase array count.
		}
	}
	
	// function to remove last element from array.
	template<class T>
	void ArrayList<T>::Remove()
	{
		if (m_count > 0)
		{
			m_count--; // decrease count
			ShrinkArray(); // decrease capacity of array if needed.
		}
	}

	// shrink array capacity if free space is more than current size mulitply shrink factor.
	template<class T>
	void ArrayList<T>::ShrinkArray()
	{
		if (m_capacity - m_count > m_count * SHRINK_FACTOR) // if free space is more than current size mulitply shrink factor.
		{
			size_t m_capacity = m_count * GROWTH_FACTOR; // new capacity.

			T* p_temp = mp_data; // temp array.
			
			mp_data = new T[m_capacity]; // new array

			// copy element to new array.
			for (size_t i = 0; i < m_count; ++i)
			{
				mp_data[i] = p_temp[i];
			}

			// delete temp array.
			delete[] p_temp;
		}
	}

	//Function to find an element and delete it from array.
	template<class T>
	void ArrayList<T>::Remove(T t_data)
	{
		size_t index = GetIndex(t_data); // Get index of element.
		if (index >= 0 && index < m_count) // if valid index.
		{
			// copy elements to prev positions.
			for (size_t i = index; i < m_count - 1; ++i)
			{
				mp_data[i] = mp_data[i + 1];
			}
			m_count--;
		}
		// shrink array capacity if needed.
		ShrinkArray();
	}

	// override operator [].
	template<class T>
	T ArrayList<T>::operator[](size_t t_index) const
	{
		// check for valid index.
		if (t_index < 0 || t_index >= m_count)
		{
			throw std::runtime_error("Index Out of Range.");
		}
		else
		{
			return mp_data[t_index]; // return element.
		}
	}

	// Get index of given element.
	template<class T>
	size_t ArrayList<T>::GetIndex(T t_data) const
	{
		// loop until element maches with argument data.
		for (size_t i = 0; i < m_count; ++i)
		{
			if (t_data == mp_data[i])
			{
				return i; // return index.
			}
		}
		// invalid data.
		throw std::runtime_error("No element found.");
	}

	// check if element exists in array.
	template<class T>
	bool ArrayList<T>::Contains(T t_data) const
	{
		// loop until element maches with argument data.
		for (size_t i = 0; i < m_count; ++i)
		{
			if (t_data == mp_data[i])
			{
				return true; // data in array.
			}
		}
		return false; // data not in array.
	}
}
