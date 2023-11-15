#include<iostream>

class Number
{
private:
	int num;
public:
	Number(int n) :num(n) {}
	void ShowData() { std::cout << num << std::endl; }

	Number* operator->()
	{
		return this;
	}
	Number& operator*()
	{
		return *this;
	}
};

int main(void)
{
	Number num(20);
	num.ShowData();

	(*num) = 30;
	num->ShowData();
	(*num).ShowData();
	return 0;
}