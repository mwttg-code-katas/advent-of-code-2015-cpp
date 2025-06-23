#include "filereader.h"

#include <iostream>
#include <chrono>

int puzzle01();

int main() {
    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::high_resolution_clock::now();
    int solution_puzzle01 = puzzle01();
    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "The solution of puzzle 01 is: " << solution_puzzle01 << " this took " << duration << " to execute."
            << std::endl;
}

int puzzle01() {
    const std::string input = filereader::read_file("input.txt");
    int floor = 0;
    for (const char c: input) {
        if (c == '(') floor++;
        if (c == ')') floor--;
    }
    return floor;
}
