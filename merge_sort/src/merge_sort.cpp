// merge_sort.cpp : Defines the merge sort function.
//

#include "merge_sort.hpp"

namespace my_lib
{
	template<class T>
	void MergeSort(T t_data[], int t_length)
	{
		MergeSort(t_data, 0, t_length - 1);
	}

	template<class T>
	void MergeSort(T t_data[], int t_length, bool t_compare(const T& t_a, const T& t_b))
	{
		MergeSort(t_data, 0, t_length - 1, t_compare);
	}

	namespace
	{
		template<class T>
		void MergeSort(T t_data[], int t_startIndex, int t_endIndex)
		{
			if (t_startIndex < 0 || t_startIndex >= t_endIndex) return;
			int midIndex = t_startIndex + (t_endIndex - t_startIndex) / 2;

			MergeSort(t_data, t_startIndex, midIndex);
			MergeSort(t_data, midIndex + 1, t_endIndex);

			Merge(t_data, t_startIndex, midIndex, t_endIndex);
		}

		template<class T>
		void Merge(T t_data[], int t_left, int t_mid, int t_right)
		{
			int leftArrSize = t_mid - t_left + 1;
			int rightArrSize = t_right - t_mid;

			T *leftArr = new T[leftArrSize];
			T *rightArr = new T[rightArrSize];

			for (int i = 0; i < leftArrSize; ++i)
			{
				leftArr[i] = t_data[t_left + i];
			}

			for (int i = 0; i < rightArrSize; ++i)
			{
				rightArr[i] = t_data[t_mid + i + 1];
			}

			int l = 0, r = 0, i = t_left;
			while (l < leftArrSize && r < rightArrSize)
			{
				if (leftArr[l] <= rightArr[r])
				{
					t_data[i] = leftArr[l++];
				}
				else
				{
					t_data[i] = rightArr[r++];
				}
				i++;
			}

			while (l < leftArrSize)
			{
				t_data[i++] = leftArr[l++];
			}

			while (r < rightArrSize)
			{
				t_data[i++] = rightArr[r++];
			}

			delete[] leftArr;
			delete[] rightArr;
		}

		template<class T>
		void MergeSort(T t_data[], int t_startIndex, int t_endIndex, bool t_compare(const T& t_a, const T& t_b))
		{
			if (t_startIndex < 0 || t_startIndex >= t_endIndex) return;
			int midIndex = t_startIndex + (t_endIndex - t_startIndex) / 2;

			MergeSort(t_data, t_startIndex, midIndex, t_compare);
			MergeSort(t_data, midIndex + 1, t_endIndex, t_compare);

			Merge(t_data, t_startIndex, midIndex, t_endIndex, t_compare);
		}

		template<class T>
		void Merge(T t_data[], int t_left, int t_mid, int t_right, bool t_compare(const T& t_a, const T& t_b))
		{
			int leftArrSize = t_mid - t_left + 1;
			int rightArrSize = t_right - t_mid;

			T* leftArr = new T[leftArrSize];
			T* rightArr = new T[rightArrSize];

			for (int i = 0; i < leftArrSize; ++i)
			{
				leftArr[i] = t_data[t_left + i];
			}

			for (int i = 0; i < rightArrSize; ++i)
			{
				rightArr[i] = t_data[t_mid + i + 1];
			}

			int l = 0, r = 0, i = t_left;
			while (l < leftArrSize && r < rightArrSize)
			{
				if (t_compare(leftArr[l], rightArr[r]))
				{
					t_data[i] = leftArr[l++];
				}
				else
				{
					t_data[i] = rightArr[r++];
				}
				i++;
			}

			while (l < leftArrSize)
			{
				t_data[i++] = leftArr[l++];
			}

			while (r < rightArrSize)
			{
				t_data[i++] = rightArr[r++];
			}

			delete[] leftArr;
			delete[] rightArr;
		}
	}
}