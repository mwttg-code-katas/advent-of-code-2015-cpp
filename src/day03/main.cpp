#include "filereader.h"
#include "Position.h"

#include <iostream>
#include <sstream>
#include <chrono>
#include <unordered_map>

unsigned long puzzle01();

unsigned long puzzle02();

std::string extractCharacters(const std::string &input, int offset);

std::unordered_map<Position, int> getDeliveryPerPosition(const std::string &commands);


int main() {
    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::high_resolution_clock::now();
    const unsigned long solution_puzzle01 = puzzle01();
    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "The solution of puzzle 01 is: " << solution_puzzle01 << " this took " << duration << " to execute."
            << std::endl;

    std::chrono::time_point<std::chrono::system_clock> start2 = std::chrono::high_resolution_clock::now();
    const unsigned long solution_puzzle02 = puzzle02();
    std::chrono::time_point<std::chrono::system_clock> end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration2 = end2 - start2;
    std::cout << "The solution of puzzle 02 is: " << solution_puzzle02 << " this took " << duration2 << " to execute."
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

unsigned long puzzle02() {
    const std::string input = filereader::read_file("day03-input.txt");
    const std::string santaCommands = extractCharacters(input, 0);
    const std::string roboCommands = extractCharacters(input, 1);
    std::unordered_map<Position, int> santaDeliveries = getDeliveryPerPosition(santaCommands);
    std::unordered_map<Position, int> roboDeliveries = getDeliveryPerPosition(roboCommands);
    santaDeliveries.merge(roboDeliveries);
    return santaDeliveries.size();
}

std::string extractCharacters(const std::string &input, int offset) {
    std::string result;
    result.reserve(input.size() / 2); // better performance
    for (int index = offset; index < input.size(); index += 2) {
        result.push_back(input[index]);
    }
    return result;
}

std::unordered_map<Position, int> getDeliveryPerPosition(const std::string &commands) {
    Position currentPosition = {0, 0};
    std::unordered_map<Position, int> deliveryPerPosition{{currentPosition, 1}};
    for (const char command: commands) {
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
    return deliveryPerPosition;
}
