#pragma once

#include <vector>

#include "Command.h"

class Grid {
public:
    Grid(int width, int height);
    void executeCommand(const Command &command);
    int countLitLights() const;
private:
    std::vector<std::vector<int>> grid;
    int width;
    int height;
};
