// tries.hpp : defines tries data structure

#ifndef TRIES
#define TRIES

#include "trie_node.hpp"

namespace my_lib
{
	template<class T>
	class Trie
	{
	public:
		Trie();
		~Trie();

		//insert string in the trie
		void Insert(std::string t_str, T t_data);
		//check if string exist in trie
		bool Contains(std::string t_str) const;
		//get value by providing string key
		T GetValue(std::string t_str);
		//remove string from the tree.
		void Remove(std::string t_str);

	private:
		TrieNode<T>* mp_root;

		//remove child nodes of given node
		void Clear(TrieNode<T> *t_node);
	};
}

#endif // !TRIES

