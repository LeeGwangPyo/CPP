#include<iostream>

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y)
	{
	}
	void ShowPosition() const
	{
		std::cout << '[' << xpos << ", " << ypos << ']' << std::endl;
	}
	Point& operator-=(const Point& ref)
	{
		Point pos(xpos -= ref.xpos, ypos -= ref.ypos);
		return pos;
	}
	Point& operator+=(const Point& ref)
	{
		Point pos(xpos += ref.xpos, ypos -= ref.ypos);
		return pos;
	}
};

int main(void)
{
	Point pos1(10, 20);
	Point pos2(3, 5);
	pos1.ShowPosition();
	pos2.ShowPosition();

	pos1.operator+=(pos2);
	pos1.ShowPosition();

	return 0;
}