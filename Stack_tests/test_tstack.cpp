//#include "tmatrix.h"

#include "gtest.h"
#include "../Stack_lab/Tstack.h"

TEST(TStack, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> m(4));
}

TEST(TStack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> m(-4));
}

TEST(TStack, can_create_copied_stack)
{
	TStack<int> m(4);

	ASSERT_NO_THROW(TStack<int> m1(m));
}

TEST(TStack, can_assign_stacks_of_equal_size)
{
	TStack<int> m(5), m1(5);
	ASSERT_NO_THROW(m = m1);
}

TEST(TStack, can_assign_stacks_of_different_size)
{
	TStack<int> m(5), m1(6);
	ASSERT_NO_THROW(m = m1);
}

TEST(TStack, compare_equal_stacks_return_true)
{
	TStack<int> m(5), m1(5);
	ASSERT_NO_THROW(m = m1);
}

TEST(TStack, compare_stacks_with_itself_return_true)
{
	TStack<int> m1(2), m2(2);
	EXPECT_TRUE(m1 == m2);
}

TEST(TStack, matrices_with_different_size_are_not_equal)
{
	TStack<int> m1(2), m2(3);
	EXPECT_FALSE(m1 == m2);
}