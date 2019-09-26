//trie_helper.cpp : defines helper function for tries.
//

#include <stdlib.h>
#include <string>

namespace my_lib
{
	void ToUpper(std::string &t_str)
	{
		for (char &c : t_str)
		{
			if (c >= 'a' && c <= 'z')
			{
				c += 'A' - 'a';
			}
		}
	}
}