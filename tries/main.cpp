// main.cpp : Defines the entry point for the application.
//

#include <stdlib.h>
#include <iostream>

#include "tries.cpp"

int main()
{
	my_lib::TrieNode<int> node{};
	int i = 19;
	node.SetData(i);
	i = 18;
	if (!node.GetChild(0))
	{
		std::cout << node.GetData() << std::endl;
	}
	
	return 0;
}