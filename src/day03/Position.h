#pragma once

#include <functional>

struct Position {
    int x;
    int y;

    bool operator==(const Position& other) const {
        return x == other.x && y == other.y;
    }

    void move_north();
    void move_south();
    void move_east();
    void move_west();
};

namespace std {
    template <>
    struct hash<Position> {
        std::size_t operator()(const Position& p) const noexcept {
            return (std::hash<int>()(p.x) << 1) ^ std::hash<int>()(p.y);
        }
    };
}

