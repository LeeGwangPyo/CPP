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
	virtual int GetPay()const = 0;
	virtual void ShowSalaryInfo()const = 0;
};

class Permanentworker :public Employee
{
private:
	int salary;
public:
	Permanentworker(const char* name, int money) :Employee(name), salary(money)
	{
	}
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

class TemporaryWorker : public Employee
{
private:
	int workTime;
	int payPerHour;
public:
	TemporaryWorker(const char* name, int pay) :Employee(name), workTime(0), payPerHour(pay)
	{
	}
	void AddWorkTime(int time)
	{
		workTime += time;
	}
	int GetPay()const
	{
		return workTime * payPerHour;
	}
	void ShowSalaryInfo()const
	{
		ShowYourName();
		std::cout << "Salary: " << GetPay() << std::endl << std::endl;
	}
};

class SalesWorker :public Permanentworker
{
private:
	int salesResult;
	double bonusRatio;
public:
	SalesWorker(const char* name, int money, double ratio) :Permanentworker(name, money), salesResult(0), bonusRatio(ratio)
	{
	}
	void AddSalesResult(int value)
	{
		salesResult += value;
	}
	int GetPay()const
	{
		return Permanentworker::GetPay() + (int)(salesResult * bonusRatio);
		//Permanentworker의 Getpay 함수호출	
	}
	void ShowSalaryInfo()const
	{
		ShowYourName();
		std::cout << "Salary: " << GetPay() << std::endl << std::endl;
	}
};

class EmployeeHandler
{
private:
	Employee* emplist[50];
	int empNum;
public:
	EmployeeHandler() :empNum(0)
	{
	}
	void AddEmployee(Employee* emp)
	{
		emplist[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const
	{
		for (int i = 0; i < empNum; i++)
			emplist[i]->ShowSalaryInfo();
	}
	void ShowTotalSalary()const
	{
		int sum = 0;

		for (int i = 0; i < empNum; i++)
			sum += emplist[i]->GetPay();

		std::cout << "salary sum: " << sum << std::endl;
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete emplist[i];
	}
};

enum RISK_LEVEL { RISK_A = 30, RISK_B = 20, RISK_C = 10 };

class ForeignSalesWorker:public SalesWorker
{
private:
	int const risklevel;
	int salesResult;
	double Ratio;
public:
	ForeignSalesWorker(const char* name, int money, int ratio, int level) :SalesWorker(name, money, ratio), Ratio(ratio), risklevel(level)
	{ }
	void AddSalesResult(int value)
	{
		salesResult += value;
	}
	int GetPay()const
	{
		return Permanentworker::GetPay() + (int)(salesResult * Ratio);
		//Permanentworker의 Getpay 함수호출	
	}
	int GetRiskPay()const
	{
		return (int)(GetPay() * (risklevel / 100.0));
	}
	int Sum()const
	{
		return GetPay() + GetRiskPay();
	}
	void ShowSalaryInfo()const
	{
		ShowYourName();
		std::cout << "salary: " << GetPay() << std::endl;
		std::cout << "risk pay: " << GetRiskPay() << std::endl;
		std::cout << "sum: " << Sum() << std::endl << std::endl;
	}
};
int main(void)
{
	//직원관리를 목적으로 설계괸 컨트롤 클래스의 객체생성
	EmployeeHandler handler;
	/*
	//직원 등록
	handler.AddEmployee(new Permanentworker("Kim", 1000));
	handler.AddEmployee(new Permanentworker("Lee", 1500));
	handler.AddEmployee(new Permanentworker("Jun", 2000));

	//임시직 등록
	TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);

	//영업직 등록
	SalesWorker* seller = new SalesWorker("Jung", 1000, 0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);
	*/

	ForeignSalesWorker* fseller1 = new ForeignSalesWorker("hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller1);

	ForeignSalesWorker* fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);

	ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3);

	//이번 달에 지불해야 할 급여의 정보
	handler.ShowAllSalaryInfo();

	//이번 달에 지불해야할 급여의 총 합
	//handler.ShowTotalSalary();
	return 0;
}