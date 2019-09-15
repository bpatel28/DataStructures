#include "gtest/gtest.h"

#include "linked_list.cpp"
#include <stdlib.h>
#include <iostream>

namespace  {

	class LinkedListTest : public ::testing::Test
	{
	protected:
		void SetUp() override {
			mp_int_list = new my_lib::LinkedList<int>{};
		}

		void TearDown() override {
			delete mp_int_list;
		}

		my_lib::LinkedList<int>* mp_int_list;
 	};

	TEST_F(LinkedListTest, CountShouldGiveItemCounts)
	{
		EXPECT_EQ(mp_int_list->Count(), 0);

		mp_int_list->PushBack(1);
		EXPECT_EQ(mp_int_list->Count(), 1);

		mp_int_list->PushFront(2);
		EXPECT_EQ(mp_int_list->Count(), 2);

		mp_int_list->PopBack();
		EXPECT_EQ(mp_int_list->Count(), 1);

		mp_int_list->PopFront();
		EXPECT_EQ(mp_int_list->Count(), 0);
	}

	TEST_F(LinkedListTest, PushBackShouldAddItemAtTheEnd)
	{
		mp_int_list->PushBack(1);
		EXPECT_EQ((*mp_int_list)[mp_int_list->Count() - 1], 1);

		mp_int_list->PushBack(2);
		EXPECT_EQ((*mp_int_list)[mp_int_list->Count() - 1], 2);

		mp_int_list->PushBack(3);
		EXPECT_EQ((*mp_int_list)[mp_int_list->Count() - 1], 3);
	}

	TEST_F(LinkedListTest, PopBackShouldRemoveItemFromEnd)
	{
		mp_int_list->PushBack(1);
		mp_int_list->PushBack(2);
		mp_int_list->PushBack(3);
		mp_int_list->PushBack(4);
		mp_int_list->PushBack(5);

		EXPECT_EQ(mp_int_list->PopBack(), 5);
		EXPECT_EQ(mp_int_list->PopBack(), 4);
		EXPECT_EQ(mp_int_list->PopBack(), 3);
		EXPECT_EQ(mp_int_list->PopBack(), 2);
		EXPECT_EQ(mp_int_list->PopBack(), 1);
	}

	TEST_F(LinkedListTest, PeekBackShouldGiveLastItemWithoutRemoving)
	{
		mp_int_list->PushBack(1);
		mp_int_list->PushBack(2);
		mp_int_list->PushBack(3);
		mp_int_list->PushBack(4);
		mp_int_list->PushBack(5);

		EXPECT_EQ(mp_int_list->PeekBack(), 5);

		mp_int_list->PopBack();
		EXPECT_EQ(mp_int_list->PeekBack(), 4);

		mp_int_list->PopBack();
		EXPECT_EQ(mp_int_list->PeekBack(), 3);

		mp_int_list->PopBack();
		EXPECT_EQ(mp_int_list->PeekBack(), 2);

		mp_int_list->PopBack();
		EXPECT_EQ(mp_int_list->PeekBack(), 1);
	}

	TEST_F(LinkedListTest, PushFrontShouldAddItemAtTheStart)
	{
		mp_int_list->PushFront(1);
		EXPECT_EQ((*mp_int_list)[0], 1);

		mp_int_list->PushFront(2);
		EXPECT_EQ((*mp_int_list)[0], 2);

		mp_int_list->PushFront(3);
		EXPECT_EQ((*mp_int_list)[0], 3);
	}

	TEST_F(LinkedListTest, PopFrontShouldRemoveItemFromStart)
	{
		mp_int_list->PushFront(1);
		mp_int_list->PushFront(2);
		mp_int_list->PushFront(3);
		mp_int_list->PushFront(4);
		mp_int_list->PushFront(5);

		EXPECT_EQ(mp_int_list->PopFront(), 5);
		EXPECT_EQ(mp_int_list->PopFront(), 4);
		EXPECT_EQ(mp_int_list->PopFront(), 3);
		EXPECT_EQ(mp_int_list->PopFront(), 2);
		EXPECT_EQ(mp_int_list->PopFront(), 1);
	}

	TEST_F(LinkedListTest, PeekFrontShouldGiveFirstItemWithoutRemoving)
	{
		mp_int_list->PushFront(1);
		mp_int_list->PushFront(2);
		mp_int_list->PushFront(3);
		mp_int_list->PushFront(4);
		mp_int_list->PushFront(5);

		EXPECT_EQ(mp_int_list->PeekFront(), 5);

		mp_int_list->PopFront();
		EXPECT_EQ(mp_int_list->PeekFront(), 4);

		mp_int_list->PopFront();
		EXPECT_EQ(mp_int_list->PeekFront(), 3);

		mp_int_list->PopFront();
		EXPECT_EQ(mp_int_list->PeekFront(), 2);

		mp_int_list->PopFront();
		EXPECT_EQ(mp_int_list->PeekFront(), 1);
	}

	TEST_F(LinkedListTest, InsertAtShouldAddItemAtGivenIndex)
	{
		mp_int_list->PushBack(1);
		mp_int_list->PushBack(2);
		mp_int_list->PushBack(3);
		mp_int_list->PushBack(4);
		mp_int_list->PushBack(5);

		EXPECT_EQ(mp_int_list->Count(), 5);

		mp_int_list->InsertAt(5, 6);
		EXPECT_EQ((*mp_int_list)[5], 6);
		EXPECT_EQ(mp_int_list->Count(), 6);

		mp_int_list->InsertAt(0, 0);
		EXPECT_EQ((*mp_int_list)[0], 0);
		EXPECT_EQ(mp_int_list->Count(), 7);

		mp_int_list->InsertAt(7, 7);
		EXPECT_EQ((*mp_int_list)[7], 7);
		EXPECT_EQ(mp_int_list->Count(), 8);
	}

	TEST_F(LinkedListTest, RemoveAtShouldRemoveItemAtGivenIndex)
	{
		mp_int_list->PushBack(1);
		mp_int_list->PushBack(2);
		mp_int_list->PushBack(3);
		mp_int_list->PushBack(4);
		mp_int_list->PushBack(5);
		mp_int_list->PushBack(6);
		mp_int_list->PushBack(7);

		EXPECT_EQ(mp_int_list->Count(), 7);

		EXPECT_EQ(mp_int_list->RemoveAt(0), 1);
		EXPECT_EQ(mp_int_list->Count(), 6);

		EXPECT_EQ(mp_int_list->RemoveAt(3), 5);
		EXPECT_EQ(mp_int_list->Count(), 5);

		EXPECT_EQ(mp_int_list->RemoveAt(3), 6);
		EXPECT_EQ(mp_int_list->Count(), 4);

		EXPECT_EQ(mp_int_list->RemoveAt(3), 7);
		EXPECT_EQ(mp_int_list->Count(), 3);
	}

	TEST_F(LinkedListTest, ClearAllShouldDeleteAllElements)
	{
		EXPECT_EQ(mp_int_list->IsEmpty(), true);

		mp_int_list->PushBack(1);
		mp_int_list->PushBack(2);
		mp_int_list->PushBack(3);
		mp_int_list->PushBack(4);
		mp_int_list->PushBack(5);
		mp_int_list->PushBack(6);
		mp_int_list->PushBack(7);

		EXPECT_EQ(mp_int_list->Count(), 7);
		EXPECT_EQ(mp_int_list->IsEmpty(), false);

		mp_int_list->Clear();
		EXPECT_EQ(mp_int_list->Count(), 0);
		EXPECT_EQ(mp_int_list->IsEmpty(), true);
	}

	TEST_F(LinkedListTest, ReverseShouldReverseListContent)
	{
		EXPECT_EQ(mp_int_list->IsEmpty(), true);

		int total_items = 10;
		for (size_t i = 0; i < total_items; i++)
		{
			mp_int_list->PushBack(i);
			EXPECT_EQ((*mp_int_list)[i], i);
		}

		mp_int_list->Reverse();
		for (size_t i = 0; i < mp_int_list->Count(); i++)
		{
			total_items--;
			EXPECT_EQ((*mp_int_list)[i], total_items) << "Found " << (*mp_int_list)[i] << " at index " << i << ". Expected " << total_items;
		}
	}
}