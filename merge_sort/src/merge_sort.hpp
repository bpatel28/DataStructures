﻿// merge_sort.hpp : delcares merge sort function.
// 


#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <stdlib.h>
#include <iostream>

namespace my_lib
{
	template<class T>
	void MergeSort(T t_data[], int t_length);

	template<class T>
	void MergeSort(T t_data[], int t_length, bool t_compare(const T& t_a, const T& t_b));

	namespace
	{
		template<class T>
		void MergeSort(T t_data[], int t_startIndex, int t_endIndex);

		template<class T>
		void Merge(T t_data[], int t_left, int t_mid, int t_right);

		template<class T>
		void MergeSort(T t_data[], int t_startIndex, int t_endIndex, bool t_compare(const T& t_a, const T& t_b));

		template<class T>
		void Merge(T t_data[], int t_left, int t_mid, int t_right, bool t_compare(const T& t_a, const T& t_b));
	}
}


#endif // !MERGE_SORT_H
