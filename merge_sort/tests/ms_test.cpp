//ms_test.cpp : defines unit test for merge sort
//

#include "gtest/gtest.h"

#include "merge_sort.cpp"
#include <stdlib.h>
#include <iostream>

namespace
{
	struct Student
	{
		int Id = 0;
		std::string Name{ "" };
	};

	const static int TOTAL_STUDENTS = 10;
	const static int ID[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	bool Compare(const Student& t_a, const Student& t_b)
	{
		return (t_a.Id < t_b.Id);
	}

	class SortTest : public ::testing::Test
	{
	protected:

		void SetUp() override
		{
			SetStudent(0, 9, "Brijesh");
			SetStudent(1, 5, "Sandeep");
			SetStudent(2, 1, "Pablo");
			SetStudent(3, 3, "Hai");
			SetStudent(4, 2, "Dave");
			SetStudent(5, 4, "Khush");
			SetStudent(6, 7, "Ray");
			SetStudent(7, 8, "Kirk");
			SetStudent(8, 0, "Vincent");
			SetStudent(9, 6, "Aziz");
		}

		void TearDown() override
		{

		}

		void SetStudent(int t_studentIndex, int t_idIndex, std::string t_name)
		{
			m_students[t_studentIndex].Id = ID[t_idIndex];
			m_students[t_studentIndex].Name = t_name;
		}

		Student m_students[TOTAL_STUDENTS];
	};

	TEST(SimpleMergeSortTest, HandleIntegerSort)
	{
		int result[]{ 10000, 100, 99, 23, 19, 11, 0, 23, 44, 55, 24, 96, 105, 99999, 24 };
		int expected[]{ 0, 11, 19, 23, 23, 24, 24, 44, 55, 96, 99, 100, 105, 10000, 99999 };

		my_lib::MergeSort<int>(result, 15);

		for (int i = 0; i < 15; i++)
		{
			EXPECT_EQ(result[i], expected[i]);
		}
	}

	TEST(SimpleMergeSortTest, HandleDoubleSort)
	{
		double result[]{ 10000.111, 100, 23, 19.71111, 11, 0, 23.07, 99, 44.4, 55.9, 24.7, 96, 105.501, 99999.80, 24.13 };
		double expected[]{ 0, 11, 19.71111, 23, 23.07, 24.13, 24.7, 44.4, 55.9, 96, 99, 100, 105.501, 10000.111, 99999.80 };

		my_lib::MergeSort<double>(result, 15);

		for (int i = 0; i < 15; i++)
		{
			EXPECT_EQ(result[i], expected[i]);
		}
	}

	TEST(SimpleMergeSortTest, HandleCharSort)
	{
		char result[]{ 'Z', 'B', 'a' , 'c', 'O', 'd', 'A' };
		char expected[]{ 'A', 'B', 'O', 'Z', 'a', 'c', 'd', };

		my_lib::MergeSort<char>(result, 7);

		for (int i = 0; i < 7; i++)
		{
			EXPECT_EQ(result[i], expected[i]);
		}
	}

	TEST_F(SortTest, HandleObjectSort)
	{
		my_lib::MergeSort<Student>(m_students, TOTAL_STUDENTS, Compare);

		for (int i = 0; i < TOTAL_STUDENTS; i++)
		{
			EXPECT_EQ(m_students[i].Id, ID[i]);
		}
	}
}