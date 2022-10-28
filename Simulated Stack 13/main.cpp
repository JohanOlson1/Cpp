#include <iostream>
#include <cassert> // assert

class Stack
{
	int array[10]{};
	int arraySize{};

public:
	void reset()
	{
		arraySize = 0;
	}

	bool push(int input)
	{
		if (arraySize < 10)
		{
			array[arraySize] = input;
			++arraySize;
			return true;
		}
		else
			return false;

	}

	int pop()
	{
		assert(arraySize != 0);

		return array[arraySize--]; // Use -- to remove one element from stack afterwards, as it is "poped"
	}

	void print()
	{
		std::cout << "( ";
		for (int count{ 0 }; count < arraySize; ++count)
		{
			std::cout << array[count] << " ";
		}
		std::cout << " ) \n";
	}

};

int main()
{
	Stack stack;
	stack.reset();

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	return 0;
}