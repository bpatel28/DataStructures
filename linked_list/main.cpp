// main.cpp : Defines the entry point for the application.
//

#include "src/headers/linked_list.hpp"
#include "src/linked_list.cpp"

int main()
{
	try
	{
		my_lib::LinkedList<int> list{};
		list.add(3);
		list.add(1);
		list.add(7);
		list.add(10);
		list.remove();

		while (list.count() != 0)
		{
			std::cout << list.pop() << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
	}
	
	return 0;
}