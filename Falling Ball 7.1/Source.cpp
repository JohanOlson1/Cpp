#include <iostream>
#include "constants.h"

// Determine the current height from initial height and time of fall based on Newton's second law
double calculateHeight(double initialHeight, int seconds)
{
	double distanceFallen { myConstants::gravity * seconds * seconds / 2 };
	double heightNow{ initialHeight - distanceFallen }; 

	if (heightNow <= 0)
	{
		return 0.0;				// If ground is reached
	}
	else
	{
		return heightNow;		// If still in air
	}
	
}

// Calculates and prints the current height, if the ball has hit the ground, returns false (no longer in air)
bool calculateAndPrintHeight(double initialHeight, int time)
{
	double heightNow{ calculateHeight(initialHeight, time) };

	std::cout << "At " << time << " seconds, the ball is at height: " << heightNow << " m" << '\n';

	// Check if at ground
	if (heightNow == 0.0)
	{
		return false;
	}
}

int main()
{
	std::cout << "Enter the initial height of tower in meter: ";
	double initialHeight;
	std::cin >> initialHeight;

	bool inAir { true };
	for (int fallTime{ 0 }; inAir; ++fallTime)
	{
		inAir = calculateAndPrintHeight(initialHeight, fallTime);
	}
}

