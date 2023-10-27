#include<iostream>

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0,int y=0):xpos(x),ypos(y)
	{ }

	friend bool operator==(const Point& pos1,const Point &pos2);
	friend bool operator!=(const Point& pos1, const Point& pos2);
};

bool operator==(const Point& pos1, const Point& pos2)
{
	if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos)
		return true;
	else
		return false;

}
bool operator!=(const Point& pos1, const Point& pos2)
{
	return !(pos1 == pos2);
}

int main(void)
{
	Point pos1(11, 21);
	Point pos2(11, 21);
	Point pos3(10, 32);

	if (pos1 == pos2)
		std::cout << "equal" << std::endl;
	else
		std::cout << "not equal" << std::endl;

	if (pos1 != pos2)
		std::cout << "not equal" << std::endl;
	else
		std::cout << "equal" << std::endl;

	if (pos1 == pos3)
		std::cout << "equal" << std::endl;
	else
		std::cout << "not equal" << std::endl;
	return 0;
}