#include "pch.h"
#include "../UnitTestProject01/src01.h"


TEST(TestCaseName, TC01) {
  EXPECT_EQ(1, Cal::sum(1,2));
  EXPECT_TRUE(true);
}