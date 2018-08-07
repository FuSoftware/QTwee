#ifndef TWEEPARSER_H
#define TWEEPARSER_H

#include <string>
#include <vector>
#include <regex>

class Passage;
class TweeParser
{
public:
    TweeParser();

    std::vector<Passage*> parseFile(std::string file);
    std::vector<Passage*> parseFiles(std::vector<std::string> files);

    Passage* passageFromHeader(std::string line);
    std::vector<std::string> parseTags(std::string taglist);

private:
    int current_line = -1;
    std::string current_file;

    std::string pat_head_tags = "::(.+)\\[(.+)\\]";
    std::string pat_head = "::(.+)";
    std::regex reg_head;
    std::regex reg_head_tags;
};

#endif // TWEEPARSER_H
