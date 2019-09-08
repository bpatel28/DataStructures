#include "gtest/gtest.h"

#include "../src/headers/linked_list_node.hpp"
#include "../src/headers/linked_list.hpp"
#include "../src/linked_list.cpp"

namespace my_lib_test {
	class SizeTest : public ::testing::Test {};

	TEST_F(SizeTest, SizeEmpty) {
		my_lib::LinkedList<int> list{};
		size_t size = list.count();

		EXPECT_EQ(size, 0);
	}
}