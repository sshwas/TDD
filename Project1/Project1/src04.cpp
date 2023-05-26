#include <iostream>

using namespace std;

class Zergling
{
public:
	Zergling()
	{
		hp = 100, mana = 80;
	}

	void attack()
	{
		hp++;
		mana -= 10;
	}

	void move()
	{
		hp -= 10;
		mana += 5;
	}

	void status()
	{
		cout << hp << " " << mana << endl;
	}

private:
	int hp;
	int mana;
};


int main(void)
{
	Zergling* zergling1 = new Zergling();
	Zergling* zergling2 = new Zergling();

	zergling1->attack();
	zergling1->move();
	zergling1->move();
	zergling1->status();

	zergling2->status();

	return 0;
}