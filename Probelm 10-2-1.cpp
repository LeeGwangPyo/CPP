#include<iostream>

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y)
	{ }
	void ShowPosition() const
	{
		std::cout << '[' << xpos << ", " << ypos << ']' << std::endl;
	}
	Point operator-() const
	{
		return Point(-xpos, -ypos);
	}
};

int main(void)
{
	Point pos1(10, 20);
	Point pos2 = -pos1;
	pos1.ShowPosition();
	pos2.ShowPosition();
	return 0;
}