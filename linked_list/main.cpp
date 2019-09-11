// main.cpp : Defines the entry point for the application.
//

#include "linked_list.cpp"

int main()
{
	try
	{
		auto *p_list = new my_lib::LinkedList<int>{};
		p_list->AddLast(3);
		p_list->AddLast(1);
		p_list->AddLast(7);
		p_list->AddLast(10);

		while (p_list->Count() != 0)
			std::cout << p_list->PopBack() << " ";
		std::cout << std::endl;

		p_list->AddFirst(3);
		p_list->AddFirst(1);
		p_list->AddFirst(7);
		p_list->AddFirst(10);

		p_list->Reverse();

		while (p_list->Count() != 0)
			std::cout << p_list->PopFront() << " ";
		std::cout << std::endl;

		p_list->InsertAt(0, 0);
		p_list->InsertAt(1, 1);
		p_list->InsertAt(0, 2);
		p_list->InsertAt(3, 3);

		while (p_list->Count() != 0)
			std::cout << p_list->RemoveAt(0) << " ";
		std::cout << std::endl;

		delete p_list;

		my_lib::LinkedList<std::string> str_list {};
		str_list.AddLast("Brijesh");
		str_list.AddLast("Patel");

		for (size_t i = 0; i < str_list.Count(); i++)
			std::cout << str_list[i] << " ";
		std::cout << std::endl;

		auto *p_int_list = new my_lib::LinkedList<int>{};

		int total_items = 10;
		for (size_t i = 0; i < total_items; i++)
		{
			p_int_list->PushBack(i);
			std::cout << "Found " << (*p_int_list)[i] << " at index " << i << ". Expected " << i << std::endl;
		}
		std::cout << std::endl;

		p_int_list->Reverse();
		for (size_t i = 0; i < p_int_list->Count(); i++)
		{
			total_items--;
			std::cout << "Found " << (*p_int_list)[i] << " at index " << i << ". Expected " << total_items << std::endl;
		}
		std::cout << std::endl;

		delete p_int_list;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
	}
	
	return 0;
}