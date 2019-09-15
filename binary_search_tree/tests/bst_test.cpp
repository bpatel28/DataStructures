//bst_test.cpp : unit test for binary search tree.

#include "gtest/gtest.h"
#include "binary_search_tree/binary_search_tree.cpp"
#include <stdlib.h>
#include <iostream>

namespace
{
	class BSTTest : public ::testing::Test
	{
	protected:
		void SetUp() override
		{
			mp_tree = new my_lib::BinarySearchTree<int, int>{};
		}

		void TearDown() override
		{
			delete mp_tree;
		}

		my_lib::BinarySearchTree<int, int> *mp_tree;
	};


}


