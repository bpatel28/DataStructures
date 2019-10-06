// main.cpp : Defines the entry point for the application.
//

#include <stdlib.h>
#include <iostream>

#include "hash_table.cpp"

int main()
{
	try
	{
		std::cout << "Hash Table" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
	}
	return 0;
}