#include <iostream>
#include <string>	 // for std::string
#include <vector>	 // for std::vector
#include <algorithm> // for std::sort

// Struct holding student 
struct Student
{
	std::string name{};
	int grade{};
};

// Simplify typing of this type
using Students = std::vector<Student>;

int numberOfStudents()
{
	int numStudents{};
	std::cout << "Amount of students: ";
	std::cin >> numStudents;
	return numStudents;
}

// Do not pass as const, we want to write to the array
// Note: Could be done using for each loop, and without numStudents as input...
void inputStudents(Students& students, int numStudents)
{
	for (int count{ 0 }; count < numStudents; ++count)
	{
		std::cout << "Student #" << count + 1 << " name: ";
		std::cin >> students[count].name;
		std::cout << "Student #" << count + 1 << " grade: ";
		std::cin >> students[count].grade;
	}
}

// See previous comment
void printStudents(const Students& students, int numStudents)
{
	for (int count{ 0 }; count < numStudents; ++count)
	{
		std::cout << students[count].name << " got a grade of " << students[count].grade << '\n';
	}
}

// In order to sort a struct we need compare function, Pass by reference to avoid slow copies.
bool compareStudents(const Student& a, const Student& b)
{
	return (a.grade > b.grade);
}

int main()
{
	// User input to get number of students
	int numStudents{ numberOfStudents() };

	// std::vector to hold students, dynamic memory allocation, amount not known at compile time
	// Static cast to size type to ensure correct type
	Students arrayOfStudents(static_cast<Students::size_type>(numStudents));

	// Let the user input data for each student
	inputStudents(arrayOfStudents, numStudents);

	// Sort students with highest grader first
	std::sort(arrayOfStudents.begin(), arrayOfStudents.end(), compareStudents);

	// Print out each student and their grade
	std::cout << '\n' << "The sorted list of students with their grade: \n";
	printStudents(arrayOfStudents, numStudents);

	return 0;
}