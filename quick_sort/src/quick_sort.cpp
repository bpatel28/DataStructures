﻿//quick_sort.cpp : defines operations for quick sort class.
//

#include "quick_sort.hpp";

namespace my_lib
{
	namespace
	{

		template<class T>
		void QuickSort(T t_arr[] , int t_left, int t_right)
		{
			if (t_left < 0 || t_left > t_right) return;
			
			int pivotIndex = t_right;

			int l = 0;
			for (int i = t_left; i < t_right; i++)
			{
				if (t_arr[i] < t_arr[pivotIndex])
				{
					Swap(&t_arr[l++], &t_arr[i]);
				}
			}
			Swap(&t_arr[l++], &t_arr[pivotIndex]);

			QuickSort(t_arr, t_left, pivotIndex - 1);
			QuickSort(t_arr, pivotIndex + 1, t_right);
		}

		template<class T>
		void Swap(T* t_a, T* t_b)
		{
			T temp = *t_a;
			*t_a = *t_b;
			*t_b = temp;
		}

		template<class T>
		void QuickSort(T t_arr[], int t_left, int t_right, bool t_compare(const T &t_a, const T &t_b))
		{

		}
	}

	template<class T> 
	void QuickSort(T t_arr[], int t_length)
	{
		QuickSort(t_arr, 0, t_length - 1);
	}

	template<class T>
	void QuickSort(T t_arr[], int t_length, bool t_compare(const T &t_a, const T &t_b))
	{
		QuickSort(t_arr, 0, t_length - 1, t_compare);
	}
}