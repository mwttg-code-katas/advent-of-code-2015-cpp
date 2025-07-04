#include "ContainsNoBlacklistedItems.h"

const std::set<std::string> ContainsNoBlacklistedItems::BLACK_LIST = {"ab", "cd", "pq", "xy"};

bool ContainsNoBlacklistedItems::isValid(const std::string &input) {
    for (const std::string &item: BLACK_LIST) {
        if (input.find(item) != std::string::npos) {
            return false;
        }
    }
    return true;
}
