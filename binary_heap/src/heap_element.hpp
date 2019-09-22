//heap_element.hpp : defines heap element
//T - datatype, K - keytype
//requires comparison implemented in keytype
//

#ifndef HEAP_ELEMENT
#define HEAP_ELEMENT

#include <stdlib.h>
#include <iostream>
#include <vector>

namespace my_lib
{
	template<class T, class K>
	class HElement
	{
	public:
		HElement() : m_data(0), m_key(0) {}
		HElement(T t_data, K t_key) : m_data(t_data), m_key(t_key) {}
		~HElement() {}

		T GetData() const { return m_data; }
		void SetData(const T t_data) { m_data = t_data; }
		const K GetKey() const { return m_key; }
		void SetKey(const K t_key) { m_key = t_key; }

	private:
		T m_data;
		K m_key;
	};
}

#endif // MAX_HEAP