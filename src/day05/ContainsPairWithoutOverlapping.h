#pragma once

#include "AbstractRule.h"

class ContainsPairWithoutOverlapping final : public AbstractRule {
public:
    bool isValid(const std::string &input) override;
};

