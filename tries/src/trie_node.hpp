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

		//get child by index
		TrieNode<T>* GetChild(int t_index) const 
		{ 
			assert(t_index >= 0 && t_index < ALPHABET_SIZE);
			return mp_children[t_index];
		}

		//set child at given index
		void SetChild(TrieNode<T> *tp_node, int t_index)
		{
			assert(t_index >= 0 && t_index < ALPHABET_SIZE);
			mp_children[t_index] = tp_node;
		}

		//get data 
		T GetData() const { return *mp_data; }

		//check any child node exists or not
		bool IsEmpty()
		{
			for (size_t i = 0; i < ALPHABET_SIZE; ++i)
			{
				if (GetChild(i))
				{
					return false;
				}
			}
			return true;
		}

		//check more than one child exist
		bool HasMoreThanSingleChild()
		{
			int childCount = 0;
			for (size_t i = 0; i < ALPHABET_SIZE; ++i)
			{
				if (GetChild(i))
				{
					childCount++;
				}
			}
			return childCount > 1;
		}

		//set data
		void SetData(T t_data) { 
			if (!mp_data) delete mp_data;
			mp_data = new T{ t_data }; 
		}

		//set data with pointer
		void SetData(T *t_data) 
		{ 
			if (!mp_data) delete mp_data;
			mp_data = t_data; 
		}


		//check if the node is end of word
		bool IsEndOfWord() const { return m_isEndOfWord; }

		//set end of word
		void SetEndOfWord(bool t_end) { m_isEndOfWord = t_end; }

	private:
		bool m_isEndOfWord;
		T *mp_data;
		TrieNode<T> * mp_children[ALPHABET_SIZE];
	};

}

#endif // !TRIE_NODE
