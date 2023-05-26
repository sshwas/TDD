#include "pch.h"
#include "../UnitTestProject01/src01.h"

TEST(TestCaseName, TestName) {
	Cal* c = new Cal();
	EXPECT_EQ(3, c->sum(1,2));
	EXPECT_TRUE(true);
}
