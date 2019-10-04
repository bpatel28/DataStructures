//array_list_test.cpp : unit tests for array list.
//

#include <stdlib.h>
#include <iostream>
#include <string>

#include "array_list.cpp"
#include "gtest/gtest.h"

namespace
{
	TEST(ArrayListTest, CountShouldGiveItemCounts)
	{
		my_lib::ArrayList<int> intList{};
		my_lib::ArrayList<std::string> strList{};

		EXPECT_EQ(intList.Count(), 0);
		EXPECT_EQ(strList.Count(), 0);

		intList.Add(1);
		intList.Add(2);

		strList.Add("Brijesh");
		strList.Add("Hai");

		EXPECT_EQ(intList.Count(), 2);
		EXPECT_EQ(strList.Count(), 2);
	}

	TEST(ArrayListTest, AddShouldAddItemAtTheEnd)
	{
		my_lib::ArrayList<int> intList{};
		my_lib::ArrayList<std::string> strList{};

		intList.Add(10);
		intList.Add(1);
		intList.Add(18);
		intList.Add(7);

		strList.Add("Brijesh");
		strList.Add("Pablo");
		strList.Add("Hai");
		strList.Add("AA");

		EXPECT_EQ(intList.Count(), 4);
		EXPECT_EQ(strList.Count(), 4);

		EXPECT_EQ(intList[0], 10);
		EXPECT_EQ(intList[1], 1);
		EXPECT_EQ(intList[2], 18);
		EXPECT_EQ(intList[3], 7);

		EXPECT_EQ(strList[0], "Brijesh");
		EXPECT_EQ(strList[1], "Pablo");
		EXPECT_EQ(strList[2], "Hai");
		EXPECT_EQ(strList[3], "AA");
	}

	TEST(ArrayListTest, InsertShouldAddElementAtGivenIndex)
	{
		my_lib::ArrayList<int> intList{ { 1, 2, 3, 4, 5 } };
		my_lib::ArrayList<std::string> strList{ {"Brijesh", "Pablo", "Hai", "Sandeep"} };

		intList.Insert(0, 10);
		intList.Insert(3, 7);
		intList.Insert(4, 1);
		intList.Insert(8, 8);

		strList.Insert(0, "Patel");
		strList.Insert(2, "BB");
		strList.Insert(3, "CC");
		strList.Insert(7, "MA");

		EXPECT_EQ(intList[0], 10);
		EXPECT_EQ(intList[1], 1);
		EXPECT_EQ(intList[3], 7);
		EXPECT_EQ(intList[4], 1);
		EXPECT_EQ(intList[5], 3);
		EXPECT_EQ(intList[8], 8);

		EXPECT_EQ(strList[0], "Patel");
		EXPECT_EQ(strList[2], "BB");
		EXPECT_EQ(strList[3], "CC");
		EXPECT_EQ(strList[4], "Pablo");
		EXPECT_EQ(strList[6], "Sandeep");
		EXPECT_EQ(strList[7], "MA");
	}

	TEST(ArrayListTest, RemoveShouldRemoveItemFromEnd)
	{
		my_lib::ArrayList<int> intList{ { 1, 2, 3, 4, 5 } };
		my_lib::ArrayList<std::string> strList{ {"Brijesh", "Pablo", "Hai", "Sandeep"} };

		intList.Remove();
		intList.Remove();
		intList.Remove();
		intList.Remove();
		intList.Remove();

		strList.Remove();
		strList.Remove();
		strList.Remove();
		strList.Remove();

		EXPECT_EQ(intList.Contains(1), false);
		EXPECT_EQ(intList.Contains(2), false);
		EXPECT_EQ(intList.Contains(3), false);
		EXPECT_EQ(intList.Contains(4), false);
		EXPECT_EQ(intList.Contains(5), false);

		EXPECT_EQ(strList.Contains("Brijesh"), false);
		EXPECT_EQ(strList.Contains("Pablo"), false);
		EXPECT_EQ(strList.Contains("Hai"), false);
		EXPECT_EQ(strList.Contains("Sandeep"), false);

	}

	TEST(ArrayListTest, RemoveWithParamShouldRemoveItemFromEnd)
	{
		my_lib::ArrayList<int> intList{ { 1, 2, 3, 4, 5 } };
		my_lib::ArrayList<std::string> strList{ {"Brijesh", "Pablo", "Hai", "Sandeep"} };

		intList.Remove(5);
		intList.Remove(2);
		intList.Remove(1);
		intList.Remove(4);
		intList.Remove(3);

		strList.Remove("Pablo");
		strList.Remove("Hai");
		strList.Remove("Sandeep");
		strList.Remove("Brijesh");

		EXPECT_EQ(intList.Contains(1), false);
		EXPECT_EQ(intList.Contains(2), false);
		EXPECT_EQ(intList.Contains(3), false);
		EXPECT_EQ(intList.Contains(4), false);
		EXPECT_EQ(intList.Contains(5), false);

		EXPECT_EQ(strList.Contains("Brijesh"), false);
		EXPECT_EQ(strList.Contains("Pablo"), false);
		EXPECT_EQ(strList.Contains("Hai"), false);
		EXPECT_EQ(strList.Contains("Sandeep"), false);
	}

	TEST(ArrayListTest, GetIndexShouldGiveIndexOfGivenItem)
	{
		my_lib::ArrayList<int> intList{ { 1, 2, 3, 4, 5 } };
		my_lib::ArrayList<std::string> strList{ {"Brijesh", "Pablo", "Hai", "Sandeep"} };

		EXPECT_EQ(intList.GetIndex(1), 0);
		EXPECT_EQ(intList.GetIndex(2), 1);
		EXPECT_EQ(intList.GetIndex(4), 3);
		EXPECT_EQ(intList.GetIndex(5), 4);
		EXPECT_EQ(intList.GetIndex(3), 2);
		
		EXPECT_EQ(strList.GetIndex("Brijesh"), 0);
		EXPECT_EQ(strList.GetIndex("Hai"), 2);
		EXPECT_EQ(strList.GetIndex("Sandeep"), 3);
		EXPECT_EQ(strList.GetIndex("Pablo"), 1);
	}
}