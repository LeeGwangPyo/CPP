#include<iostream>

class Base
{
public:
	Base() { std::cout << "Base Constructor" << std::endl; }
	void SimpleFunc() { std::cout << "BaseOne" << std::endl; }
};

class MiddleDerivedOne : virtual public Base
{
public:
	MiddleDerivedOne() :Base()
	{
		std::cout << "MiddleDerivedOne Constructor" << std::endl;
	}
	void MiddleFuncOne()
	{
		SimpleFunc();
		std::cout << "MiddleDerivedOne" << std::endl;
	}
};

class MiddleDerivedTwo :virtual public Base
{
public:
	MiddleDerivedTwo() :Base()
	{
		std::cout << "MiddleDerivedTwo Constrcutor" << std::endl;
	}
	void MiddleFuncTwo()
	{
		SimpleFunc();
		std::cout << "MiddleDerivedTwo" << std::endl;
	}
};

class LastDerived :public MiddleDerivedOne, public MiddleDerivedTwo
{
public:
	LastDerived() :MiddleDerivedOne(), MiddleDerivedTwo()
	{
		std::cout << "LastDerived Constructor" << std::endl;
	}
	void ComplexFunc()
	{
		MiddleDerivedOne();
		MiddleDerivedTwo();
	}
};

int main(void)
{
	std::cout << "按眉积己 傈 ....." << std::endl;
	LastDerived ldr;
	std::cout << "按眉积己 饶 ....." << std::endl;
	ldr.ComplexFunc();
	return 0;
}