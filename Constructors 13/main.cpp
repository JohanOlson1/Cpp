#include <iostream>
#include <string> # // std::string

class Ball
{
private:
	std::string m_color{};
	double m_radius{};
public:
	Ball(double radius = 10.0)
	{
		m_color = "black";
		m_radius = radius;
	}

	Ball(std::string color = "black", double radius = 10.0) // Default constructor with both parameters
	{
		m_color = color;
		m_radius = radius;
	}

	void print()
	{
		std::cout << "The ball's color is " << m_color << " and the size is " << m_radius << '\n';
	}
};

int main()
{
	Ball ball{50.0};

	ball.print();

	return 0;
}