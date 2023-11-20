#include<iostream>

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y)
	{
		std::cout << "Point 按眉 积己" << std::endl;
	}
	~Point()
	{
		std::cout << "Point 按眉 家戈" << std::endl;
	}
	void SetPos(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	friend std::ostream& operator<<(std::ostream& os, const Point& pos);
};

std::ostream& operator<<(std::ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << std::endl;
	return os;
}

class SmartPtr
{
private:
	Point* posPtr;
public:
	SmartPtr(Point* ptr) :posPtr(ptr)
	{ }

	Point& operator*()const
	{
		return*posPtr;
	}
	Point* operator->()const
	{
		return posPtr;
	}
	~SmartPtr()
	{
		delete posPtr;
	}
};

int main(void)
{
	SmartPtr stpr1(new Point(1, 2));
	SmartPtr stpr2(new Point(2, 3));
	SmartPtr stpr3(new Point(3, 4));
	std::cout << *stpr1;
	std::cout << *stpr2;
	std::cout << *stpr3;

	stpr1->SetPos(10, 20);
	stpr2->SetPos(30, 40);
	stpr3->SetPos(50, 60);
	std::cout << *stpr1;
	std::cout << *stpr2;
	std::cout << *stpr3;
	return 0;
}