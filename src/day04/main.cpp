#include "md5.h"

#include <chrono>

const std::string secretKey = "yzbqklnj";

unsigned long puzzle01();
unsigned long puzzle02();

unsigned long mining(int startingZeros);

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
    return mining(5);
}

unsigned long puzzle02() {
    return mining(6);
}

unsigned long mining(int startingZeros) {
    unsigned long miningNumber = 0;
    const std::string zeros(startingZeros, '0');

    while (true) {
        std::string input = secretKey + std::to_string(miningNumber);
        std::string hex = MD5(input).hexdigest();

        if (hex.substr(0, startingZeros) == zeros) {
            return miningNumber;
        }

        miningNumber++;
    }
}
