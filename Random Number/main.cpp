#include <iostream>
#include <random>
#include <chrono>

int main()
{
	std::mt19937 mt{ std::random_device{}() };

	// Create a resuable random generator that generates uniform numbers between 1 and 6
	std::uniform_int_distribution<> die6{ 1, 6 };

	// print some random numbers
	for (int count{ 1 }; count <= 40; ++count)
	{
		std::cout << die6(mt) << '\t';
	
	// After generating 10 numbers, print new row
		if (count % 10 == 0)
			std::cout << '\n';
	}

	return 0;
}