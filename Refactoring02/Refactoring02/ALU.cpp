#pragma once

#include <string>
#include "Result.cpp"

class ALU
{
public:
	void enableSignal(Result* result) {
		if (InvalidCheckAndSetResult(result)) return;
		calculateAndSetResult(result);
	}

	bool InvalidCheckAndSetResult(Result* r) {
		if (isInvalidOperand(operand1)) {
			setFailResult(r, FAIL_RESULT_VALUE, FAIL_STATUS_OPERAND1);
			return true;
		}

		if (isInvalidOperand(operand2)) {
			setFailResult(r, FAIL_RESULT_VALUE, FAIL_STATUS_OPERAND2);
			return true;
		}

		if (isInvalidOPCODE()) {
			setFailResult(r, FAIL_RESULT_VALUE, FAIL_STATUS_OPCODE);
			return true;
		}
		return false;
	}

	bool isInvalidOperand(int operand) {
		return operand == OPERAND_INITIAL_VALUE;
	}

	void setFailResult(Result* result, int i, int i1) {
		result->setResult(i);
		result->setStatus(i1);
	}

	bool isInvalidOPCODE() {
		return OPCODE != "ADD" && OPCODE != "MUL" && OPCODE != "SUB";
	}

	void calculateAndSetResult(Result* result) {
		result->setResult(getResultAfterCalculate());
		result->setStatus(0);
	}

	int getResultAfterCalculate() {
		int result = 0;
		if (OPCODE == "ADD") {
			result = operand1 + operand2;
		}
		else if (OPCODE == "MUL") {
			result = operand1 * operand2;
		}
		else if (OPCODE == "SUB") {
			result = operand1 - operand2;
		}
		return result;
	}

	void setOperand1(int operand1) {
		this->operand1 = operand1;
	}

	void setOperand2(int operand2) {
		this->operand2 = operand2;
	}

	void setOPCODE(std::string OPCODE) {
		this->OPCODE = OPCODE;
	}

private:
	const int FAIL_RESULT_VALUE = 65535;
	const int FAIL_STATUS_OPERAND1 = 1;
	const int FAIL_STATUS_OPERAND2 = 2;
	const int FAIL_STATUS_OPCODE = 3;
	const int OPERAND_INITIAL_VALUE = -1;

	int operand1 = OPERAND_INITIAL_VALUE;
	int operand2 = OPERAND_INITIAL_VALUE;
	std::string OPCODE;
};