#pragma once

#include "AbstractRule.h"

class ContainsLetterRepeatExactlyOneSpace final : public AbstractRule {
public:
    bool isValid(const std::string &input) override;
};