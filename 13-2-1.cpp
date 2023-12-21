#include<iostream>

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y)
	{ }
	void Setpos(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	void ShowPositon()
	{
		std::cout << '[' << xpos << ", " << ypos << ']' << std::endl;
	}
};

template<typename T>
class SmartPtr
{
private:
	T* posptr;
public:
	SmartPtr(T* ptr) :posptr(ptr) {};
	T& operator*() const { return *posptr; }
	T* operator->() const { return posptr; }
	~SmartPtr() { delete posptr; }

};

int main(void)
{
	SmartPtr<Point> sptr1(new Point(1, 2));
	SmartPtr<Point> sptr2(new Point(3, 4));
	sptr1->ShowPositon();
	sptr2->ShowPositon();
	sptr1->Setpos(10, 20);
	sptr2->Setpos(30, 40);
	sptr1->ShowPositon();
	sptr2->ShowPositon();
	return 0;
}