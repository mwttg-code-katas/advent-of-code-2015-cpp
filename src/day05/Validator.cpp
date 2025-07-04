#include "Validator.h"

Validator::Validator() = default;

bool Validator::validate(const std::string& input) const {
    for (const auto& rule : rules) {
        if (!rule->isValid(input)) {
            return false;
        }
    }
    return true;
}

void Validator::clearRules() {
    rules.clear();
}
