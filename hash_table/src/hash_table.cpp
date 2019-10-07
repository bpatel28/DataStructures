// hash_table.cpp : Defines the operation for hash table.
//

#include "hash_table.hpp"

namespace my_lib
{
	template<class K, class T, class F>
	HashTable<K, T, F>::HashTable() : m_count(0), m_capacity(INITIAL_CAPACITY)
	{
		mp_table = new HashNode<K, T>*[m_capacity];

		for (size_t i = 0; i < m_capacity; i++)
		{
			mp_table[i] = nullptr;
		}
	}

	template<class K, class T, class F>
	HashTable<K, T, F>::HashTable(size_t t_capacity) : m_count(0), m_capacity(t_capacity)
	{
		mp_table = new HashNode<K, T>*[m_capacity];

		for (size_t i = 0; i < m_capacity; i++)
		{
			mp_table[i] = nullptr;
		}
	}

	template<class K, class T, class F>
	HashTable<K, T, F>::~HashTable()
	{
		for (size_t i = 0; i < m_capacity; i++)
		{
			HashNode<K, T> *p_prev = nullptr;
			HashNode<K, T> *p_entry = mp_table[i];

			while (p_entry)
			{
				p_prev = p_entry;
				p_entry = p_entry->GetNext();

				delete p_prev;
			}
			mp_table[i] = nullptr;
		}

		delete[] mp_table;
	}

	template<class K, class T, class F>
	size_t HashTable<K, T, F>::Count() const
	{
		return m_count;
	}

	template<class K, class T, class F>
	size_t HashTable<K, T, F>::GetHashCode(const size_t &t_hash)
	{
		return t_hash % m_capacity;
	}

	template<class K, class T, class F>
	void HashTable<K, T, F>::Put(const K &t_key, const T &t_value)
	{
		size_t hashCode = GetHashCode(hashFunc(t_key));

		HashNode<K, T> *p_prev = nullptr;
		HashNode<K, T> *p_entry = mp_table[hashCode];

		while (p_entry && p_entry->GetKey() != t_key )
		{
			p_prev = p_entry;
			p_entry = p_entry->GetNext();
		}

		if (p_entry)
		{
			p_entry->SetValue(t_value);
		}
		else
		{
			p_entry = new HashNode<K, T>{ t_key, t_value };
			if (p_prev)
			{
				p_prev->SetNext(p_entry);
			}
			else
			{
				mp_table[hashCode] = p_entry;
			}
			m_count++;
		}
	}

	template<class K, class T, class F>
	T HashTable<K, T, F>::GetValue(const K &t_key)
	{
		size_t hashCode = GetHashCode(hashFunc(t_key));
		HashNode<K, T> *p_entry = mp_table[hashCode];

		while (p_entry)
		{
			if (p_entry->GetKey() == t_key)
			{
				return p_entry->GetValue();
			}
			p_entry = p_entry->GetNext();
		}

		throw std::runtime_error("Invalid key.");
	}

	template<class K, class T, class F>
	K HashTable<K, T, F>::GetKey(const T &t_value)
	{
		for (size_t i = 0; i < m_capacity; i++)
		{
			HashNode<K, T> *p_entry = mp_table[i];
			while (p_entry)
			{
				if (p_entry->GetValue() == t_value)
				{
					return p_entry->GetKey();
				}
				p_entry = p_entry->GetNext();
			}
		}

		throw std::runtime_error("Invalid value.");
	}

	template<class K, class T, class F>
	void HashTable<K, T, F>::Remove(const K &t_key)
	{
		size_t hashCode = GetHashCode(hashFunc(t_key));

		HashNode<K, T> *p_prev = nullptr;
		HashNode<K, T> *p_entry = mp_table[hashCode];

		while (p_entry && p_entry->GetKey() != t_key)
		{
			p_prev = p_entry;
			p_entry = p_entry->GetNext();
		}

		if (p_entry)
		{
			if (p_prev)
			{
				p_prev->SetNext(p_entry->GetNext());
			}
			else
			{
				mp_table[hashCode] = p_entry->GetNext();
			}
			delete p_entry;
			m_count--;
		}
	}
}