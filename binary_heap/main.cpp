//main.cpp : entry point for project and testing lib.
//

#include "max_heap.cpp"

int main()
{
	my_lib::MaxHeap<int, int> heap{10};
	for (size_t i = 0; i < 15; i++)
	{
		heap.Insert(i, i);
	}
	for (size_t i = 0; i < heap.Count(); i++)
	{
		std::cout << heap.GetRoot()[i].GetData() << std::endl;
	}
	std::cout << std::endl;

	heap.Remove(10);
	size_t size = heap.Count();
	for (size_t i = 0; i < size; i++)
	{
		std::cout << heap.ExtractMax() << std::endl;
	}

}