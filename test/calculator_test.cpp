#include <iostream>
#include <gtest/gtest.h>

#include "calculator.h"

using namespace std;

TEST(calcsuite, calcname)
{

}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}