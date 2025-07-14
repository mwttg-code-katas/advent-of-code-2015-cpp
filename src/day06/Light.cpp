#include "Light.h"

#include <stdexcept>

Light transformToLight(const std::string &input) {
    if (input == "turn on") {
        return Light::on;
    } else if (input == "turn off") {
        return Light::off;
    } else if (input == "toggle") {
        return Light::toggle;
    } else {
        throw std::invalid_argument("Unknown input");
    }
}
