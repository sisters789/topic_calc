#include <iostream>
#include <gtest/gtest.h>
#include <unistd.h>
#include <cstring>
#include "calculator.h"

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
    std::string output = ::testing::internal::GetCapturedStdout();
    std::string expected = "The mem is 0";

    EXPECT_EQ(output, expected);
}

TEST_F(CalculatorTest, SetMemTest)
{
    ::testing::internal::CaptureStdout();
    calc.printMem();
    std::string output = ::testing::internal::GetCapturedStdout();
    std::string expected = "The mem is 0";

    EXPECT_EQ(output, expected);
}

TEST_F(CalculatorTest, DividedByZeroTest)
{
    calc.setA("1");
    calc.setB("0");

    ASSERT_ANY_THROW(calc.divide());
}

TEST_F(CalculatorTest, NegativeSqrtTest)
{
    calc.setA("-4");

    ASSERT_ANY_THROW(calc.sqrt());
}

TEST_F(CalculatorTest, writefile1)
{
    std::string test_suite_name = ::testing::UnitTest::GetInstance()->current_test_info()->test_suite_name();
    std::string test_name = ::testing::UnitTest::GetInstance()->current_test_info()->name();
    std::string filename = test_suite_name + "." + test_name + ".txt";
    std::string cmd = "ls | grep " + filename;

    EXPECT_TRUE(calc.writeResultToFile(filename, 1));

    ::testing::internal::CaptureStdout();
    system(cmd.c_str());
    std::string cmd_output = ::testing::internal::GetCapturedStdout();

    EXPECT_TRUE(cmd_output.find(filename) != std::string::npos);
}

TEST_F(CalculatorTest, writefile2)
{
    std::string test_suite_name = ::testing::UnitTest::GetInstance()->current_test_info()->test_suite_name();
    std::string test_name = ::testing::UnitTest::GetInstance()->current_test_info()->name();
    std::string filename = test_suite_name + "." + test_name + ".txt";
    EXPECT_TRUE(calc.writeResultToFile(filename, 2));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}