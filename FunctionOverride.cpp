#include<iostream>

class First
{
public:
	void MyFunc()
	{
		std::cout << "First Function" << std::endl;
	}
};

class Second :public First
{
public:
	void MyFunc()
	{
		std::cout << "Second Function" << std::endl;
	}
};

class Third :public Second
{
public:
	void MyFunc()
	{
		std::cout << "Third Function" << std::endl;
	}
};

int main(void)
{
	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = sptr;

	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();
	delete tptr;
	return 0;
}