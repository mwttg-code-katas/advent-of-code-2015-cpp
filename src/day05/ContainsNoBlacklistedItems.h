#pragma once

#include "AbstractRule.h"

#include <set>

class ContainsNoBlacklistedItems final : public AbstractRule {
public:
    bool isValid(const std::string &input) override;
private:
    static const std::set<std::string> BLACK_LIST;
};
