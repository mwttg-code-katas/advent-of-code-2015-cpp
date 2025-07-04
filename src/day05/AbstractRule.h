#pragma once

#include <string>

class AbstractRule {
public:
    virtual ~AbstractRule() = default;

    virtual bool isValid(const std::string &input) = 0;
};
