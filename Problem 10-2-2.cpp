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
	friend Point operator~(Point& ref);
};

Point operator~(Point& ref)
{
	return Point(ref.ypos, ref.xpos);
}

int main(void)
{
	Point pos1(1, 6);
	Point pos2 = ~pos1;
	pos1.ShowPosition();
	pos2.ShowPosition();
	return 0;
}