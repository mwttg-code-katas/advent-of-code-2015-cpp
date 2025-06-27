#include "filereader.h"
#include "Position.h"

#include <iostream>
#include <sstream>
#include <chrono>
#include <unordered_map>

unsigned long puzzle01();

int puzzle02();

int main() {
    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::high_resolution_clock::now();
    const unsigned long solution_puzzle01 = puzzle01();
    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "The solution of puzzle 01 is: " << solution_puzzle01 << " this took " << duration << " to execute."
            << std::endl;
}

unsigned long puzzle01() {
    const std::string input = filereader::read_file("day03-input.txt");
    Position currentPosition = {0, 0};
    std::unordered_map<Position, int> deliveryPerPosition{{currentPosition, 1}};
    for (const char command: input) {
        switch (command) {
            case '^':
                currentPosition.move_north();
                break;
            case 'v':
                currentPosition.move_south();
                break;
            case '<':
                currentPosition.move_west();
                break;
            case '>':
                currentPosition.move_east();
                break;
            default:
                exit(255);
        }
        const int deliveries = deliveryPerPosition[currentPosition];
        deliveryPerPosition[currentPosition] = deliveries + 1;
    }
    return deliveryPerPosition.size();
}
