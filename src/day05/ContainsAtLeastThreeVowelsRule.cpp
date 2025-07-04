#include "ContainsAtLeastThreeVowelsRule.h"

bool ContainsAtLeastThreeVowelsRule::isValid(const std::string &input) {
    int foundVowels = 0;
    for (const char &letter: input) {
        if (isVowel(letter)) {
            foundVowels = foundVowels + 1;
        }
    }
    return foundVowels >= 3;
}

bool ContainsAtLeastThreeVowelsRule::isVowel(const char &letter) {
    if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u') {
        return true;
    }

    return false;
}
