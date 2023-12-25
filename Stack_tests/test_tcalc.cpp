//#include "tmatrix.h"

#include "gtest.h"
#include "../Stack_lab/TCalculator.h"

TEST(TCalculator, can_create_calculator)
{
  ASSERT_NO_THROW(TCalculator m);
}

TEST(TCalculator, Addition) {
	TCalculator calc("3+4");
	ASSERT_NO_THROW(calc.Calc(), 7.0);
}

TEST(TCalculator, Substruction) {
	TCalculator calc("4-3");
	ASSERT_NO_THROW(calc.Calc(), 1.0);
}

TEST(TCalculator, Multiplication) {
	TCalculator calc("3*4");
	ASSERT_NO_THROW(calc.Calc(), 12.0);
}

TEST(TCalculator, Division) {
	TCalculator calc("12/4");
	ASSERT_NO_THROW(calc.Calc(), 3.0);
}

TEST(TCalculator, DivisionByZero) {
	TCalculator calc("4/0");
	ASSERT_NO_THROW(calc.Calc(), "error");
}

TEST(TCalculator, SinFunc) {
	TCalculator calc("sin(0)");
	ASSERT_NO_THROW(calc.Calc(), 1.0);
}

TEST(TCalculator, CosFunc) {
	TCalculator calc("cos(0)");
	ASSERT_NO_THROW(calc.Calc(), 1.0);
}

TEST(TCalculator, MixedOperations) {
	TCalculator calc("2+3*4-6/2");
	ASSERT_NO_THROW(calc.Calc(), 14.0);
}
