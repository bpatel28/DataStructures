//hash_table_tests.cpp : unit tests for hash table.
//

#include <stdlib.h>
#include <iostream>
#include <vector>

#include "hash_table.cpp"
#include "gtest/gtest.h"

namespace
{
	class HashTableTest : public ::testing::Test
	{
	protected:

		void AddItems(std::vector<std::string> t_keys, std::vector<int> t_values)
		{
			if (t_keys.size() != t_values.size()) return;
			for (size_t i = 0; i < t_keys.size(); i++)
			{
				table.Put(t_keys[i], t_values[i]);
			}
		}

		my_lib::HashTable<std::string, int, std::hash<std::string>> table;
	};


	TEST_F(HashTableTest, CountShouldReturnItemCount)	
	{
		EXPECT_EQ(table.Count(), 0);

		table.Put("A", 1);
		table.Put("B", 5);
		table.Put("C", 8);

		EXPECT_EQ(table.Count(), 3);
	}

	TEST_F(HashTableTest, PutShouldAddItem)
	{
		std::vector<std::string> keys{ "Brijesh", "Brij", "Sandeep", "Pablo", "Hai", "Khush", "parvir"};
		std::vector<int> values{ 1, 2, 3, 4, 5, 6, 7 };
		AddItems(keys, values);

		EXPECT_EQ(table.Count(), keys.size());

		for (size_t i = 0; i < keys.size(); i++)
		{
			EXPECT_EQ(table.GetValue(keys[i]), values[i]);
		}
	}

	TEST_F(HashTableTest, GetKeyeShouldGetKeyAtGivenValue)
	{
		std::vector<std::string> keys{ "Brijesh", "Brij", "Sandeep", "Pablo", "Hai", "Khush", "parvir" };
		std::vector<int> values{ 1, 2, 3, 4, 5, 6, 7 };
		AddItems(keys, values);

		EXPECT_EQ(table.Count(), keys.size());

		for (size_t i = 0; i < keys.size(); i++)
		{
			EXPECT_EQ(table.GetKey(values[i]), keys[i]);
		}
	}

	TEST_F(HashTableTest, RemoveShouldRemoveItemFromTable)
	{
		std::vector<std::string> keys{ "Brijesh", "Brij", "Sandeep", "Pablo", "Hai", "Khush", "Parvir" };
		std::vector<int> values{ 1, 2, 3, 4, 5, 6, 7 };
		AddItems(keys, values);

		table.Remove("Brijesh");
		table.Remove("Sandeep");
		table.Remove("Hai");

		EXPECT_NE(table.Count(), keys.size());
		EXPECT_EQ(table.GetValue("Pablo"), 4);
		EXPECT_EQ(table.GetValue("Khush"), 6);
		EXPECT_EQ(table.GetValue("Parvir"), 7);
	}
}