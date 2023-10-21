#include "Calculator.h"
int main(void)
{
	Calculator Cal;
	Cal.Init();
	std::cout << "3.2 + 2.4 = " << Cal.Add(3.2, 2.4) << std::endl;
	std::cout << "2.5 / 1.7 = " << Cal.Div(2.5, 1.7) << std::endl;
	std::cout << "2.2 - 1.5 = " << Cal.Min(2.2, 1.5) << std::endl;
	std::cout << "4.9 / 1.2 = " << Cal.Div(4.9, 1.2) << std::endl;
	Cal.ShowOpCout();
	return 0;
}