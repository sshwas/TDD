#include<iostream>
#include <vector>
using namespace std;

class GameMachine
{
public:
	void inputCoin(int coin);
	void playGame();

private:
	int totalCoin;
};

void GameMachine::inputCoin(int coin)
{
	if (coin > 5)
	{
		cout << "�Է� ������ 5 �ʰ� �Ҽ� �����ϴ�" << endl;
		return;
	}
	if (totalCoin + coin > 10)
	{
		cout << "total �� 10�� �ʰ� �� �� �����ϴ�" << endl;
		return;
	}

	totalCoin += coin;
}

void GameMachine::playGame()
{
	if (totalCoin <= 0)
	{
		cout << "���� �־��ּ���" << endl;
		return;
	}
	totalCoin--;
	cout << "������ ��������" << endl;
	cout << "������ ��������" << endl;
}


// ���� �Ұ��� ���� , ��� const �� �ٴ°�

int const INF = 1e9;  // ���
const int INF_ = 1e9; //
INF = 180;  // �ȵ˴ϴ�.

int a = 10;
int b = 100;
int* const ptr = &a; // �ּҰ� ���� X
ptr = &b;

int const* pptr = &b;
*pptr = 100; // ������ �� ���� X