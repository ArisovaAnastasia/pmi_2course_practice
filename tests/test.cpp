#include "..\gtest\gtest.h"
#include <string>
#include <vector>

#include "vector.h"

TEST(vector, ctor_test1) {
	ASSERT_NO_THROW(Vector v);
}

TEST(vector, ctor_test2) {
	ASSERT_NO_THROW(Vector v(5));
}

TEST(vector, ctor_test3) {
	ASSERT_NO_THROW(Vector v(std::initializer_list<int>{5,4,3,2,1}));
}

TEST(vector, ctor_test4) {
	Vector v1({5,4,3,2,1});
	ASSERT_NO_THROW(Vector v2 = v1);
}

TEST(vector, cpy_assign_test) {
	Vector v1{3,1,4,1,5,9,2,6}, v2{2,3,7};
	ASSERT_NO_THROW(v2 = v1);
}

TEST(vector, swap_test) {
	Vector v1{3,1,4,1,5,9,2,6}, v2{2,3,7};
	ASSERT_NO_THROW(v1.Swap(v2));
}

TEST(vector, idx_operator_test) {
	Vector v1{3,1,4,1,5,9,2,6};
	ASSERT_NO_THROW(v1[0]);
	ASSERT_NO_THROW(v1[7]);
}

TEST(vector, const_idx_operator_test) {
	const Vector v1{3,1,4,1,5,9,2,6};
	ASSERT_NO_THROW(v1[0]);
	ASSERT_NO_THROW(v1[7]);
}

TEST(vector, size_test) {
	Vector v1{3,1,4,1,5,9,2,6}, v2;
	EXPECT_EQ(v1.Size(), 8);
	EXPECT_EQ(v2.Size(), 0);
}

TEST(vector, capacity_test) {
	Vector v1{3,1,4,1,5,9,2,6}, v2;

	EXPECT_EQ(v1.Capacity(), 8);
	v1.PushBack(5);
	EXPECT_EQ(v1.Capacity(), 16);


	EXPECT_EQ(v2.Capacity(), 0);
	v2.PushBack(62);
	EXPECT_EQ(v2.Capacity(), 1);
}

TEST(vector, push_back_test) {
	Vector v1;
	for (size_t i = 0; i < 500000; ++i)
		ASSERT_NO_THROW(v1.PushBack((int)i));
}

TEST(vector, pop_back_test) {
	Vector v1;
	for (size_t i = 0; i < 500000; ++i)
		v1.PushBack((int)i);	
	for (size_t i = 0; i < 500000; ++i)
		ASSERT_NO_THROW(v1.PopBack());
}

TEST(vector, clear_test) {
	Vector v1;
	for (size_t i = 0; i < 500000; ++i)
		v1.PushBack((int)i);	

	ASSERT_NO_THROW(v1.Clear());
}