#include "..\Stack\TStack.h"
#include "gtest.h"

TEST(TStack, can_create_stack_with_positive_size) {
	ASSERT_NO_THROW(TStack<int>ts(10));
}

TEST(TStack, cant_create_stack_with_negative_size) {
	ASSERT_ANY_THROW(TStack<int>ts(-10));
}

TEST(TStack, cant_create_stack_with_zero_size) {
	ASSERT_ANY_THROW(TStack<int>ts(0));
}

TEST(TStack, can_create_copied_stack) {
	TStack<int> ts(10);
	ASSERT_NO_THROW(TStack<int> copy = ts);
}

TEST(TStack, copied_stack_is_equal_to_source_one) {

}

TEST(TStack, copied_stack_has_its_own_memory) {

}

TEST(TStack, can_assign_stacks_of_equal_size) {

}

TEST(TStack, can_assign_stacks_of_different_size) {

}

TEST(TStack, can_assign_stack_to_itself) {

}

TEST(TStack, equal_stacks_comparison_returns_true) {

}

TEST(TStack, unequal_stacks_comparison_returns_false) {

}

TEST(TStack, stacks_with_different_sizes_are_not_equal) {

}

TEST(TStack, empty_stack_isempty_returns_true) {

}

TEST(TStack, not_empty_stack_isempty_returns_false) {

}

TEST(TStack, full_stack_isfull_returns_true) {

}

TEST(TStack, not_full_stack_isfull_returns_false) {

}

TEST(TStack, can_push_and_pop) {

}

TEST(TStack, cant_push_when_stack_is_full) {

}

TEST(TStack, cant_pop_when_stack_is_empty) {

}

TEST(TStack, can_give_top) {

}

TEST(TStack, cant_give_top_when_stack_is_empty) {

}

TEST(TStack, can_clear_stack) {

}
