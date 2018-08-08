#ifndef PASSAGE_H
#define PASSAGE_H

#include <vector>
#include <string>

class Passage
{
public:
    Passage(std::string name, std::string text = "", std::vector<std::string> tags = std::vector<std::string>());
    std::string getName();
    std::string getText();
    std::vector<std::string> getLines();
    unsigned int getCharacterCount();
    void addLine(std::string line);


private:
    std::vector<Passage*> linkedTo;
    std::vector<std::string> tags;
    std::string name;
    std::string text;
};

#endif // PASSAGE_H
