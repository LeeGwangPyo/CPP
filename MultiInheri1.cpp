#include<iostream>

class BaseOne
{
public:
	void SimpleFuncOne() { std::cout << "BaseOne" << std::endl; }
};

class BaseTwo
{
public:
	void SimpleFuncTwo() { std::cout << "BaseTwo" << std::endl; }
};

class MultiDerived :public BaseOne, public BaseTwo
{
public:
	void ComplexFunc()
	{
		SimpleFuncOne();
		SimpleFuncTwo();
	}
};

int main(void)
{
	MultiDerived mrd;
	mrd.ComplexFunc();
	return 0;
}