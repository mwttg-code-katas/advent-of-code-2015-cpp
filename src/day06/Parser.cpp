#include "Parser.h"
#include "Light.h"
#include "filereader.h"

std::vector<Command> read_file(const std::string &filename) {
    const std::vector<std::string> lines = filereader::read_lines(filename);

    std::smatch match;
    std::vector<Command> result;
    for (const std::string &line: lines) {
        std::regex_search(line.begin(), line.end(), match, REGEX);
        const Light light = transformToLight(match[1]);
        const int top = std::stoi(match[2]);
        const int left = std::stoi(match[3]);
        const int bottom = std::stoi(match[4]);
        const int right = std::stoi(match[5]);
        const Area area = Area{top, left, bottom, right};
        const Command command = Command{light, area};
        result.push_back(command);
    }

    return result;
}
