#include <gtest/gtest.h>
#include <FirstExcersice.hpp>

TEST(FirstExcersiceTest, CheckEquality) {
    EXPECT_EQ(
        FirstExcersice().doIt(),
        std::string("I am First Excersice"));
}