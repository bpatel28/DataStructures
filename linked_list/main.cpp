// main.cpp : Defines the entry point for the application.
//

#include "src/headers/linked_list.hpp"
#include "src/linked_list.cpp"

int main()
{
	try
	{
		auto *list = new my_lib::LinkedList<int>{};
		list->AddLast(3);
		list->AddLast(1);
		list->AddLast(7);
		list->AddLast(10);

		while (list->Count() != 0)
			std::cout << list->PopBack() << " ";
		std::cout << std::endl;

		list->AddFirst(3);
		list->AddFirst(1);
		list->AddFirst(7);
		list->AddFirst(10);

		list->Reverse();

		while (list->Count() != 0)
			std::cout << list->PopFront() << " ";
		std::cout << std::endl;

		list->InsertAt(0, 0);
		list->InsertAt(1, 1);
		list->InsertAt(0, 2);
		list->InsertAt(3, 3);

		while (list->Count() != 0)
			std::cout << list->RemoveAt(0) << " ";
		std::cout << std::endl;

		delete list;

		my_lib::LinkedList<std::string> str_list {};
		str_list.AddLast("Brijesh");
		str_list.AddLast("Patel");

		for (size_t i = 0; i < str_list.Count(); i++)
			std::cout << str_list[i] << " ";
		std::cout << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
	}
	
	return 0;
}