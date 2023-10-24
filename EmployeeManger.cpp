#include<iostream>
#include<cstring>

class Employee
{
private:
	char name[100];
public:
	Employee(const char* name)
	{
		strcpy(this->name, name);
	}
	void ShowYourName() const
	{
		std::cout << "name: " << name << std::endl;
	}
};

class Permanentworker :public Employee
{
private:
	int salary;
public:
	Permanentworker(const char* name, int money) :Employee(name), salary(money)
	{ }
	int GetPay()const
	{
		return salary;
	}
	void ShowSalaryInfo()const
	{
		ShowYourName();
		std::cout << "salary: " << GetPay() << std::endl << std::endl;
	}
};

class EmployeeHandler
{
private:
	Employee* emplist[50];
	int empNum;
public:
	EmployeeHandler():empNum(0)
	{ }
	void AddEmployee(Employee* emp)
	{
		emplist[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const
	{
		/*
		for (int i = 0; i < empNum; i++)
			emplist[i]->ShowSalaryInfo();
		*/
	}
	void ShowTotalSalary()const
	{
		int sum = 0;
		/*
		for (int i = 0; i < empNum; i++)
			sum += emplist[i]->Getpay();
		*/
		std::cout << "salary sum: " << sum << std::endl;
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete emplist[i];
	}
};
int main(void)
{
	//���������� �������� ���豭 ��Ʈ�� Ŭ������ ��ü����
	EmployeeHandler handler;

	//���� ���
	handler.AddEmployee(new Permanentworker("Kim", 1000));
	handler.AddEmployee(new Permanentworker("Lee", 1500));
	handler.AddEmployee(new Permanentworker("Jun", 2000));

	//�̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowAllSalaryInfo();

	//�̹� �޿� �����ؾ��� �޿��� �� ��
	handler.ShowTotalSalary();
	return 0;
}