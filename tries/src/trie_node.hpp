//trie_node.hpp : defines trie node.
//

#ifndef TRIE_NODE
#define TRIE_NODE

#include <stdlib.h>
#include <iostream>

namespace my_lib
{
	const int ALPHABET_SIZE = 26;

	template<class T>
	class TrieNode
	{
	public:
		TrieNode() : mp_data(nullptr), m_isEndOfWord(false) 
		{
			for (size_t i = 0; i < ALPHABET_SIZE; i++)
			{
				mp_children[i] = nullptr;
			}
		}
		~TrieNode() { delete mp_data; }

		TrieNode<T>* GetChild(int t_index) const 
		{ 
			if (t_index < 0 && t_index > ALPHABET_SIZE)
			{
				std::runtime_error("Index Out of Range.");
			}
			return mp_children[t_index]; 
		}

		void SetChild(TrieNode<T> *tp_node, int t_index)
		{
			if (t_index < 0 && t_index > ALPHABET_SIZE)
			{
				std::runtime_error("Index Out of Range.");
			}
			mp_children[t_index] = tp_node;
		}

		T GetData() const { return *mp_data; }
		void SetData(T t_data) { mp_data = new T{ t_data }; }

		bool IsEndOfWord() const { return m_isEndOfWord; }
		void SetEndOfWord(bool t_end) { m_isEndOfWord = t_end; }

	private:
		bool m_isEndOfWord;
		T *mp_data;
		TrieNode<T> *mp_children[ALPHABET_SIZE];
	};

}

#endif // !TRIE_NODE
