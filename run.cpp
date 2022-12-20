#include "Day03.h"
#include <fstream>
#include <streambuf>
#include <string>
#include <sstream>
#include <iostream>

int main() {
	Day03 day03;
	std::ifstream t("file.txt");
	std::stringstream buffer{};
	buffer << t.rdbuf();
	auto input = buffer.str();
	auto result = day03.getPrioritiesSum(input);
	std::cout << "Day 03 part 1: " << result << std::endl;
}