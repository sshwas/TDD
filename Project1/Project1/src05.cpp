#include <iostream>

using namespace std;

// �����ڵ� 
class Calculator
{
public:
	void plus(int a, int b)
	{
		a++;
		a--;
		result = a + b;
	}

	void divide(int a, int b)
	{
		if (b == 0)
		{
			std::cout << "�ι�° ���ڴ� 0 �� �� �� �����ϴ�" << std::endl;
			return;
		}
		result = a / b;
	}

	void printResult()
	{
		std::cout << result << std::endl;
	}

	int getResult() const
	{
		// getter ������ ������ �����۾��� ����.
		return result;
	}

private:
	int result;

};

int main()
{
	// Ŭ���̾�Ʈ
	Calculator* cal = new Calculator();
	cal->plus(1, 3);
	cal->printResult();

	cal->divide(3, 0);

	int ret = cal->getResult();
	return 0;
}
