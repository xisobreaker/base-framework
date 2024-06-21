#include <glog/logging.h>
#include <gtest/gtest.h>

TEST(TEST_CONFIGURE, CONFIG_READ)
{
    EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}