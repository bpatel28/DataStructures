//max_heap.hpp : defines max heap data structure
//T - datatype, K - keytype
//requires comparison implemented in keytype
//

#ifndef MAX_HEAP
#define MAX_HEAP

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <assert.h>

#include "heap_element.hpp"

namespace my_lib 
{
	template<class T, class K>
	class MaxHeap
	{
	public:
		explicit MaxHeap(const size_t t_size);
		~MaxHeap();

		const size_t Count() const;
		void Insert(T t_data, K t_key);
		T GetMax() const;
		T ExtractMax();
		HElement<T, K>* GetRoot() const;
		void Remove(T t_data);

	private:

		HElement<T, K> *mp_elements;
		size_t m_count;
		size_t m_size;

		//check size and increase the size of heap if needed
		void CheckSize(size_t t_index = 0);
		//heapify elements to restore heap property - bottom up
		void ShiftUp(size_t t_index);
		//Heapify elemeent to restore heap - top down
		void ShiftDown(size_t t_index);
		//swap method
		void Swap(size_t t_index1, size_t t_index2);
	};
}

#endif // MAX_HEAP
