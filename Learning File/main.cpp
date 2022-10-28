#include <iostream>

class Point2d
{
private:
	double m_x{};
	double m_y{};

public:
	Point2d(double x = 0.0, double y = 0.0) : m_x{ x }, m_y{ y }
	{}

	void print()
	{
		std::cout << "x: " << m_x << " y: " << m_y << std::endl;
	}
};

int main()
{
	Point2d first{};
	Point2d second{ 3.0, 4.0 };
	first.print();
	second.print();

	return 0;
}