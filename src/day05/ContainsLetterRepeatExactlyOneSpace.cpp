#include "ContainsLetterRepeatExactlyOneSpace.h"

bool ContainsLetterRepeatExactlyOneSpace::isValid(const std::string &input) {
    const int length = input.length();
    for (int index = 0; index < length - 2; index++) {
        const char firstLetter = input.at(index);
        const char secondLetter = input.at(index + 2);
        if (firstLetter == secondLetter) {
            return true;
        }
    }

    return false;
}

