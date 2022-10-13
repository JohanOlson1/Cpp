#include <iostream>
#include <iterator> // for std::size

int main()
{
	// Example array that is unsorted
	int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8, 1, 2, 3, 4, 1};

	constexpr int arrayLength{ static_cast<int>(std::size(array)) };

	// Bubble Sort Algorithm

	// Initialize these before for loop, saves us from reinitializing each loop
	int stopIndex { arrayLength };  // First iteration goes through whole array (except last one, decrement at loop start)
	bool swapped{ false };			// Initializing is best practice

	// Run sorting iterations atleast as many times as there are numbers in array ( - 1 ) to guarantee sorting
	for (int sortIteration = 1; sortIteration < arrayLength; ++sortIteration)
	{
		// With each iteration, the biggest number remaining gets bubbled to the end of the array, no need to check again
		--stopIndex; 	 // update stopIndex to one less each iteration
		
		swapped = false; // Keep track of whether any elements were swapped this iteration

		// Compare each pair, compare with next, stop before last one due to stopIndex
		for (int index = 0; index < stopIndex; ++index)
		{
			if (array[index] > array[index + 1])
			{
				std::swap(array[index], array[index + 1]);
				swapped = true;
			}
		}
		// If we go through an entire iteration without doing a swap, then we know the array must already be sorted.
		if (!swapped)
		{
			std::cout << "Early termination on iteration " << sortIteration << '\n';
			break;
		}
	}

	// Print Array
	for (int count{ 0 }; count < arrayLength; ++count)
	{
		std::cout << array[count] << " ";
	}

	return 0;
}