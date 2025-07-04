#pragma once

#include "AbstractRule.h"

class ContainsAtLeastThreeVowelsRule final : public AbstractRule {
public:
    bool isValid(const std::string &input) override;

private:
    static bool isVowel(const char &letter);
};
