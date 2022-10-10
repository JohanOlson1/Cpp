## 9. Software Testing

**Software verification** (a.k.a. **software testing**) is the process of determining whether or not the software works as expected in all cases.

##### Test your programs in small pieces

Testing a small part of your code in isolation to ensure that “unit” of code is correct is called **unit testing**. Each **unit test** is designed to ensure that a particular behavior of the unit is correct.

**Best practice**:  Write your program in small, well defined units (functions or classes), compile often, and test your code as you go.

##### Informal testing

One way you can test code is to do informal testing as you write the program. After writing a unit of code (a function, a class, or some other discrete “package” of code), you can write some code to test the unit that was just added, and then erase the test once the test passes.

##### Preserving your tests

Although writing temporary tests is a quick and easy way to test some code, it doesn’t account for the fact that at some point, you may want to test that same code again later. 

Create a test function, 

### Automate test functions

Writing a test function that contains both the tests AND the expected answers and compares them so we don’t have to.

#### **Unit testing frameworks**

Because writing functions to exercise other functions is so common and useful, there are entire frameworks (called **unit testing frameworks**) that are designed to help simplify the process of writing, maintaining, and executing unit tests.

#### Integration testing

Once each of your units has been tested in isolation, they can be integrated into your program and retested to make sure they were integrated properly.

### Code Coverage

The term **code coverage** is used to describe how much of the source code of a program is executed while testing. 

#### Statement coverage

The term **statement coverage** refers to the percentage of statements in your code that have been exercised by your testing routines.

While aiming for 100% statement coverage is good, it’s not enough to ensure correctness.

#### **Branch coverage**

**Branch coverage** refers to the percentage of branches that have been executed, each possible branch counted separately.

**Best practice**: Aim for 100% branch coverage of your code.

#### **Loop coverage**

**Loop coverage** (informally called **the 0, 1, 2 test**) says that if you have a loop in your code, you should ensure it works properly when it iterates 0 times, 1 time, and 2 times. If it works correctly for the 2-iteration case, it should work correctly for all iterations greater than 2.

**Best practice**: Use the `0, 1, 2 test` to ensure your loops work correctly with different number of iterations.

#### **Testing different categories of input**

For integers, make sure you’ve considered how your function handles negative values, zero, and positive values. You should also check for overflow if that’s relevant.

For floating point numbers, make sure you’ve considered how your function handles values that have precision issues (values that are slightly larger or smaller than expected). Good `double` type values to test with are `0.1` and `-0.1` (to test numbers that are slightly larger than expected) and `0.6` and `-0.6` (to test numbers that are slightly smaller than expected).

For strings, make sure you’ve considered how your function handles an empty string (just a null terminator), normal valid strings, strings that have whitespace, and strings that are all whitespace.

If your function takes a pointer, don’t forget to test `nullptr` as well (don’t worry if this doesn’t make sense, we haven’t covered it yet).

**Best practice:** Test different categories of input values to make sure your unit handles them properly.

## m. Random Number Generation

Computers are generally incapable of generating truly random numbers (at least through software). Instead, modern programs typically *simulate* randomness using an algorithm.

To simulate randomness, programs typically use a pseudo-random number generator. A **pseudo-random number generator (PRNG)** is an algorithm that generates a sequence of numbers whose properties simulate a sequence of random numbers.

**Key insight:** All of the values that a PRNG will produce are deterministically calculated from the seed value(s).

#### Algrithms:

An **algorithm** is a finite sequence of instructions that can be followed to solve some problem or produce some useful result.

An algorithm is considered to be **stateful** if it retains some information across calls. Conversely, a **stateless** algorithm does not store any information (and must be given all the information it needs to work with when it is called).

#### What makes a good PRNG?

- The PRNG should generate each number with approximately the same probability.
- The method by which the next number in the sequence is generated shouldn’t be predictable.
- The PRNG should have a good dimensional distribution of numbers. (This means the PRNG should return numbers across the entire range of possible results at random.)
- The PRNG should have a high period for all seeds

All PRNGs are periodic, which means that at some point the sequence of numbers generated will begin to repeat itself. The length of the sequence before a PRNG begins to repeat itself is known as the **period**.

- The PRNG should be efficient

Every PRNG algorithm has strengths and weaknesses that might make it more or less suitable for a particular applications, so selecting the right algorithm for your application is important.

### Randomization in C++

The randomization capabilities in C++ are accessible via the `<random>` header of the standard library. Within the random library, there are 6 PRNG families available for use (as of C++20):

![image-20221006125257107](C:\Users\Johan\AppData\Roaming\Typora\typora-user-images\image-20221006125257107.png)

**So we should use Mersenne Twister, right?** Probably. For most applications, Mersenne Twister is fine, both in terms of performance and quality.

If you are developing an application that requires the highest quality random results (e.g. a statistical simulation), the fastest results, or one where non-predictability is important (e.g. cryptography), you’ll need to use a 3rd party library.

#### Marsenne Twister:

Probably the most popular PRNG across all programming languages. Although it is a bit old by today’s standards, it generally produces quality results and has decent performance.  

Two types:

- `mt19937` is a Mersenne Twister that generates 32-bit unsigned integers
- `mt19937_64` is a Mersenne Twister that generates 64-bit unsigned integers

Example:

```cpp
#include <iostream>
#include <random> // for std::mt19937

int main()
{
	std::mt19937 mt; // Instantiate a 32-bit Mersenne Twister

	// Print a bunch of random numbers
	for (int count{ 1 }; count <= 40; ++count)
	{
		std::cout << mt() << '\t'; // generate a random number

		// If we've printed 5 numbers, start a new row
		if (count % 5 == 0)
			std::cout << '\n';
	}

	return 0;
}
```

**Tip:** `mt()` is a concise syntax for calling the function `mt.operator()`, which for these PRNG types has been defined to return the next random result in the sequence. The advantage of using `operator()` instead of a named function is that we don’t need to remember the function’s name, and the concise syntax is less typing.

**As an aside:** For the stats geeks: a random number distribution is just a probability distribution designed to take PRNG values as input.

##### Uniform Distribution:

```cpp
#include <iostream>
#include <random> // for std::mt19937 and std::uniform_int_distribution

int main()
{
	std::mt19937 mt;

	// Create a reusable random number generator that generates uniform numbers between 1 and 6
	std::uniform_int_distribution die6{ 1, 6 }; // for C++14, use std::uniform_int_distribution<> die6{ 1, 6 };

	// Print a bunch of random numbers
	for (int count{ 1 }; count <= 40; ++count)
	{
		std::cout << die6(mt) << '\t'; // generate a roll of the die here

		// If we've printed 10 numbers, start a new row
		if (count % 10 == 0)
			std::cout << '\n';
	}

	return 0;
}
```

If you run the program multiple times, you will note that it prints the same numbers every time! While each number in the sequence is random with regards to the previous one, the entire sequence is not random at all! Each run of our program produces the exact same result.

Given any starting seed number, PRNGs will always generate the same sequence of numbers from that seed as a result.

We really don’t need our seed to be a random number -- we just need to pick something that changes each time the program is run

There are two methods that are commonly used to do this:



1. Use the system clock

C++ have a long history of PRNGs being seeded using the current time (using the `std::time()` function). 

```cpp
static_cast<unsigned int>( std::chrono::steady_clock::now().time_since_epoch().count() )
```

The downside of this approach is that if the program is run several times in quick succession, the seeds generated for each run won’t be that different, which can impact the quality of the random results from a statistical standpoint. For normal programs, this doesn’t matter, but for programs that require high quality, independent results, this method of seeding may be insufficient.



2. Use the system’s random device

```cpp
std::random_device{}()
```

One potential problem with `std::random_device`: it isn’t required to be non-deterministic, meaning it *could*, on some systems, produce the same sequence every time the program is run, which is exactly what we’re trying to avoid. There was a [bug in MinGW](https://gcc.gnu.org/bugzilla/show_bug.cgi?id=85494) (fixed in GCC 9.2) that would do exactly this, making `std::random_device` useless.

**Best practice**: Use `std::random_device` to seed your PRNGs (unless it’s not implemented properly for your target compiler/architecture).

##### Q: If std::random_device is random itself, why don’t we just use that instead of Mersenne Twister?

Because std::random_device is implementation defined, we can’t assume much about it. It may be expensive to access or it may cause our program to pause while waiting for more random numbers to become available. The pool of numbers that it draws from may also be depleted quickly, which would impact the random results for other applications requesting random numbers via the same method. For this reason, std::random_device is better used to seed other PRNGs rather than as a PRNG itself.

##### Only seed a PRNG once

**Best practice**: Only seed a given pseudo-random number generator once, and do not reseed it.

Common mistake:

```cpp
#include <iostream>
#include <random>

int getCard()
{
    std::mt19937 mt{ std::random_device{}() }; // this gets created and seeded every time the function is called
    std::uniform_int_distribution card{ 1, 52 };
    return card(mt);
}

int main()
{
    std::cout << getCard();

    return 0;
}
```

##### Random numbers across multiple files:

The better option in most cases is to create a global random number generator (inside a namespace!). Remember how we told you to avoid non-const global variables? This is an exception.

```cpp
#include <iostream>
#include <random> // for std::mt19937 and std::random_device

namespace Random // capital R to avoid conflicts with functions named random()
{
	std::mt19937 mt{ std::random_device{}() };

	int get(int min, int max)
	{
		std::uniform_int_distribution<> die{ min, max }; // we can create a distribution in any function that needs it
		return die(mt); // and then generate a random number from our global generator
	}
}

int main()
{
	std::cout << Random::get(1, 6) << '\n';
	std::cout << Random::get(1, 10) << '\n';
	std::cout << Random::get(1, 20) << '\n';

	return 0;
}
```

##### **Debugging programs that use random numbers**

Programs that use random numbers can be difficult to debug because the program may exhibit different behaviors each time it is run. Sometimes it may work, and sometimes it may not. When debugging, it’s helpful to ensure your program executes the same (incorrect) way each time. That way, you can run the program as many times as needed to isolate where the error is.

For this reason, when debugging, it’s a useful technique to seed your PRNG with a specific value (e.g. `5`) that causes the erroneous behavior to occur. This will ensure your program generates the same results each time, making debugging easier. Once you’ve found the error, you can use your normal seeding method to start generating randomized results again.

## x. Error Handling (see 7.14-7.17 TODO:)

Most errors in a program don’t occur as the result of inadvertently misusing language features -- rather, most errors occur due to faulty assumptions made by the programmer and/or a lack of proper error detection/handling.

Many new programmers write code and then only test the **happy path**: only the cases where there are no errors. But you should also be planning for and testing your **sad paths**, where things can and will go wrong.

#### **Fatal errors**

If the error is so bad that the program can not continue to operate properly, this is called a **non-recoverable** error (also called a **fatal error**)

#### Exceptions

Because returning an error from a function back to the caller is complicated (and the many different ways to do so leads to inconsistency, and inconsistency leads to mistakes), C++ offers an entirely separate way to pass errors back to the caller: `exceptions`.

#### Input validation

**Author’s note**: Input validation is important and useful, but it also tends to make examples more complicated and harder to follow. Accordingly, in future lessons, we will generally not do any kind of input validation unless it’s relevant to something we’re trying to teach.

#### Assert and static_assert

Todo:

**Best practice**: Use assertions to document cases that should be logically impossible.

## v. Libraries

#### **std::string**

The easiest way to work with strings and string objects in C++ is via the `std::string` type, which lives in the <string> header. Example:

```cpp
#include <string>

int main()
{
    std::string name { "Alex" }; // initialize name with string literal "Alex"
    name = "John";              // change name to "John"

    return 0;
}
```

**Use std::getline() to input text**

```cpp
    std::getline(std::cin >> std::ws, name); // read a full line of text into name
```

**Best practice**: If using `std::getline()` to read strings, use `std::cin >> std::ws` input manipulator to ignore leading whitespace.

Get length of a string in identifier name:

```cpp
std::cout << name << " has " << name.length() << " characters\n";
```

Returns an unsigned integral value (most likely of type `size_t`). If you want to assign the length to an `int` variable, you should `static_cast` it to avoid compiler warnings about signed/unsigned conversions: 

```cpp
int length { static_cast<int>(name.length()) };
```

#### std::string_view

Lives in the <string_view> header)

Unlike fundamental types, initializing (or copying) a `std::string` is slow. 

**Best practice:** Do not pass `std::string` by value, as making copies of `std::string` is expensive. Prefer `std::string_view` parameters. 

**Best practice:** Prefer `std::string_view` over `std::string` when you need a read-only string, especially for function parameters.



## k. High performance

**As an aside:** You might assume that types that use less memory would be faster than types that use more memory. This is not always true. CPUs are often optimized to process data of a certain size (e.g. 32 bits), and types that match that size may be processed quicker. On such a machine, a 32-bit *int* could be faster than a 16-bit *short* or an 8-bit *char*.

## b. Bit Manipulation

Chapter O

## z. Preprocessor

When you compile your code, you might expect that the compiler compiles the code exactly as you’ve written it. This actually isn’t the case.

Prior to compilation, the code file goes through a phase known as **translation**. 

#### Includes:

When you *#include* a file, the preprocessor replaces the #include directive with the contents of the included file. The included contents are then preprocessed (along with the rest of the file), and then compiled.

#### Conditional compilation:

The *conditional compilation* preprocessor directives allow you to specify under what conditions something will or won’t compile. There are quite a few different conditional compilation directives, but we’ll only cover the three that are used by far the most here: *#ifdef*, *#ifndef*, and *#endif*.

```cpp
#include <iostream>

#define PRINT_JOE

int main()
{
#ifdef PRINT_JOE
    std::cout << "Joe\n"; // will be compiled since PRINT_JOE is defined
#endif

#ifdef PRINT_BOB
    std::cout << "Bob\n"; // will be ignored since PRINT_BOB is not defined
#endif

    return 0;
}
```

Once the preprocessor has finished, all defined identifiers from that file are discarded. This means that directives are only valid from the point of definition to the end of the file in which they are defined. Directives defined in one code file do not have impact on other code files in the same project.

## y. Extras

1. Naming collisions occur in two cases:

   1. Two (or more) identically named functions (or global variables) are introduced into separate files belonging to the same program. This will result in a linker error, as shown above.

   2. Two (or more) identically named functions (or global variables) are introduced into the same file. This will result in a compiler error.

2. In C++, any name that is not defined inside a class, function, or a namespace is considered to be part of an implicitly defined namespace called the **global namespace** (sometimes also called **the global scope**).

   **Key insight:** When you use an identifier that is defined inside a namespace (such as the *std* namespace), you have to tell the compiler that the identifier lives inside the namespace.

   The :: symbol is an operator called the **scope resolution operator**.

   **Best practice:** Use explicit namespace prefixes to access identifiers defined in a namespace.

   ```cpp
   using namespace std; // this is a using directive that allows us to access names in the std namespace with no namespace prefix
   ```

**Warning:** Avoid using-directives (such as *using namespace std;*) at the top of your program or in header files. They violate the reason why namespaces were added in the first place.

## x. General Tips

- A preferred solution. Save input values, do not overwrite them. Avoid creating new variables when possible. Output answer directly.

  