#include<iostream>

class SortRule
{
public:
	virtual bool operator()(int num1, int num2) const = 0;
};

class AscentdingSort : public SortRule
{
public:
	bool operator()(int num1, int num2) const
	{
		if (num1 > num2)
			return true;
		else
			return false;
	}
};

class DescendingSort : public SortRule
{
public:
	bool operator()(int num1, int num2) const
	{
		if (num1 < num2)
			return true;
		else
			return false;
	}
};

class DataStorage
{
private:
	int* arr;
	int idx;
	const int MAX_LEN;
public:
	DataStorage(int arrlen) : idx(0), MAX_LEN(arrlen)
	{
		arr = new int[MAX_LEN];
	}
	void addData(int num)
	{
		if (MAX_LEN < idx)
		{
			std::cout << "더 이상 저장이 불가능합니다." << std::endl;
			return;
		}
		arr[idx++] = num;
	}
	void ShowAllData()
	{
		for (int i = 0; i < idx; i++)
			std::cout << arr[i] << ' ';
		std::cout << std::endl;
	}
	void SortData(const SortRule& functor)
	{
		for (int i = 0; i < (idx - 1); i++)
		{
			for (int j = 0; j < (idx - 1)-i; j++)
			{
				if (functor(arr[j], arr[j + 1]))
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
};

int main(void)
{
	DataStorage storage(5);
	storage.addData(40);
	storage.addData(30);
	storage.addData(50);
	storage.addData(20);
	storage.addData(10);

	storage.SortData(AscentdingSort());
	storage.ShowAllData();

	storage.SortData(DescendingSort());
	storage.ShowAllData();
	return 0;
}