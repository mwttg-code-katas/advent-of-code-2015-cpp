#include "filereader.h"

#include <iostream>
#include <sstream>
#include <chrono>

std::vector<std::vector<int> > getParsedPuzzleInput(const std::string &filename);

int puzzle01();

int puzzle02();

int main() {
    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::high_resolution_clock::now();
    const int solution_puzzle01 = puzzle01();
    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "The solution of puzzle 01 is: " << solution_puzzle01 << " this took " << duration << " to execute."
            << std::endl;

    std::chrono::time_point<std::chrono::system_clock> start2 = std::chrono::high_resolution_clock::now();
    const int solution_puzzle02 = puzzle02();
    std::chrono::time_point<std::chrono::system_clock> end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration2 = end2 - start2;
    std::cout << "The solution of puzzle 01 is: " << solution_puzzle02 << " this took " << duration2 << " to execute."
            << std::endl;
}

int puzzle01() {
    const std::vector<std::vector<int> > input = getParsedPuzzleInput("day02-input.txt");
    int result = 0;
    for (const std::vector<int> &dimension: input) {
        const int side1 = dimension[0] * dimension[1];
        const int side2 = dimension[1] * dimension[2];
        const int side3 = dimension[2] * dimension[0];
        const int smallestSide = std::min(side1, std::min(side2, side3));
        const int size = (2 * side1) + (2 * side2) + (2 * side3) + smallestSide;
        result = result + size;
    }
    return result;
}

int puzzle02() {
    const std::vector<std::vector<int> > input = getParsedPuzzleInput("day02-input.txt");
    int result = 0;
    for (const std::vector<int> &dimension: input) {
        const int side1 = dimension[0];
        const int side2 = dimension[1];
        const int side3 = dimension[2];
        const int largestSide = std::max(side1, std::max(side2, side3));
        const int bow = side1 * side2 * side3;
        const int ribbonLength = 2 * side1 + 2 * side2 + 2 * side3 - 2 * largestSide + bow;
        result = result + ribbonLength;
    }
    return result;
}


std::vector<std::vector<int> > getParsedPuzzleInput(const std::string &filename) {
    const std::vector<std::string> lines = filereader::read_lines(filename);
    std::vector<std::vector<int> > result;
    for (const std::string &line: lines) {
        std::istringstream ss(line);
        std::string part;
        std::vector<int> intParts;
        while (std::getline(ss, part, 'x')) {
            int number = stoi(part);
            intParts.push_back(number);
        }
        result.push_back(std::move(intParts));
    }
    return result;
}
