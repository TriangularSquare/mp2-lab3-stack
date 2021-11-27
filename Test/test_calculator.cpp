#include "gtest.h"
#include "..\Stack\TCalc.h"

TEST(TCalc, can_create_calculator) {
	ASSERT_NO_THROW(TCalc tc);
}

TEST(TCalc, can_check_brackets) {
	string expr = "(1 + 1)";
	TCalc tc(expr);

	ASSERT_NO_THROW(tc.CorrectBrackets());
}

TEST(TCalc, can_detect_correct_brackets) {
	string expr = "(1 + 1)";
	TCalc tc(expr);

	ASSERT_TRUE(tc.CorrectBrackets());
}

TEST(TCalc, can_detect_incorrect_brackets) {
	string expr = "1 + 1)(";
	TCalc tc(expr);

	ASSERT_FALSE(tc.CorrectBrackets());
}

TEST(TCalc, can_convert_to_postfix) {
	string expr = "6 + 3.3^(4 / 2) - 4";
	TCalc tc(expr);

	ASSERT_NO_THROW(tc.ToPostfix());
	EXPECT_EQ(tc.GetPostfix(), "6 3.3 4 2 / ^ + 4 -");
}

TEST(TCalc, can_add) {
	string expr = "5 + 4";
	TCalc tc(expr);

	tc.ToPostfix();

	EXPECT_EQ(tc.Calc(), 9);
	EXPECT_EQ(tc.NewCalc(), 9);
}

TEST(TCalc, can_substract) {
	string expr = "5 - 4";
	TCalc tc(expr);

	tc.ToPostfix();

	EXPECT_EQ(tc.Calc(), 1);
	EXPECT_EQ(tc.NewCalc(), 1);
}

TEST(TCalc, can_multiply) {
	string expr = "5 * 4";
	TCalc tc(expr);

	tc.ToPostfix();

	EXPECT_EQ(tc.Calc(), 20);
	EXPECT_EQ(tc.NewCalc(), 20);
}

TEST(TCalc, can_divide) {
	string expr = "5 / 4";
	TCalc tc(expr);

	tc.ToPostfix();

	EXPECT_EQ(tc.Calc(), 1.25);
	EXPECT_EQ(tc.NewCalc(), 1.25);
}

TEST(TCalc, can_raise_to_the_power) {
	string expr = "5 ^ 4";
	TCalc tc(expr);

	tc.ToPostfix();

	EXPECT_EQ(tc.Calc(), 625);
	EXPECT_EQ(tc.NewCalc(), 625);
}

TEST(TCalc, can_calculate_complex_expression) {
	string expr = "((4 + 2) / (6 - 7 / 1) + 2 - 4 ^ (5 - 2))";
	TCalc tc(expr);

	tc.ToPostfix();

	EXPECT_EQ(tc.Calc(), -68);
	EXPECT_EQ(tc.NewCalc(), -68);
}