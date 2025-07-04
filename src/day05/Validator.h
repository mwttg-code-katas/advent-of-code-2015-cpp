#pragma once

#include "AbstractRule.h"

#include <vector>
#include <memory>
#include <string>

class Validator {
public:
    Validator();
    bool validate(const std::string& input) const;
    template<typename T> void addRule();
    void clearRules();

private:
    std::vector<std::unique_ptr<AbstractRule>> rules;
};

// I'm not sure why this has to be inside the header file :/
template<typename T>
void Validator::addRule() {
    rules.push_back(std::make_unique<T>());
}

