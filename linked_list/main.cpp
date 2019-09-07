// main.cpp : Defines the entry point for the application.
//

#include "src/headers/linked_list.hpp"
#include <iostream>

using namespace std;

int main()
{
	my_lib::LinkedListNode<int> node{5};
	cout << node.get_data() << endl;
	return 0;
}