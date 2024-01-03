#include<iostream>

int main(void)
{
	Here:
	int num1, num2;
	std::cout << "µÎ °³ÀÇ ¼ıÀÚ ÀÔ·Â: ";
	std::cin >> num1 >> num2;

	if (num2 == 0)
	{
		std::cout << "Á¦ ¼ö´Â 0ÀÌ µÉ¼ö ¾ø½À´Ï´Ù" << std::endl;
		goto Here;
	}
	std::cout << "³ª´°¼ÀÀÇ ¸ò: " << num1 / num2 << std::endl;
	std::cout << "³ª´°¼ÀÀÇ ³ª¸ÓÁö: " << num1 % num2 << std::endl;
	return 0;
}