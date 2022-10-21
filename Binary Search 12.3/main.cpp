#include <iostream>
#include <cassert> // For assert

// array is the array to search over.
// target is the value we're trying to determine exists or not.
// min is the index of the lower bounds of the array we're searching.
// max is the index of the upper bounds of the array we're searching.
// binarySearch() should return the index of the target element if the target is found, -1 otherwise
int binarySearch(const int* array, int target, int min, int max)
{
    // Iterate until we find target or we can determine it does not exist
    while (min <= max) // If indeces bypass each other, target does not exist
    {
        // Calculate center index, round down if even size of array
        int centerIndex{ min + ( (max - min) / 2 ) }; // No need to static cast to int, it defaults from x.5 to x as we cast to int

        // Check for target using center element, reduce array if not found
        int centerElement{ array[centerIndex] };

        if (centerElement > target)
        {
            max = centerIndex - 1;  // We already tested the center index, no need to check again
        }
        else if (centerElement < target)
        {
            min = centerIndex + 1;  // We already tested the center index, no need to check again
        }
        else
        {
            return centerIndex;     // Target found, return its index
        }
    }
    // Target not found otherwise
    return -1;
}

// Another version of binary search using recursive callback to function
int binarySearchRecursive(const int* array, int target, int min, int max)
{
    // Ensure array exist
    assert(array);

    if (min > max)
        return -1;

    // Calculate center index, round down if even size of array
    int centerIndex{ min + ((max - min) / 2) }; // No need to static cast to int, it defaults from x.5 to x as we cast to int

    // Check for target using center element, reduce array if not found
    int centerElement{ array[centerIndex] };

    if (centerElement > target)
    {
        return binarySearch(array, target, min, centerIndex - 1);
    }
    else if (centerElement < target)
    {
        return binarySearch(array, target, centerIndex + 1, max);
    }
    else
    {
        return centerIndex;     // Target found, return its index
    }
    return -1;
}

int main()
{
    constexpr int array[]{ 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };

    // We're going to test a bunch of values to see if they produce the expected results
    constexpr int numTestValues{ 9 };
    // Here are the test values
    constexpr int testValues[numTestValues]{ 0, 3, 12, 13, 22, 26, 43, 44, 49 };
    // And here are the expected results for each value
    int expectedValues[numTestValues]{ -1, 0, 3, -1, -1, 8, -1, 13, -1 };

    // Loop through all of the test values
    for (int count{ 0 }; count < numTestValues; ++count)
    {
        // See if our test value is in the array
        int index{ binarySearchRecursive(array, testValues[count], 0, static_cast<int>(std::size(array)) - 1) };
        // If it matches our expected value, then great!
        if (index == expectedValues[count])
            std::cout << "test value " << testValues[count] << " passed!\n";
        else // otherwise, our binarySearch() function must be broken
            std::cout << "test value " << testValues[count] << " failed.  There's something wrong with your code!\n";
    }

    return 0;
}