//max_heap_test.cpp : defines unit test for MaxHeap
//

#include "gtest/gtest.h"

#include "max_heap.cpp"
#include <stdlib.h>
#include <iostream>

namespace
{
	class MaxHeapTest : public ::testing::Test
	{
	protected:
		void SetUp()
		{
			heap = new my_lib::MaxHeap<int, int>{10};
		}

		void TearDown()
		{
			delete heap;
		}

		my_lib::MaxHeap<int, int> *heap;
	};

	TEST_F(MaxHeapTest, CountShouldReturnItemCount)
	{
		EXPECT_EQ(heap->Count(), 0);
		for (size_t i = 0; i < 15; i++)
		{
			heap->Insert(i, i);
		}
		EXPECT_EQ(heap->Count(), 15);
	}

	TEST_F(MaxHeapTest, InsertShouldAddElement)
	{
		EXPECT_EQ(heap->Count(), 0);
		for (size_t i = 0; i < 15; i++)
		{
			heap->Insert(i, i);
		}
		size_t size = heap->Count();
		for (size_t i = size - 1; i > 0; i--)
		{
			EXPECT_EQ(heap->ExtractMax(), i);
		}
			
	}

	TEST_F(MaxHeapTest, ExtractMaxShouldRemoveMaxElement)
	{
		EXPECT_EQ(heap->Count(), 0);
		for (size_t i = 0; i < 15; i++)
		{
			heap->Insert(i, i);
		}
		size_t size = heap->Count();
		for (size_t i = size - 1; i > 0; i--)
		{
			EXPECT_EQ(heap->ExtractMax(), i);
		}
	}

	TEST_F(MaxHeapTest, RemoveShouldRemoveElementAndRestoreHeap)
	{
		EXPECT_EQ(heap->Count(), 0);
		
		for (size_t n = 0; n < 15; n++)
		{
			heap->Insert(n, n);
		}

		for (size_t i = 0; i < 7; i++)
		{
			heap->Remove(i);
		}

		size_t size = heap->Count();
		for (size_t i = size - 1; i > 7; i--)
		{
			EXPECT_EQ(heap->ExtractMax(), i);
		}
	}
}