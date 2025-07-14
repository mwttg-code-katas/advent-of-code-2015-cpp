#include <chrono>
#include <iostream>

#include "Grid.h"
#include "Parser.h"

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
    const std::vector commands = read_file("day06-input.txt");
    Grid grid(1000, 1000);
    for (const Command command : commands) {
        grid.executeCommand(command);
    }
    return grid.countLitLights();
}