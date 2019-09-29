//quick_sort.hpp : declare quick sort function.
//

#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <stdlib.h>

namespace my_lib
{
	namespace
	{
		template<class T>
		void Swap(T *t_a, T *t_b);

		template<class T>
		int Partition(T arr[], int t_left, int t_right);

		template<class T>
		void QuickSort(T t_arr[], int t_left, int t_right);

		template<class T>
		void QuickSort(T t_arr[], int t_left, int t_right, bool t_compare(const T &t_a, const T &t_b));
	}

	template<class T>
	void QuickSort(T t_arr[], int t_length);

	template<class T>
	void QuickSort(T t_arr[], int t_length, bool t_compare(const T &t_a, const T &t_b));
}

#endif // !QUICK_SORT_H
