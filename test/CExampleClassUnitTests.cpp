#include <gtest/gtest.h>

#include <CExampleClass.hpp>

TEST(CApp, testMethodReturnsTen) {
    constexpr int expected = 10;
    EXPECT_EQ(expected, holoscratch::CExampleClass::testMethodReturnsTen());
}