//main.cpp : entry point for project and testing lib.
//

#include <stdlib.h>
#include <iostream>
#include "merge_sort.cpp"
#include <string>

int main()
{
	int arr[]{ 5, 3, 2, 4, 1 };

	my_lib::MergeSort(arr, 5);

	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i] << std::endl;
	}


	return 0;
}
