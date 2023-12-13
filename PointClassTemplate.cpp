#include<iostream>

template<typename T>
class Point
{
private:
	T xpos, ypos;
public:
	Point(T x = 0, T y = 0) :xpos(x), ypos(y)
	{ }
	void ShowPosition() const
	{
		std::cout << '[' << xpos << ", " << ypos << ']' << std::endl;
	}
};

int main(void)
{
	Point<int> pos1(3, 5);
	pos1.ShowPosition();

	Point<double> pos2(3.5, 6.8);
	pos2.ShowPosition();
	
	Point<char> pos3('P', 'F');
	pos3.ShowPosition();
	return 0;
}