#include <string>
using namespace std;

class GreetInterface
{
public:
	virtual string Greet() = 0;
};

class GreetFormal : public GreetInterface
{
public:
	string Greet() override
	{
		return "Good evening, sir.";
	}
};

class GreetCasual : public GreetInterface
{
public:
	string Greet() override
	{
		return "Sup bro?";
	}
};

class GreetIntimate : public GreetInterface
{
public:
	string Greet() override
	{
		return "Hello Darling!";
	}
};

class GreetNormal : public GreetInterface
{
public:
	string Greet() override
	{
		return "Hello.";
	}
};


class Greeter
{
public:
	string Greet()
	{
		return gi->Greet();
	}

	void SetFormality(GreetInterface* gi)
	{
		this->gi = gi;
	}

private:
	GreetInterface* gi;
};