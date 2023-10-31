#include<iostream>
#include<cstring>

class Person
{
private:
	char* name;
	int age;
public:
	Person(const char* myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	void ShowPersonInfo()const
	{
		std::cout << "�̸�: " << name << std::endl;
		std::cout << "����: " << age << std::endl;
	}
	~Person()
	{
		delete[]name;
		std::cout << "Called destructor!" << std::endl;
	}

	Person& operator=(const Person& ref)
	{
		delete[]name;
		int len = strlen(ref.name) + 1;
		name = new char[len];
		strcpy(name, ref.name);
		age = ref.age;
		return *this;
	}
};

int main(void)
{
	Person man1("LeedongWoo", 29);
	Person man2("Yoon ji yul", 22);
	man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}