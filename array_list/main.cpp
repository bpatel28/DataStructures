// main.cpp : Defines the entry point for the application.
//

#include <stdlib.h>
#include <iostream>
#include "array_list.cpp"


int main()
{
	try
	{
		my_lib::ArrayList<int> list{ { 5, 6, 7, 8, 9, 10 } };
		list.Remove();
		list.Remove(5);
		list.Insert(0, 5);
		list.Insert(1, 2);
		list.Insert(6, 10);
		list.Add(1);
		list.Add(2);
		list.Remove();
		list.Remove(6);
		list.Remove(8);
		list.Remove(9);
		for (size_t i = 0; i < list.Count(); i++)
		{
			std::cout << list[i] << std::endl;
		}
		std::cout << "count ->" << list.Count() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
	}
	return 0;
}