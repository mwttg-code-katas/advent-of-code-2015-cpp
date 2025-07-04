#include "ContainsAtLeastOneLetterTwiceInRow.h"
#include "ContainsAtLeastThreeVowelsRule.h"
#include "ContainsNoBlacklistedItems.h"
#include "Validator.h"
#include "filereader.h"

#include <chrono>
#include <iostream>

int puzzle01();

int main() {
    const std::chrono::time_point<std::chrono::system_clock> start = std::chrono::high_resolution_clock::now();
    const int solution_puzzle01 = puzzle01();
    const std::chrono::time_point<std::chrono::system_clock> end = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "The solution of puzzle 01 is: " << solution_puzzle01 << " this took " << duration << " to execute."
            << std::endl;
}

int puzzle01() {
    const std::vector<std::string> lines = filereader::read_lines("day05-input.txt");

    Validator validator;

    validator.clearRules();
    validator.addRule<ContainsAtLeastThreeVowelsRule>();
    validator.addRule<ContainsAtLeastOneLetterTwiceInRow>();
    validator.addRule<ContainsNoBlacklistedItems>();

    int niceStrings = 0;
    for (const std::string &line : lines) {
        bool isValid = validator.validate(line);
        if (isValid) {
            niceStrings = niceStrings + 1;
        }
    }

    return niceStrings;
}
