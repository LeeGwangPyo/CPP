#include<iostream>

int main(void)
{
	Here:
	int num1, num2;
	std::cout << "�� ���� ���� �Է�: ";
	std::cin >> num1 >> num2;

	if (num2 == 0)
	{
		std::cout << "�� ���� 0�� �ɼ� �����ϴ�" << std::endl;
		goto Here;
	}
	std::cout << "�������� ��: " << num1 / num2 << std::endl;
	std::cout << "�������� ������: " << num1 % num2 << std::endl;
	return 0;
}