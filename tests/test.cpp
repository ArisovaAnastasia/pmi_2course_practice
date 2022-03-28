#include "..\gtest\gtest.h"
#include <string>
#include <vector>

#include "vector.h"

TEST(vector, can_create_vector_withous_points) {
	ASSERT_NO_THROW(Vector a);
}

TEST(vector, can_create_vector_with_positive_length) {
	ASSERT_NO_THROW(Vector a(10));
}

TEST(vector, can_create_vector_with_initializer_list) {
	ASSERT_NO_THROW(Vector a = { 2 });
}

TEST(vector, can_create_vector_with_copy_constructor) {
	Vector a { 2,3,4,5,6 };
	ASSERT_NO_THROW(Vector b(a));

	Vector b(a);
	EXPECT_EQ(a, b);
}

TEST(vector, copy_assignment_is_useful) {
	Vector a{ 2,3,4,5,6 };
	Vector b(10);
	
	ASSERT_NO_THROW(b = a);
	EXPECT_EQ(a, b);
}

TEST(vector, index_operation_is_correct) {
	Vector a{ 2,3,4,5,6 };

	ASSERT_NO_THROW(a[3]);
	EXPECT_EQ(a[3], 5);
}


TEST(vector, const_index_operation_is_correct) {
	const Vector a{ 2,3,4,5,6 };

	ASSERT_NO_THROW(a[3]);
	EXPECT_EQ(a[3], 5);
}

TEST(vector, can_get_size) {
	Vector a{ 2,3,4,5,6 };

	ASSERT_NO_THROW(a.Size());
	EXPECT_EQ(a.Size(), 5);
}

TEST(vector, can_get_capacity_) {
	Vector a{ 2,3,4,5,6 };

	ASSERT_NO_THROW(a.Capacity());
	EXPECT_EQ(a.Capacity(), 10);
}

TEST(vector, can_push_back) {
	Vector a{ 2,3,4,5,6 };

	ASSERT_NO_THROW(a.PushBack(100));
	EXPECT_EQ(a.Size(), 6);
	ASSERT_EQ(a[a.Size() - 1], 100);
}

TEST(vector, can_pop_back) {
	Vector a{ 2,3,4,5,6 };

	ASSERT_NO_THROW(a.PopBack());
	EXPECT_EQ(a.Size(), 4);
	ASSERT_EQ(a[a.Size() - 1], 5);
}

TEST(vector, can_clear) {
	Vector a{ 2,3,4,5,6 };

	ASSERT_NO_THROW(a.Clear());
	EXPECT_EQ(a.Size(), 0);
}

TEST(vector, can_swap) {
	Vector a{ 2,3,4,5,6 };
	Vector b{ 10,100,20 };

	ASSERT_NO_THROW(Swap(a,b));
}

TEST(vector, can_resrve) {
	Vector a{ 2,3,4,5,6,1000, 40 };

	ASSERT_NO_THROW(a.Reserve(20));
	EXPECT_EQ(20, a.Capacity());
	EXPECT_EQ(1000, a[5]);
}
