#include "pch.h"
#include "../tests/vector.h"
#include <initializer_list>


TEST(Vector, can_create_empty_vector) {
	ASSERT_NO_THROW(Vector vec);
}

TEST(Vector, can_create_vector_using_parametric_constructor) {
	ASSERT_NO_THROW(Vector vec(7));
}

TEST(Vector, can_correct_create_vector_with_initList) {
	ASSERT_NO_THROW(Vector vec(std::initializer_list <int> {1, 4, 9, 16, 25}));
}

TEST(Vector, correct_copy_constructor) {
	Vector u{ 1,1,1,1 };
	ASSERT_NO_THROW(Vector v = u);
}

TEST(Vector, correct_assignment_and_indexing) {
	Vector u{ 1,2,3,4,5 };
	Vector v(5);
	v = u;

	// Поскольку мы не перегружаем по сути оператор ==,
	//		то проверка на EXPECT_EQ будет иной

	bool isCorrect = true;
	for (size_t i = 0; i < v.Size(); i++)
		if (u[i] != v[i]) {
			isCorrect = false;
			break;
		}
	EXPECT_EQ(isCorrect, true);
}

TEST(Vector, can_swap_vectors) {
	Vector u{ 1, 2, 3 };
	Vector uCopy(u);
	Vector v{ 23, 65, 213, 9, 23, 42 };
	Vector vCopy(v);
	u.Swap(v);

	bool isCorrect = true;
	for (size_t i = 0; i < v.Size(); i++)
		if (uCopy[i] != v[i]) {
			isCorrect = false;
			break;
		}
	EXPECT_EQ(isCorrect, true);
}

TEST(Vector, indexing_is_correct) {
	Vector vec{ 1, -1, 2, -2, 3, -3 };
	ASSERT_NO_THROW(vec[0]);
	EXPECT_EQ(vec[0], 1);
}

TEST(Vector, const_indexing_is_correct) {
	const Vector vec{ 1, -1, 2, -2, 3, -3 };
	ASSERT_NO_THROW(vec[0]);
	EXPECT_EQ(vec[0], 1);
}

TEST(Vector, can_get_size) {
	Vector v{ 1, 3, 5, 7, 9, 11, 13, 15 };
	Vector u;
	Vector w;
	w.PushBack(23);
	EXPECT_EQ(v.Size(), 8);
	EXPECT_EQ(u.Size(), 0);
	EXPECT_EQ(w.Size(), 1);
}

TEST(Vector, can_get_capacity) {
	Vector v{ 1, 3, 5, 7, 9, 11, 13, 15 };
	Vector u;
	Vector w;
	w.PushBack(23);
	EXPECT_EQ(v.Capacity(), 8);
	EXPECT_EQ(u.Capacity(), 0);
	EXPECT_EQ(w.Capacity(), 1);

	u.Reserve(325);
	EXPECT_EQ(u.Capacity(), 325);
}

TEST(Vector, can_push_and_pop_back) {
	Vector u{ 1, 2, 3, 4, 5 };
	Vector v;
	ASSERT_NO_THROW(u.PushBack(26.5));
	ASSERT_NO_THROW(v.PushBack(26.5));

	ASSERT_NO_THROW(u.PopBack());
	ASSERT_NO_THROW(v.PopBack());
}

TEST(Vector, correct_clear) {
	Vector u;
	for (int i = 0; i < 1000; i++) 
		u.PushBack(i * i);
	ASSERT_NO_THROW(u.Clear());
	EXPECT_EQ(u.Size(), 0);
	EXPECT_EQ(u.Capacity(), 1024);
}