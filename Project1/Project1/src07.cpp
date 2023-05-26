#include<iostream>
using namespace std;

class Phone
{
public:
	virtual void call();
};

void Phone::call()
{
	cout << "calling..." << endl;
}

class SmartPhone : public Phone
{
public:
	virtual void call() override;
	void internet();
};

void SmartPhone::call()
{
	cout << "smart calling..." << endl;
}

void SmartPhone::internet()
{
	cout << "connecting..." << endl;
}


void usePhone(Phone* p)
{
	p->call();
}

int main()
{
	Phone* p = new Phone();

	usePhone(p);

	p = new SmartPhone();

	usePhone(p);

	delete p;



	return 0;
}