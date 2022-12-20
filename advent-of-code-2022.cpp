// advent-of-code-2022.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Day03.h"
#include <sstream>
#include <fstream>

int main()
{
	Day03 day03;
	std::ifstream t("day03-input.txt");
	std::stringstream buffer{};
	buffer << t.rdbuf();
	auto input = buffer.str();
	auto part1 = day03.getPrioritiesSum(input);
	std::cout << "Day 03 part 1: " << part1 << std::endl;
	auto part2 = day03.getPrioritiesSumForGroups(input);
	std::cout << "Day 03 part 2: " << part2 << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
