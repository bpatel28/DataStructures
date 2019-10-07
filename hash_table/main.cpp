// main.cpp : Defines the entry point for the application.
//

#include <stdlib.h>
#include <iostream>

#include "hash_table.cpp"

int main()
{
	try
	{
		my_lib::HashTable<int, int, std::hash<int>> table{};

		table.Put(1, 2);
		table.Put(2, 3);
		table.Put(4, 10);

		std::cout << table.GetValue(1) << std::endl;
		std::cout << table.GetValue(2) << std::endl;
		std::cout << table.GetValue(4) << std::endl;
		std::cout << "Count : " << table.Count() << std::endl;
		table.Remove(1);
		std::cout << "Count : " << table.Count() << std::endl;

		my_lib::HashTable<std::string, int, std::hash<std::string>> strTable{};

		strTable.Put("Brijesh", 5);
		strTable.Put("Patel", 28);

		std::cout << strTable.GetValue("Brijesh") << std::endl;
		std::cout << strTable.GetValue("Patel") << std::endl;
		std::cout << "Count : " << strTable.Count() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
	}
	return 0;
}