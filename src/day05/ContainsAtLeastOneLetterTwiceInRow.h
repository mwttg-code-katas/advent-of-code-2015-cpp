#pragma once

#include "AbstractRule.h"

class ContainsAtLeastOneLetterTwiceInRow final : public AbstractRule {
public:
    bool isValid(const std::string &input) override;
};
