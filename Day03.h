#pragma once
#include <string>
#include <ranges>
#include <string_view>
#include <vector>


class Day03
{
	int getPriority(char letter);
	std::pair<std::string_view, std::string_view> getCompartments(std::string_view rucksack);

public:
	int getPrioritiesSum(std::string input);
	int getPrioritiesSumForGroups(std::string input);
	char getCommonLetter(std::vector<std::string> group);
};

