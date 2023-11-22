#include<iostream>

class Number
{
private:
	int num;
public:
	Number(int n = 0) :num(n)
	{
		std::cout << "Number(int n=0)" << std::endl;
	}
	Number& operator=(const Number& ref)
	{
		std::cout << "operator=()" << std::endl;
		num = ref.num;
		return *this;
	}
	operator int()
	{
		return num;
	}
	void ShowNumber() { std::cout << num << std::endl; }
};

int main(void)
{
	Number num1;
	num1 = 30;
	Number num2 = num1 + 20;
	num2.ShowNumber();
	return 0;
}