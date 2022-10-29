#include <iostream>
#include <numeric>

class Fraction
{
private:
	int m_numerator{ 0 };
	int m_denominator{ 1 };

public:
	Fraction(int num, int den=1) : m_numerator{ num }, m_denominator{ den } 
	{
		// Include reduce to ensure each created fraction is properly reduced
		reduce();
	}

	void print()
	{
		std::cout << m_numerator << "/" << m_denominator << std::endl;
	}

	void reduce()
	{
		int gcd{ std::gcd(m_numerator, m_denominator) };
		m_numerator /= gcd;
		m_denominator /= gcd;
	}

	friend Fraction operator*(const Fraction& f1, const Fraction& f2);
	// Program works without these two but will need to convert from fundamentals, which is slower
	// Can use referenc by value for value since it is a rvalue
	friend Fraction operator*(const Fraction& f1, int value);
	friend Fraction operator*(int value, const Fraction& f2);
};

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
	// Direct access since friend function, both private and constructor
	return Fraction{ f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator};
}

Fraction operator*(const Fraction& f1, int value)
{
	return Fraction{ f1.m_numerator * value, f1.m_denominator };
}

Fraction operator*(int value, const Fraction& f2)
{
	// Use previous overload, since it does same thing
	return Fraction{ f2 * value };
}

int main()
{
	Fraction f1{ 2, 5 };
	f1.print();

	Fraction f2{ 3, 8 };
	f2.print();

	Fraction f3{ f1 * f2 };
	f3.print();

	Fraction f4{ f1 * 2 };
	f4.print();

	Fraction f5{ 2 * f2 };
	f5.print();

	Fraction f6{ Fraction{1, 2} *Fraction{2, 3} *Fraction{3, 4} };
	f6.print();

	Fraction f7{ 0, 6 };
	f7.print();

	return 0;
}