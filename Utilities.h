#pragma once
#include <string_view>

class Utilities
{
public:
	static char findCommonLetter(std::pair<std::string_view, std::string_view> compartments);
};

