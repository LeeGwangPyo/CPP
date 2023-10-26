#include<iostream>

class BaseOne
{
public:
	void SimpleFunc() { std::cout << "BaseOne" << std::endl; }
};

class BaseTwo
{
public:
	void SimpleFunc() { std::cout << "BaseTwo" << std::endl; }
};

class MultiDerived :public BaseOne, public BaseTwo
{
public:
	void ComplexFunc()
	{
		BaseOne::SimpleFunc();
		BaseTwo::SimpleFunc();
	}
};

int main(void)
{
	MultiDerived mdr;
	mdr.ComplexFunc();
	return 0;
}