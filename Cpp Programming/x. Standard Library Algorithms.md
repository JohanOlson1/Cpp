# x. Standard Library Algorithms

Because searching, counting, and sorting are such common operations to do, the C++ standard library comes with a bunch of functions to do these things in just a few lines of code. Additionally, these standard library functions come pre-tested, are efficient, work on a variety of different container types, and many support parallelization (the ability to devote multiple CPU threads to the same task in order to complete it faster).

The functionality provided in the algorithms library generally fall into one of three categories:

- **Inspectors** -- Used to view (but not modify) data in a container. Examples include searching and counting.
- **Mutators** -- Used to modify data in a container. Examples include sorting and shuffling.
- **Facilitators** -- Used to generate a result based on values of the data members. Examples include objects that multiply values, or objects that determine what order pairs of elements should be sorted in.

## std::find

[`std::find`](https://en.cppreference.com/w/cpp/algorithm/find) searches for the first occurrence of a value in a container. `std::find` takes 3 parameters: an iterator to the starting element in the sequence, an iterator to the ending element in the sequence, and a value to search for. It returns an iterator pointing to the element (if it is found) or the end of the container (if the element is not found).

```cpp
#include <algorithm>
#include <array>
#include <iostream>

int main()
{
    std::array arr{ 13, 90, 99, 5, 40, 80 };

    std::cout << "Enter a value to search for and replace with: ";
    int search{};
    int replace{};
    std::cin >> search >> replace;

    // Input validation omitted

    // std::find returns an iterator pointing to the found element (or the end of the container)
    // we'll store it in a variable, using type inference to deduce the type of
    // the iterator (since we don't care)
    auto found{ std::find(arr.begin(), arr.end(), search) };

    // Algorithms that don't find what they were looking for return the end iterator.
    // We can access it by using the end() member function.
    if (found == arr.end())
    {
        std::cout << "Could not find " << search << '\n';
    }
    else
    {
        // Override the found element.
        *found = replace;
    }

    for (int i : arr)
    {
        std::cout << i << ' ';
    }

    std::cout << '\n';

    return 0;
}
```

## std::find_if

Sometimes we want to see if there is a value in a container that matches some condition (e.g. a string that contains a specific substring) rather than an exact value. In such cases, `std::find_if` is perfect. The `std::find_if` function works similarly to `std::find`, but instead of passing in a value to search for, we pass in a callable object, such as a function pointer (or a lambda, which we’ll cover later) that checks to see if a match is found.

```cpp
#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

// Our function will return true if the element matches
bool containsNut(std::string_view str)
{
    // std::string_view::find returns std::string_view::npos if it doesn't find
    // the substring. Otherwise it returns the index where the substring occurs
    // in str.
    return (str.find("nut") != std::string_view::npos);
}

int main()
{
    std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };

    // Scan our array to see if any elements contain the "nut" substring
    auto found{ std::find_if(arr.begin(), arr.end(), containsNut) };

    if (found == arr.end())
    {
        std::cout << "No nuts\n";
    }
    else
    {
        std::cout << "Found " << *found << '\n';
    }

    return 0;
}
```

## std::shuffle

[`std::shuffle`](https://en.cppreference.com/w/cpp/algorithm/random_shuffle) takes a list and randomly re-orders its elements.

```cpp
// Observe we don't use const argument since we want to change the array/deck
void shuffleDeck(Deck& deck) // Deck is the array type
{
	std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) }; // Random seed
	std::shuffle(deck.begin(), deck.end(), mt);									   // Shuffle deck, since an array, no need to return
}
```



## Advice

**Best practice**: Unless otherwise specified, do not assume that standard library algorithms will execute in a particular sequence. `std::for_each`, `std::copy`, `std::copy_backward`, `std::move`, and `std::move_backward` have sequential guarantees.

**Best practice**: Favor using functions from the algorithms library over writing your own functionality to do the same thing