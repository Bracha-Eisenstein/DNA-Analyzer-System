#include <sstream>
#include "parser.h"

std::vector<std::string> Parser::parse(std::string line)
{
    char delimiter = ' ';
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(line);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}
