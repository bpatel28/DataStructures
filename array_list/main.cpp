// main.cpp : Defines the entry point for the application.
//

#include <stdlib.h>
#include <iostream>
#include "array_list.cpp"

int main()
{
	try
	{
		std::cout << "Project Array List" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
	}
	return 0;
}