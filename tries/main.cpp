// main.cpp : Defines the entry point for the application.
//

#include "tries.cpp"

int main()
{
	try
	{
		my_lib::Trie<int> trie{};
		trie.Insert("aa", 1);
		trie.Insert("ZZ", 10);
		trie.Insert("bb", 1);
		trie.Remove("ZZ");
		std::cout << trie.GetValue("ZZ") << std::endl;
		std::cout << trie.GetValue("brijesh") << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	return 0;
}