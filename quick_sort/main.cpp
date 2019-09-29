//main.cpp : entry point for project and testing lib.
//

#include <stdlib.h>
#include <iostream>
#include "quick_sort.cpp"
#include <string>

struct Student
{
	int Id = 0;
	std::string Name{ "" };
};

bool Compare(const Student& t_a, const Student& t_b);

int main()
{
	int arr[]{5, 3, 2, 4, 1};

	my_lib::QuickSort(arr, 5);

	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i] << std::endl;
	}

	const int totalStudents = 5;

	Student students[totalStudents];

	for (int i = 0; i < totalStudents; i++)
	{
		students[totalStudents - 1 - i].Id = i;
		students[i].Name = "A" + std::to_string(i);
	}

	my_lib::QuickSort(students, totalStudents, Compare);

	for (int i = 0; i < totalStudents; i++)
	{
		std::cout << students[i].Id << " - " << students[i].Name << std::endl;
	}
}

bool Compare(const Student& t_a, const Student& t_b)
{
	return (t_a.Id < t_b.Id);
}

