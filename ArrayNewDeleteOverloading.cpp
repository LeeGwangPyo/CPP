#include<iostream>

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y)
	{ }
	friend std::ostream& operator<<(std::ostream& os, const Point& pos);
	void* operator new(size_t size)
	{
		std::cout << "operator new : " << size << std::endl;
		void* adr = new char[size];
		return adr;
	}
	void* operator new [](size_t size)
	{
		std::cout << "operator new [] : " << size << std::endl;
		void* adr = new char[size];
		return adr;
	}
	void operator delete(void* adr)
	{
		std::cout << "operator delete ()" << std::endl;
		delete[]adr;
	}
	void operator delete[](void* adr)
	{
		std::cout << "operator delete[] ()" << std::endl;
		delete[]adr;
	}
};

std::ostream& operator<<(std::ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << std::endl;
	return os;
}

int main(void)
{
	Point* ptr = new Point(3, 4);
	Point* arr = new Point[3];
	delete ptr;
	delete[]arr;
	return 0;
}