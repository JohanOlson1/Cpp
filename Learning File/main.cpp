#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

std::vector<int> calories;

int day1part1() {
	std::ifstream f("Advent_of_Code_1_1.txt");
	std::string temp;
	int totCals = 0;

	while (std::getline(f, temp)) {
		if (temp == "") {
			calories.push_back(totCals);
			totCals = 0;
		}
		else
			totCals += stoi(temp);
	}
	std::sort(calories.begin(), calories.end(), std::greater<>());
	return calories[0];
}

int main()
{
	int largestSum{ 0 };
	std::string myline{};
	std::ifstream myfile("Advent_of_Code_1_1.txt");
	if (myfile.is_open()) {
		std::cout << "File Opened" << std::endl;
		int sum{ 0 };
		while (myfile) {
			std::getline(myfile, myline);
			if (myline != "") {
				std::cout << myline << "\n";
				sum += std::stoi(myline);
			}
			else  {
				if (sum > largestSum) {
					largestSum = sum;
				}
				sum = 0;
			}
		}
	}
	else {
		std::cout << "Could not open file\n";
	}
	
	std::cout << "largest sum is: " << largestSum << "\n";
	std::cout << "largest sum is: " << day1part1() << "\n";

	return 0;
}