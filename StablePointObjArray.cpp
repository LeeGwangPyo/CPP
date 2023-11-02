#include<iostream>
#include<cstdlib>

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) {}
	friend std::ostream& operator<<(std::ostream& os, const Point& pos);
};

std::ostream& operator<<(std::ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << std::endl;
	return os;
}

class BoundCheckPointArray
{
private:
	Point* arr;
	int arrlen;

	BoundCheckPointArray(const BoundCheckPointArray& arr){}
	BoundCheckPointArray& operator=(const BoundCheckPointArray& arr){}

public:
	BoundCheckPointArray(int len) :arrlen(len)
	{
		arr = new Point[len];
	}
	Point& operator[](int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			std::cout << "Array index out of bound exception" << std::endl;
			exit(1);
		}
		return arr[idx];
	}
	Point operator[](int idx) const
	{
		if (idx < 0 || idx >= arrlen)
		{
			std::cout << "Array index out of bound exception" << std::endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrLen()const { return arrlen; }
	~BoundCheckPointArray() { delete[]arr; }
};

int main(void)
{
	BoundCheckPointArray arr(3);
	arr[0] = Point(3, 4);
	arr[1] = Point(5, 6);
	arr[2] = Point(7, 8);
	for (int i = 0; i < arr.GetArrLen(); i++)
		std::cout << arr[i];
	return 0;
}