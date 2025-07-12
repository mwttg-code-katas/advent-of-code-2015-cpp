#include "ContainsPairWithoutOverlapping.h"

bool ContainsPairWithoutOverlapping::isValid(const std::string &input) {
    const int length = input.length();
    for (int firstPairIndex = 0; firstPairIndex < length - 3; firstPairIndex++) {
        const char pairOneFirstLetter = input.at(firstPairIndex);
        const char pairOneSecondLetter = input.at(firstPairIndex + 1);

        for (int secondPairIndex = firstPairIndex + 2; secondPairIndex < length - 1; secondPairIndex++) {
            const char pairTwoFistLetter = input.at(secondPairIndex);
            const char pairTwoSecondLetter = input.at(secondPairIndex + 1);

            if (pairOneFirstLetter == pairTwoFistLetter && pairOneSecondLetter == pairTwoSecondLetter) {
                return true;
            }
        }
    }
    return false;
}

