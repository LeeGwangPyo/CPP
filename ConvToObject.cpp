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
	void ShowNumber() { std::cout << num << std::endl; }
};

int main(void)
{
	Number num;
	num = 30;
	num.ShowNumber();
	return 0;
}