#include <iostream>
#include <cmath>

// Class holding coordinates of a point, (x, y)
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

	// Distance from current point to a second point
	double distanceTo(const Point2d& secondPoint)
	{
		return std::sqrt((m_x - secondPoint.m_x)* (m_x - secondPoint.m_x) + (m_y - secondPoint.m_y)* (m_y - secondPoint.m_y));
	}

	friend double distanceFrom(const Point2d& firstPoint, const Point2d& secondPoint);
};

// Distance from one point to another, demonstrating use of friend function
double distanceFrom(const Point2d& firstPoint, const Point2d& secondPoint)
{
	return std::sqrt( (firstPoint.m_x - secondPoint.m_x) * (firstPoint.m_x - secondPoint.m_x) + (firstPoint.m_y - secondPoint.m_y) * (firstPoint.m_y - secondPoint.m_y));
}

int main()
{
	Point2d first{};
	Point2d second{ 3.0, 4.0 };
	first.print();
	second.print();
	std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

	return 0;
}