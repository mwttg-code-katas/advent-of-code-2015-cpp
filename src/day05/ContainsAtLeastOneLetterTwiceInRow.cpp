#include "ContainsAtLeastOneLetterTwiceInRow.h"

bool ContainsAtLeastOneLetterTwiceInRow::isValid(const std::string &input) {
    char lastLetter = '\0';
    for (const char &letter: input) {
        if (letter == lastLetter) {
            return true;
        }
        lastLetter = letter;
    }

    return false;
}
