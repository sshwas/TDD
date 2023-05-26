#include<iostream>
using namespace std;


// ���� �������̽� -> �ν��Ͻ��� ������ ��������. ��, ���Ӻ�(�������̽� ����)�� ���� ������ X ,
class Socket
{
public:
	virtual void plugIn() = 0; // pure virtual function(���� �����Լ�)
	virtual void unplug() = 0; // �����ΰ� ���� ������ �ν��Ͻ��� ������
};

class Samsang : public Socket // ���������Լ��� �����θ� ������ش�.
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
	cout << "330 V ����" << endl;
}
void Samsang::disable330V()
{
	cout << "330V ����" << endl;
}



class SunPower : public Socket
{
public:
	void plugIn() override
	{
		cout << "�¾翭 ����" << endl;
	}
	void unplug() override
	{
		cout << "�¾翭 ����" << endl;
	}
};


void client(Socket* sock)
{
	// ���������� ���� 
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