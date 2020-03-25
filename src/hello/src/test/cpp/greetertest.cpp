#include <gtest/gtest.h>
#include "hello.h"

TEST(GreeterTest, Sanitizer) {
    EXPECT_NO_THROW(Greeter().hello());
}