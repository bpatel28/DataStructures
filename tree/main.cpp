
#include "bt_node.hpp"

int main()
{
	my_lib::BTNode<int> node;
	std::cout << node.GetData() << std::endl;
	return 0;
}