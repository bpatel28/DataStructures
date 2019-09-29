//qs_test.cpp : defines unit test for quick sort
//

#include "gtest/gtest.h"

#include "quick_sort.cpp"
#include <stdlib.h>
#include <iostream>

namespace
{
	TEST(SimpleQuickSortTest, HandleIntegerSort)
	{
		int result[] {10000, 100, 99, 23, 19, 11, 0, 23, 44, 55, 24, 96, 105, 99999, 24};
		int expected[] {0, 11, 19, 23, 23, 24, 24, 44, 55, 96, 99, 100, 105, 10000, 99999};

		my_lib::QuickSort<int>(result, 15);

		for (int i = 0; i < 15; i++)
		{
			EXPECT_EQ(result[i], expected[i]);
		}
	}

	TEST(SimpleQuickSortTest, HandleDoubleSort)
	{
		double result[]{ 10000.111, 100, 23, 19.71111, 11, 0, 23.07, 99, 44.4, 55.9, 24.7, 96, 105.501, 99999.80, 24.13 };
		double expected[]{ 0, 11, 19.71111, 23, 23.07, 24.13, 24.7, 44.4, 55.9, 96, 99, 100, 105.501, 10000.111, 99999.80 };

		my_lib::QuickSort<double>(result, 15);

		for (int i = 0; i < 15; i++)
		{
			EXPECT_EQ(result[i], expected[i]);
		}
	}

	TEST(SimpleQuickSortTest, HandleCharSort)
	{
		char result[]{ 'Z', 'B', 'a' , 'c', 'O', 'd', 'A' };
		char expected[]{ 'A', 'B', 'O', 'Z', 'a', 'c', 'd', };

		my_lib::QuickSort<char>(result, 7);

		for (int i = 0; i < 7; i++)
		{
			EXPECT_EQ(result[i], expected[i]);
		}
	}
}