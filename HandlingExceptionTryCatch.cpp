#include<iostream>

int main(void)
{
	Here:
	int num1, num2;
	std::cout << "�� ���� ���� �Է�: ";
	std::cin >> num1 >> num2;
	try
	{
		if (num2 == 0)
			throw num2;
		std::cout << "�������� ��: " << num1 / num2 << std::endl;
		std::cout << "�������� ������: " << num1 % num2 << std::endl;
	}
	catch(int expn)
	{
		std::cout << "�� ���� " << expn << "�� �ɼ� �����ϴ�." << std::endl;
		goto Here;
	}
	std::cout << "end of main" << std::endl;
	return 0;
}