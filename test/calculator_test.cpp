#include <iostream>
#include <gtest/gtest.h>
#include <sstream>

#include "calculator.h"

using namespace std;

class CalculatorTest : public ::testing::Test
{
    protected:
        Calculator calc;
};

TEST_F(CalculatorTest, InitClassTest)
{
    ASSERT_ANY_THROW(calc.parseInput("abc"));
}

TEST_F(CalculatorTest, NumberParseInputTest)
{
    EXPECT_EQ(calc.parseInput("-10"), -10);
    EXPECT_EQ(calc.parseInput("-10.1"), -10.1);
    EXPECT_EQ(calc.parseInput("0"), 0);
    EXPECT_EQ(calc.parseInput("10"), 10);
    EXPECT_EQ(calc.parseInput("10.1"), 10.1);
}

TEST_F(CalculatorTest, ValidStringParseInputTest)
{
    ASSERT_EQ(calc.parseInput("result"), 0);
    ASSERT_EQ(calc.parseInput("mem"), 0);
}

TEST_F(CalculatorTest, InvalidStringParseInputTest)
{
    ASSERT_ANY_THROW(calc.parseInput("abc"));
}

TEST_F(CalculatorTest, PrintMemTest)
{
    ::testing::internal::CaptureStdout();
    calc.printMem();
    string output = ::testing::internal::GetCapturedStdout();
    string expected = "The mem is 0";

    EXPECT_EQ(output, expected);
}

TEST_F(CalculatorTest, SetMemTest)
{
    ::testing::internal::CaptureStdout();
    calc.printMem();
    string output = ::testing::internal::GetCapturedStdout();
    string expected = "The mem is 0";

    EXPECT_EQ(output, expected);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}