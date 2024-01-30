#include<iostream>

class AAA
{
public:
	void ShowYou() { std::cout << "AAA exception!" << std::endl; }
};

class BBB : public AAA
{
public:
	void ShowYou() { std::cout << "BBB exception!" << std::endl; }
};

class CCC : public BBB
{
public:
	void ShowYou() { std::cout << "CCC exceoption!" << std::endl; }
};

void ExceptionGenerator(int expn)
{
	if (expn == 1)
		throw AAA();
	else if (expn == 2)
		throw BBB();
	else
		throw CCC();
}

int main(void)
{
	try
	{
		ExceptionGenerator(3);
		ExceptionGenerator(2);
		ExceptionGenerator(1);
	}
	catch(CCC& expn)
	{
		std::cout << "catch(AAA& expn)" << std::endl;
		expn.ShowYou();
	}
	catch (BBB& expn)
	{
		std::cout << "catch(BBB& expn)" << std::endl;
		expn.ShowYou();
	}
	catch (AAA& expn)
	{
		std::cout << "catch(CCC& expn)" << std::endl;
		expn.ShowYou();
	}
}
