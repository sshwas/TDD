#include "pch.h"
#include <stdio.h>
#include "../Refactoring03/cal.cpp"
#include "../Refactoring03/EvenOdd.cpp"

using namespace std;



class DanielFixture : public testing::Test
{
protected:
	void SetUp() override
	{
		printf("#Setup#\n");
	}
	void TearDown() override
	{
		printf("#teardown#\n");
	}

public:
	int chair = 0; // chair는 테스트 대상

	void push_chair()
	{
		printf("push_chair\n");
		chair++;
		EXPECT_EQ(1, chair);
		chair = 0;
	}
};

TEST_F(DanielFixture, TC01)
{
	push_chair();
	printf("TC01 end \n");
}

TEST_F(DanielFixture, TC02)
{
	push_chair();
	printf("TC02 end \n");
}


TEST(TestCaseName, TestName)
{
	Cal cal;

	printf("HQ1\n");

	EXPECT_EQ(3, cal.GetSum(1, 2));

	printf("HQ2\n");

	EXPECT_EQ(7, 1 + 1) << "2다";
}



class EvenOddFixture : public testing::Test
{
public:
	EvenOdd app;
};

TEST_F(EvenOddFixture, EvenOdd01)
{
	vector<int> input = { 1,4,5,0 };
	vector<char> expect = { 'X','O','X','O' };

	EXPECT_EQ(expect, app.TranslateEvenOdd(input));
}

TEST_F(EvenOddFixture, EvenOdd02)
{
	vector<int> input = { 1,2,3,1 };
	vector<char> expect = { 'X','O','X','X' };

	EXPECT_EQ(expect, app.TranslateEvenOdd(input));
}


class GlobalEnv : public testing::Environment
{
public:
	void SetUp()
	{
		std::cout << "TEST READY!!\n";
	}
	void TearDown()
	{
		std::cout << "CLEAN UP!!\n";
	}
};

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	testing::AddGlobalTestEnvironment(new GlobalEnv);
	return RUN_ALL_TESTS();
}