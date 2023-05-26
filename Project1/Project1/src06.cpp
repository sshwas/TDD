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
		cout << "입력 코인은 5 초과 할수 없습니다" << endl;
		return;
	}
	if (totalCoin + coin > 10)
	{
		cout << "total 은 10을 초과 할 수 없습니다" << endl;
		return;
	}

	totalCoin += coin;
}

void GameMachine::playGame()
{
	if (totalCoin <= 0)
	{
		cout << "돈을 넣어주세요" << endl;
		return;
	}
	totalCoin--;
	cout << "게임을 시작하지" << endl;
	cout << "게임을 종료하지" << endl;
}


// 변경 불가다 한정 , 어디에 const 가 붙는가

int const INF = 1e9;  // 상수
const int INF_ = 1e9; //
INF = 180;  // 안됩니다.

int a = 10;
int b = 100;
int* const ptr = &a; // 주소값 변경 X
ptr = &b;

int const* pptr = &b;
*pptr = 100; // 역참조 값 변경 X