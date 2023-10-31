#include<iostream>

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y)
	{
	}
	void ShowPosition()const
	{
		std::cout << '[' << xpos << ', ' << ypos << ']' << std::endl;
	}
	friend std::ostream& operator<<(std::ostream&, const Point&);
	friend std::istream& operator>>(std::istream&, Point& pos);
};

std::istream& operator>>(std::istream& is, Point& pos)
{
	is >> pos.xpos >> pos.ypos;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << std::endl;
	return os;
}

int main(void)
{
	Point pos1;
	std::cout << "x,y 좌표 순으로 입력: ";
	std::cin >> pos1;
	std::cout << pos1;

	Point pos2;
	std::cout << "x, y 좌표순으로 입력 : ";
	std::cin >> pos2;
	std::cout << pos2;
	return 0;
}