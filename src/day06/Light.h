#pragma once

#include <string>

enum class Light { on, off, toggle };

Light transformToLight(const std::string &input);

