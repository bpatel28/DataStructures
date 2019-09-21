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
			mp_sc_tree = new my_lib::BinarySearchTree<std::string, char>{};
			mp_si_tree = new my_lib::BinarySearchTree<std::string, int> {};
		}

		void TearDown() override
		{
			delete mp_ii_tree;
		}

		my_lib::BinarySearchTree<int, int> *mp_ii_tree;
		my_lib::BinarySearchTree<std::string, char> * mp_sc_tree;
		my_lib::BinarySearchTree<std::string, int> * mp_si_tree;
	};

	TEST_F(BSTTest, GetRootShouldGiveRootElem)
	{
		EXPECT_EQ(mp_ii_tree->GetRoot(), nullptr);
		EXPECT_EQ(mp_sc_tree->GetRoot(), nullptr);
		EXPECT_EQ(mp_si_tree->GetRoot(), nullptr);

		mp_ii_tree->Insert(1, 1);
		mp_sc_tree->Insert("Brijesh", 'a');
		mp_si_tree->Insert("Brijesh", 1);

		EXPECT_NE(mp_ii_tree->GetRoot(), nullptr);
		EXPECT_NE(mp_sc_tree->GetRoot(), nullptr);
		EXPECT_NE(mp_si_tree->GetRoot(), nullptr);
	}

	TEST_F(BSTTest, InsertShouldAddElement)
	{
		mp_ii_tree->Insert(1, 1);
		mp_sc_tree->Insert("Brijesh", 'a');
		mp_si_tree->Insert("Brijesh", 1);

		EXPECT_EQ(mp_ii_tree->GetRoot()->GetData(), 1);
		EXPECT_EQ(mp_sc_tree->GetRoot()->GetData(), "Brijesh");
		EXPECT_EQ(mp_si_tree->GetRoot()->GetData(), "Brijesh");

		EXPECT_EQ(mp_ii_tree->GetHeight(), 1);
		EXPECT_EQ(mp_sc_tree->GetHeight(), 1);
		EXPECT_EQ(mp_si_tree->GetHeight(), 1);
	}

	TEST_F(BSTTest, FindShouldReturnElementAtProvidedKey)
	{
		mp_si_tree->Insert("Brijesh", 1);
		mp_si_tree->Insert("Patel", 2);
		mp_si_tree->Insert("Hai", 3);
		mp_si_tree->Insert("Pablo", 4);
		mp_si_tree->Insert("Khush", 5);
		mp_si_tree->Insert("Pablo", 6);

		EXPECT_EQ(mp_si_tree->Find(1), "Brijesh");
		EXPECT_EQ(mp_si_tree->Find(2), "Patel");
		EXPECT_EQ(mp_si_tree->Find(3), "Hai");
		EXPECT_EQ(mp_si_tree->Find(4), "Pablo");
		EXPECT_EQ(mp_si_tree->Find(5), "Khush");
		EXPECT_EQ(mp_si_tree->Find(6), "Pablo");

		mp_sc_tree->Insert("Brijesh", 'a');
		mp_sc_tree->Insert("Patel", 'b');
		mp_sc_tree->Insert("Hai", 'c');
		mp_sc_tree->Insert("Pablo",'d');
		mp_sc_tree->Insert("Khush", 'e');
		mp_sc_tree->Insert("Pablo", 'f');

		EXPECT_EQ(mp_sc_tree->Find('a'), "Brijesh");
		EXPECT_EQ(mp_sc_tree->Find('b'), "Patel");
		EXPECT_EQ(mp_sc_tree->Find('c'), "Hai");
		EXPECT_EQ(mp_sc_tree->Find('d'), "Pablo");
		EXPECT_EQ(mp_sc_tree->Find('e'), "Khush");
		EXPECT_EQ(mp_sc_tree->Find('f'), "Pablo");
	}

	TEST_F(BSTTest, ContainsShouldReturnElementAtProvidedKey)
	{
		mp_si_tree->Insert("Brijesh", 1);
		mp_si_tree->Insert("Patel", 2);
		mp_si_tree->Insert("Hai", 3);
		mp_si_tree->Insert("Pablo", 4);
		mp_si_tree->Insert("Khush", 5);
		mp_si_tree->Insert("Pablo", 6);

		EXPECT_EQ(mp_si_tree->Contains("Brijesh"), true);
		EXPECT_EQ(mp_si_tree->Contains("Patel"), true);
		EXPECT_EQ(mp_si_tree->Contains("Hai"), true);
		EXPECT_EQ(mp_si_tree->Contains("Pablo"), true);
		EXPECT_EQ(mp_si_tree->Contains("Khush"), true);
		EXPECT_EQ(mp_si_tree->Contains("Pablo"), true);
	}

	TEST_F(BSTTest, GetKeyShouldReturnElementKey)
	{
		mp_si_tree->Insert("Brijesh", 1);
		mp_si_tree->Insert("Patel", 2);
		mp_si_tree->Insert("Hai", 3);
		mp_si_tree->Insert("Pablo", 4);
		mp_si_tree->Insert("Khush", 5);

		EXPECT_EQ(mp_si_tree->GetKey("Brijesh"), 1);
		EXPECT_EQ(mp_si_tree->GetKey("Patel"), 2);
		EXPECT_EQ(mp_si_tree->GetKey("Hai"), 3);
		EXPECT_EQ(mp_si_tree->GetKey("Pablo"), 4);
		EXPECT_EQ(mp_si_tree->GetKey("Khush"), 5);

		mp_sc_tree->Insert("Brijesh", 'a');
		mp_sc_tree->Insert("Patel", 'b');
		mp_sc_tree->Insert("Hai", 'c');
		mp_sc_tree->Insert("Pablo", 'd');
		mp_sc_tree->Insert("Khush", 'e');
		
		EXPECT_EQ(mp_sc_tree->GetKey("Brijesh"), 'a');
		EXPECT_EQ(mp_sc_tree->GetKey("Patel"), 'b');
		EXPECT_EQ(mp_sc_tree->GetKey("Hai"), 'c');
		EXPECT_EQ(mp_sc_tree->GetKey("Pablo"), 'd');
		EXPECT_EQ(mp_sc_tree->GetKey("Khush"), 'e');
	}

	TEST_F(BSTTest, GetMinShouldReturnMinKeyValueElement)
	{
		for (size_t i = 0; i < 20; i++)
		{
			mp_ii_tree->Insert(i, i);
		}
		for (size_t i = 0; i < 20; i++)
		{
			mp_si_tree->Insert(("A" + std::to_string(i)), i);
		}
		for (size_t i = 0; i < 20; i++)
		{
			mp_sc_tree->Insert(("A" + std::to_string(i)), 'A' + i);
		}
		mp_ii_tree->BalanceTree();
		mp_sc_tree->BalanceTree();
		mp_si_tree->BalanceTree();

		EXPECT_EQ(mp_ii_tree->GetMin(), 0);
		EXPECT_EQ(mp_si_tree->GetMin(), "A0");
		EXPECT_EQ(mp_sc_tree->GetMin(), "A0");
	}

	TEST_F(BSTTest, GetMaxShouldReturnMaxKeyValueElement)
	{
		for (size_t i = 0; i < 20; i++)
		{
			mp_ii_tree->Insert(i, i);
		}
		for (size_t i = 0; i < 20; i++)
		{
			mp_si_tree->Insert(("A" + std::to_string(i)), i);
		}
		for (size_t i = 0; i < 20; i++)
		{
			mp_sc_tree->Insert(("A" + std::to_string(i)), 'A' + i);
		}
		mp_ii_tree->BalanceTree();
		mp_sc_tree->BalanceTree();
		mp_si_tree->BalanceTree();

		EXPECT_EQ(mp_ii_tree->GetMax(), 19);
		EXPECT_EQ(mp_si_tree->GetMax(), "A19");
		EXPECT_EQ(mp_sc_tree->GetMax(), "A19");
	}

	TEST_F(BSTTest, RemoveShouldRemoveElement)
	{
		//add elements
		for (size_t i = 0; i < 20; i++)
		{
			mp_ii_tree->Insert(i, i);
		}
		for (size_t i = 0; i < 20; i++)
		{
			mp_si_tree->Insert(("A" + std::to_string(i)), i);
		}
		for (size_t i = 0; i < 20; i++)
		{
			mp_sc_tree->Insert(("A" + std::to_string(i)), 'A' + i);
		}
		mp_ii_tree->BalanceTree();
		mp_sc_tree->BalanceTree();
		mp_si_tree->BalanceTree();

		//remove element
		for (size_t i = 0; i < 20; i+=2)
		{
			mp_ii_tree->Remove(i);
		}
		for (size_t i = 0; i < 20; i+=2)
		{
			mp_si_tree->Remove(i);
		}
		for (size_t i = 0; i < 20; i+=2)
		{
			mp_sc_tree->Remove('A' + i);
		}

		//test
		for (size_t i = 1; i < 20; i += 2)
		{
			EXPECT_EQ(mp_ii_tree->Find(i), i);
		}
		for (size_t i = 1; i < 20; i += 2)
		{
			EXPECT_EQ(mp_si_tree->Find(i), ("A" + std::to_string(i)));
		}
		for (size_t i = 1; i < 20; i += 2)
		{
			EXPECT_EQ(mp_sc_tree->Find('A' + i), ("A" + std::to_string(i)));
		}
	}

	TEST_F(BSTTest, BalanceTreeShouldMakeTreeBalanced)
	{
		//add elements
		for (size_t i = 0; i < 20; i++)
		{
			mp_ii_tree->Insert(i, i);
		}
		for (size_t i = 0; i < 20; i++)
		{
			mp_si_tree->Insert(("A" + std::to_string(i)), i);
		}
		for (size_t i = 0; i < 20; i++)
		{
			mp_sc_tree->Insert(("A" + std::to_string(i)), 'A' + i);
		}

		//teest
		EXPECT_EQ(mp_ii_tree->IsBalanced(), false);
		EXPECT_EQ(mp_sc_tree->IsBalanced(), false);
		EXPECT_EQ(mp_si_tree->IsBalanced(), false);

		mp_ii_tree->BalanceTree();
		mp_sc_tree->BalanceTree();
		mp_si_tree->BalanceTree();

		//teest
		EXPECT_EQ(mp_ii_tree->IsBalanced(), true);
		EXPECT_EQ(mp_sc_tree->IsBalanced(), true);
		EXPECT_EQ(mp_si_tree->IsBalanced(), true);
	}
}


