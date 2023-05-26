#include <iostream>

using namespace std;

// 서버코드 
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
			std::cout << "두번째 인자는 0 이 될 수 없습니다" << std::endl;
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
		// getter 에서는 데이터 변경작업이 없다.
		return result;
	}

private:
	int result;

};

int main()
{
	// 클라이언트
	Calculator* cal = new Calculator();
	cal->plus(1, 3);
	cal->printResult();

	cal->divide(3, 0);

	int ret = cal->getResult();
	return 0;
}
