//tries_test.cpp : unit tests for tries.
//

#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

#include "tries.cpp"
#include "gtest/gtest.h"

namespace
{
	class TrieTest : public ::testing::Test
	{
	protected:

		my_lib::Trie<int> m_trie;
	};

	TEST_F(TrieTest, InsertShouldAddNewString)
	{
		std::string keys[] = {"A", "AB", "ABC", "ABCD", "ABCDE", "B", "BAB", "BACD", "ZZ", "CC"};
		int values[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

		for (size_t i = 0; i < 10; i++)
		{
			m_trie.Insert(keys[i], values[i]);
		}

		for (size_t i = 0; i < 10; i++)
		{
			EXPECT_EQ(m_trie.Contains(keys[i]), true);
		}
		
	}

	TEST_F(TrieTest, GetValueShouldGiveValuesInTrie)
	{
		std::string keys[] = { "A", "AB", "ABC", "ABCD", "ABCDE", "B", "BAB", "BACD", "ZZ", "CC" };
		int values[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

		for (size_t i = 0; i < 10; i++)
		{
			m_trie.Insert(keys[i], values[i]);
		}

		for (size_t i = 0; i < 10; i++)
		{
			EXPECT_EQ(m_trie.GetValue(keys[i]), values[i]);
		}
	}

	TEST_F(TrieTest, RemoveShouldRemoveKeyValue)
	{
		std::string keys[] = { "A", "AB", "ABC", "ABCD", "ABCDE", "B", "BAB", "BACD", "ZZ", "CC" };
		int values[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

		for (size_t i = 0; i < 10; i++)
		{
			m_trie.Insert(keys[i], values[i]);
		}

		for (size_t i = 0; i < 10; i+=2)
		{
			m_trie.Remove(keys[i]);
		}

		for (size_t i = 1; i < 10; i+=2)
		{
			EXPECT_EQ(m_trie.Contains(keys[i]), true);
		}
	}
}