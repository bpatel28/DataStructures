// array_list.h : declare array list class
//

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdlib.h>
#include <iostream>

namespace my_lib
{

	namespace
	{
		static size_t const INITIAL_CAPACITY = 10;
		static size_t const GROWTH_FACTOR = 2;
		static size_t const SHRINK_FACTOR = 4;
	}

	template<class T>
	class ArrayList
	{
	public:
		ArrayList();

		template<size_t N>
		ArrayList(const T(&t_data)[N]);

		~ArrayList();

		//add new item
		void Add(T t_data);
		//Insert item at given index
		void Insert(size_t t_index, T t_data);
		//remove last item
		void Remove();
		//remove given item
		void Remove(T t_data);

		//access element by index
		T operator[](size_t index) const;
		//get index of data
		size_t GetIndex(T t_data) const;
		//check if list contains item
		bool Contains(T t_data) const;
		
		size_t Count() const;

	private:
		size_t m_capacity;
		size_t m_count;

		T *mp_data;

		void GrowArray();
		void ShrinkArray();
	};
}

#endif // !ARRAY_LIST_H
