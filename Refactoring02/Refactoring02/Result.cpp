#pragma once

class Result
{
    int status = -1;
    int result = 65535;

    //status -1 : ��� �ȳ���
    //status 0 : ����
    //status 1 : Operand1�� �߸���
    //status 2 : Operand2�� �߸���
    //status 3 : OPCODE�� �߸��Ǿ���

    //result 65535 : ��� ����

public:
    void setStatus(int status) {
        this->status = status;
    }

    void setResult(int result) {
        this->result = result;
    }

    int getStatus() {
        return status;
    }

    int getResult() {
        return result;
    }
};