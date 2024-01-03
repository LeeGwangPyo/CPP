#include<iostream>

void Divide(int num1, int num2)
{
	if (num2 == 0)
		throw num2;
	std::cout << "³ª´°¼ÀÀÇ ¸ò: " << num1 / num2 << std::endl;
	std::cout << "³ª´°¼ÀÀÇ ³ª¸ÓÁö: " << num1 % num2 << std::endl;
}

int main(void)
{
	Here:
	int num1, num2;
	std::cout << "µÎ °³ÀÇ ¼ýÀÚ ÀÔ·Â: ";
	std::cin >> num1 >> num2;

	try
	{
		Divide(num1, num2);
		std::cout << "³ª´°¼ÀÀ» ¸¶ÃÆ½À´Ï´Ù" << std::endl;
	}
	catch(int expn)
	{
		std::cout << "Á¦¼ö´Â " << expn << "ÀÌ µÉ ¼ö ¾ø½À´Ï´Ù." << std::endl;
		goto Here;
	}
	return 0;
}