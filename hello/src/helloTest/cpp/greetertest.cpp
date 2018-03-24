#include <gtest/gtest.h>
#include "hello.h"

TEST(GreeterTest, CheckCapitalisation) {
    EXPECT_NO_THROW(Greeter().hello());
}