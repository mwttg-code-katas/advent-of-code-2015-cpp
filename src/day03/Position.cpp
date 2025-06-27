#include "Position.h"

void Position::move_north() {
    y = y + 1;
}

void Position::move_south() {
    y = y - 1;
}

void Position::move_east() {
    x = x + 1;
}

void Position::move_west() {
    x = x - 1;
}
