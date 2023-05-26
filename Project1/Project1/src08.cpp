#include<iostream>
using namespace std;


// 소켓 인터페이스 -> 인스턴스를 만들지 않을것임. 즉, 접속부(인터페이스 선언)만 있지 구현부 X ,
class Socket
{
public:
	virtual void plugIn() = 0; // pure virtual function(순수 가상함수)
	virtual void unplug() = 0; // 구현부가 없기 때문에 인스턴스를 못만듦
};

class Samsang : public Socket // 순수가상함수의 구현부를 만들어준다.
{
public:
	void plugIn() override;
	void unplug() override;
private:
	void enable330V();
	void disable330V();
};

void Samsang::plugIn()
{
	enable330V();
}
void Samsang::unplug()
{
	disable330V();
}
void Samsang::enable330V()
{
	cout << "330 V 연결" << endl;
}
void Samsang::disable330V()
{
	cout << "330V 해제" << endl;
}



class SunPower : public Socket
{
public:
	void plugIn() override
	{
		cout << "태양열 연결" << endl;
	}
	void unplug() override
	{
		cout << "태양열 해제" << endl;
	}
};


void client(Socket* sock)
{
	// 다형적으로 동작 
	sock->plugIn();
	sock->unplug();
}

int main()
{
	Socket* sock = new Samsang();
	client(sock);
	delete sock;
	sock = nullptr;

	sock = new SunPower();
	client(sock);
	delete sock;
	return 0;
}