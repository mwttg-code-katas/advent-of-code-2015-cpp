#include "filereader.h"

#include <stdexcept>
#include <fstream>
#include <sstream>

namespace filereader {
    std::vector<std::string> read_lines(const std::string &filename) {
        std::ifstream file(filename);
        if (!file) {
            throw std::runtime_error("Can't open file: " + filename);
        }

        std::vector<std::string> lines;
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        return lines;
    }

    std::string read_file(const std::string &filename) {
        const std::ifstream file(filename);
        if (!file) {
            throw std::runtime_error("Can't open file: " + filename);
        }

        std::ostringstream ss;
        ss << file.rdbuf();
        return ss.str();
    }
}
