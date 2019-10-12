// hash_table.hpp : declare hash table class.
//

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "hash_node.hpp"

namespace my_lib
{

	namespace
	{
		const size_t INITIAL_CAPACITY = 100;
	}

	template<class K, class T, class F = std::hash<K>>
	class HashTable
	{
	public:
		HashTable();
		HashTable(size_t t_capacity);
		~HashTable();

		void Put(const K &t_key, const T &t_value);
		void Remove(const K &t_key);
		T GetValue(const K &t_key);
		K GetKey(const T &t_value);

		size_t Count() const;

	private:
		HashNode<K, T> **mp_table;
		size_t m_count;
		size_t m_capacity;

		F hashFunc;
		size_t GetHashCode(const size_t &t_hash);
	};
}

#endif // !HASH_TABLE_H
