#include<iostream>
#include<cstdlib>

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y)
	{ }
};

class BoundCheck2DIntArray
{
	Point arr;
	int arrlen;
	BoundCheck2DIntArray(const BoundCheck2DIntArray&arr){}
	BoundCheck2DIntArray& operator=(const BoundCheck2DIntArray& arr){}

public:

};