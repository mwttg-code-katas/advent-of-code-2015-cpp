#pragma once

#include <string>
#include <vector>

namespace filereader {
    std::vector<std::string> read_lines(const std::string &filename);
    std::string read_file(const std::string &filename);
}
