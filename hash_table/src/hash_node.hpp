//hash_node.hpp : defines hash node class.
//

#ifndef HASH_NODE_H
#define HASH_NODE_H

#include <iostream>
#include <stdlib.h>

namespace my_lib 
{
	namespace
	{
		template<class K, class T>
		class HashNode
		{
		public:
			HashNode(const K& t_key, const T& t_value) : m_key(t_key), m_value(t_value), mp_next(nullptr) {};
			~HashNode() {}

			K GetKey() const { return m_key; }
			T GetValue() const { return m_value; }
			HashNode<K, T>* GetNext() { return mp_next; }

			void SetKey(K t_key) { m_key = t_key; }
			void SetValue(T t_value) { m_value = t_value; }
			void SetNext(HashNode<K, T>* tp_next) { mp_next = tp_next; }

		private:
			K m_key;
			T m_value;

			HashNode<K, T>* mp_next;
		};
	}
}

#endif // !HASH_NODE_H
