#include "pch.h"
#include "../Refactoring02/ALU.cpp";
#include "../Refactoring02/Result.cpp";


TEST(ALU, ADDTest)
{
	ALU alu;
	alu.setOperand1(10);
	alu.setOperand2(20);
	alu.setOPCODE("ADD");

	Result ret;
	alu.enableSignal(&ret);
	EXPECT_EQ(30, ret.getResult());
	EXPECT_EQ(0, ret.getStatus());

	alu.setOperand1(-1);
	alu.setOperand2(20);
	alu.enableSignal(&ret);
	EXPECT_EQ(0xFFFF, ret.getResult());
	EXPECT_EQ(1, ret.getStatus());

	alu.setOperand1(10);
	alu.setOperand2(-1);
	alu.enableSignal(&ret);
	EXPECT_EQ(0xFFFF, ret.getResult());
	EXPECT_EQ(2, ret.getStatus());
}

TEST(ALU, MULTest)
{
	ALU alu;
	alu.setOperand1(10);
	alu.setOperand2(20);
	alu.setOPCODE("MUL");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(200, ret.getResult());
	EXPECT_EQ(0, ret.getStatus());

	alu.setOperand1(-1);
	alu.setOperand2(20);
	alu.enableSignal(&ret);
	EXPECT_EQ(0xFFFF, ret.getResult());
	EXPECT_EQ(1, ret.getStatus());

	alu.setOperand1(10);
	alu.setOperand2(-1);
	alu.enableSignal(&ret);
	EXPECT_EQ(0xFFFF, ret.getResult());
	EXPECT_EQ(2, ret.getStatus());
}

TEST(ALU, SUBTest)
{
	ALU alu;
	alu.setOperand1(20);
	alu.setOperand2(10);
	alu.setOPCODE("SUB");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(10, ret.getResult());
	EXPECT_EQ(0, ret.getStatus());

	alu.setOperand1(-1);
	alu.setOperand2(10);
	alu.enableSignal(&ret);
	EXPECT_EQ(0xFFFF, ret.getResult());
	EXPECT_EQ(1, ret.getStatus());

	alu.setOperand1(20);
	alu.setOperand2(-1);
	alu.enableSignal(&ret);
	EXPECT_EQ(0xFFFF, ret.getResult());
	EXPECT_EQ(2, ret.getStatus());
}

TEST(ALU, DIVTest)
{
	ALU alu;
	alu.setOperand1(20);
	alu.setOperand2(10);
	alu.setOPCODE("DIV");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(0xFFFF, ret.getResult());
	EXPECT_EQ(3, ret.getStatus());
}