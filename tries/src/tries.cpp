//tries.cpp : defines operations for tries
//

#include <assert.h>
#include "tries.hpp"
#include "trie_helper.cpp"

namespace my_lib
{
	template<class T>
	Trie<T>::Trie()
	{
		mp_root = new TrieNode<T>{};
	}

	template<class T>
	Trie<T>::~Trie()
	{
		Clear(mp_root);
	}

	template<class T>
	void Trie<T>::Clear(TrieNode<T> *tp_node)
	{
		if (!tp_node) return;
		for (size_t i = 0; i < ALPHABET_SIZE; i++)
		{
			Clear(tp_node->GetChild(i));
		}
		delete tp_node;
	}

	template<class T>
	void Trie<T>::Insert(std::string t_str, T t_data)
	{
		assert(t_str.length() > 0);
		ToUpper(t_str);
		auto *p_curr = mp_root;
		for (char &c : t_str)
		{
			int index = c - 'A';
			if (!p_curr->GetChild(index))
			{
				p_curr->SetChild(new TrieNode<T>{}, index);
			}
			p_curr = p_curr->GetChild(index);
		}
		p_curr->SetEndOfWord(true);
		p_curr->SetData(t_data);
	}

	template<class T>
	bool Trie<T>::Contains(std::string t_str) const
	{
		assert(t_str.length() > 0);
		ToUpper(t_str);
		auto *p_curr = mp_root;
		for (char& c : t_str)
		{
			int index = c - 'A';
			if (!p_curr->GetChild(index))
			{
				return false;
			}
			p_curr = p_curr->GetChild(index);
		}
		return p_curr->IsEndOfWord();
	}

	template<class T>
	T Trie<T>::GetValue(std::string t_str)
	{
		assert(t_str.length() > 0);
		ToUpper(t_str);
		auto *p_curr = mp_root;
		for (char& c : t_str)
		{
			int index = c - 'A';
			if (!p_curr->GetChild(index)) throw std::runtime_error("No value found!");
			p_curr = p_curr->GetChild(index);
		}
		if (!p_curr->IsEndOfWord()) throw std::runtime_error("No value found!");
		return p_curr->GetData();
	}

	 template<class T>
	 void Trie<T>::Remove(std::string t_str)
	 {
		 assert(t_str.length() > 0);
		 ToUpper(t_str);
		 auto *p_curr = mp_root;
		 char &deleteChar = t_str.at(0);
		 TrieNode<T> *p_deleteNodeParent = mp_root;
		 for (char &c : t_str)
		 {
			 int index = c - 'A';
			 if (!p_curr->GetChild(index)) return;
			 //check if substring present in given string
			 if (p_curr->HasMoreThanSingleChild() || p_curr->IsEndOfWord())
			 {
				 p_deleteNodeParent = p_curr;
				 deleteChar = c;
			 }
			 p_curr = p_curr->GetChild(index);
		 }
		 //if given string is substring of larger string
		 if (!p_curr->IsEmpty())
		 {
			 p_curr->SetEndOfWord(false);
			 p_curr->SetData(nullptr);
		 }
		 else
		 {
			 //clear and reset
			 Clear(p_deleteNodeParent->GetChild(deleteChar - 'A'));
			 p_deleteNodeParent->SetChild(nullptr, deleteChar - 'A');
		 }
	 }
}