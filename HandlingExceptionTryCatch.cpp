#include<iostream>

int main(void)
{
	Here:
	int num1, num2;
	std::cout << "두 개의 숫자 입력: ";
	std::cin >> num1 >> num2;
	try
	{
		if (num2 == 0)
			throw num2;
		std::cout << "나눗셈의 몫: " << num1 / num2 << std::endl;
		std::cout << "나눗셈의 나머지: " << num1 % num2 << std::endl;
	}
	catch(int expn)
	{
		std::cout << "제 수는 " << expn << "이 될수 없습니다." << std::endl;
		goto Here;
	}
	std::cout << "end of main" << std::endl;
	return 0;
}