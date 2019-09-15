//bst_test.cpp : unit test for binary search tree.

#include "gtest/gtest.h"
#include "binary_search_tree/binary_search_tree.cpp"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

namespace
{
	class BSTTest : public ::testing::Test
	{
	protected:
		void SetUp() override
		{
			mp_ii_tree = new my_lib::BinarySearchTree<int, int>{};
			mp_ss_tree = new my_lib::BinarySearchTree<std::string, char>{};
			mp_si_tree = new my_lib::BinarySearchTree<std::string, int> {};
		}

		void TearDown() override
		{
			delete mp_ii_tree;
		}

		std::vector<int> GetIntKeys(size_t t_total)
		{
			auto *p_keys = new std::vector<int> {};
			for (size_t i = 0; i < t_total; i++)
			{
				p_keys->push_back(i);
			}
			return *p_keys;
		}


		my_lib::BinarySearchTree<int, int> *mp_ii_tree;
		my_lib::BinarySearchTree<std::string, char> *mp_ss_tree;
		my_lib::BinarySearchTree<std::string, int> *mp_si_tree;
	};

	TEST_F(BSTTest, GetRootShouldGiveRootElem)
	{
		EXPECT_EQ(mp_ii_tree->GetRoot(), nullptr);
		EXPECT_EQ(mp_ss_tree->GetRoot(), nullptr);
		EXPECT_EQ(mp_si_tree->GetRoot(), nullptr);

		mp_ii_tree->Insert(1, 1);
		mp_ss_tree->Insert("Brijesh", 'a');
		mp_si_tree->Insert("Brijesh", 1);

		EXPECT_NE(mp_ii_tree->GetRoot(), nullptr);
		EXPECT_NE(mp_ss_tree->GetRoot(), nullptr);
		EXPECT_NE(mp_si_tree->GetRoot(), nullptr);
	}

	TEST_F(BSTTest, InsertShouldAddElement)
	{
		mp_ii_tree->Insert(1, 1);
		mp_ss_tree->Insert("Brijesh", 'a');
		mp_si_tree->Insert("Brijesh", 1);

		EXPECT_EQ(mp_ii_tree->GetRoot()->GetData(), 1);
		EXPECT_EQ(mp_ss_tree->GetRoot()->GetData(), "Brijesh");
		EXPECT_EQ(mp_si_tree->GetRoot()->GetData(), "Brijesh");

		EXPECT_EQ(mp_ii_tree->GetHeight(), 1);
		EXPECT_EQ(mp_ss_tree->GetHeight(), 1);
		EXPECT_EQ(mp_si_tree->GetHeight(), 1);
	}

}


