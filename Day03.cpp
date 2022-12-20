#include "Day03.h"
#include <ranges>
#include <string_view>
#include <iostream>
#include "Utilities.h"
#include <vector>
#include <map>

int Day03::getPriority(char letter)
{
	// 65 - 90 == A - Z
	// 97 - 122 == a - z
	if (letter > 64 && letter < 91) {
		// Upper case letter
		return letter - 38;
	}
	if (letter > 96 && letter < 123) {
		// Lower case letter
		return letter - 96;
	}
	return 0;
}

std::pair<std::string_view, std::string_view> Day03::getCompartments(std::string_view rucksack)
{
	auto compartmentSize = rucksack.length() / 2;
	std::cout << "middle: " << compartmentSize << std::endl;
	auto firstCompartment = rucksack.substr(0, compartmentSize);
	std::cout << "firstCompartment: " << firstCompartment << std::endl;
	auto secondCompartment = rucksack.substr(compartmentSize, compartmentSize); // due to 0 indexing compartmentSize is also where the second compartment starts
	std::cout << "secondCompartment: " << secondCompartment << std::endl;
	return std::pair<std::string_view, std::string_view>(firstCompartment, secondCompartment);
}

int Day03::getPrioritiesSum(std::string input)
{
	int prioritySum = 0;
	for (const auto rucksack : std::views::split(input, '\n')) {
		auto rucksackView = std::string_view{rucksack.begin(), rucksack.end()};
		auto compartments = getCompartments(rucksackView);
		auto commonLetter = Utilities::findCommonLetter(compartments);
		std::cout << "common letter: " << commonLetter << std::endl;
		auto prio = getPriority(commonLetter);
		prioritySum += prio;
	}
	return prioritySum;
}

int Day03::getPrioritiesSumForGroups(std::string input)
{
	int prioritySum = 0;
	std::vector<std::string> group;
	auto rucksacks = std::views::split(input, '\n');
	for (const auto rucksack : rucksacks) {
		auto rucksackView = std::string_view{ rucksack.begin(), rucksack.end() };
		std::string rs = std::string{ rucksackView };
		group.push_back(rs);

		if (group.size() == 3) 
		{
			// find common letter
			auto commonLetter = getCommonLetter(group);
		
			// calculate priority
			prioritySum += getPriority(commonLetter);
		
			// start new group
			group.clear();
		}
	}

	return prioritySum;
}

char Day03::getCommonLetter(std::vector<std::string> group)
{
	std::map<char, int> letterLookup;
	std::string first = group.back();
	group.pop_back(); // remove the element just retrieved

	for (const auto letter : first) {
		letterLookup.insert(std::pair<char, int>(letter, 1));
	}

	std::map<char, int> secondLookup;
	std::string second = group.back();
	group.pop_back();

	for (const auto letter : second) {
		if (letterLookup[letter]) {
			secondLookup.insert(std::pair<char, int>(letter, 1));
		}
	}

	std::string third = group.back();
	group.pop_back();
	for (const auto letter : third) {
		if (secondLookup[letter] == 1) {
			return letter;
		}
	}
	return ' ';
}
