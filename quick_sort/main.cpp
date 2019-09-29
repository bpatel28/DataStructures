//main.cpp : entry point for project and testing lib.
//

#include <stdlib.h>
#include <iostream>
#include "quick_sort.cpp"

int main()
{
	int arr[]{5, 3, 2, 4, 1};

	my_lib::QuickSort(arr, 5);

	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i] << std::endl;
	}
}