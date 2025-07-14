#pragma once

#include <regex>
#include <string>
#include <vector>

#include "Command.h"

inline const std::regex REGEX("(turn off|turn on|toggle) (\\d+),(\\d+) through (\\d+),(\\d+)");

std::vector<Command> read_file(const std::string& filename);
