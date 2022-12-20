#include "Utilities.h"
#include <string>
#include<map>

char Utilities::findCommonLetter(std::pair<std::string_view, std::string_view> compartments)
{
    std::map<char, int> letterLookup;
    for (auto letter : compartments.first) {
        letterLookup.insert(std::pair<char, int>(letter, 1));
    }
    for (auto letter : compartments.second) {
        if (letterLookup[letter] == 1) {
            return letter;
        }
    }
    return ' ';
}
