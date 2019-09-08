// main.cpp : Defines the entry point for the application.
//

#include "src/headers/linked_list.hpp"
#include "src/linked_list.cpp"

int main()
{
	try
	{
		auto *list = new my_lib::LinkedList<int>{};
		list->add_last(3);
		list->add_last(1);
		list->add_last(7);
		list->add_last(10);

		while (list->count() != 0)
			std::cout << list->pop_back() << " ";
		std::cout << std::endl;

		list->add_first(3);
		list->add_first(1);
		list->add_first(7);
		list->add_first(10);

		list->reverse();


		while (list->count() != 0)
			std::cout << list->pop_front() << " ";
		std::cout << std::endl;

		list->insert_at(0, 0);
		list->insert_at(1, 1);
		list->insert_at(0, 2);
		list->insert_at(3, 3);

		while (list->count() != 0)
			std::cout << list->remove_at(0) << " ";
		std::cout << std::endl;

		my_lib::LinkedList<std::string> str_list {};
		str_list.add_last("Brijesh");
		str_list.add_last("Patel");

		for (size_t i = 0; i < str_list.count(); i++)
			std::cout << str_list[i] << " ";
		std::cout << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
	}
	
	return 0;
}