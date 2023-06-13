#include <iostream>
#include <gtest/gtest.h>

#include "scientific.h"

using namespace std;

TEST(scisuite, sciname)
{

}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}