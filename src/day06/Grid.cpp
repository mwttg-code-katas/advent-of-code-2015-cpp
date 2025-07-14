#include "Grid.h"

#include <vector>

Grid::Grid(int width, int height) {
    this->width = width;
    this->height = height;
    grid = std::vector(height, std::vector(width, 0));
}

void Grid::executeCommand(const Command &command) {
    const Light light = command.light;
    const auto [top, left, bottom, right] = command.area;
    for (int y = top; y <= bottom; y++) {
        for (int x = left; x <= right; x++) {
            switch (light) {
                case Light::on:
                    grid[y][x] = 1;
                    break;
                case Light::off:
                    grid[y][x] = 0;
                    break;
                case Light::toggle:
                    grid[y][x] = 1 - grid[y][x];
                    break;
            }
        }
    }
}

int Grid::countLitLights() const {
    int result = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (grid[y][x] == 1) {
                result = result + 1;
            }
        }
    }
    return result;
}
