#include "passage.h"

Passage::Passage(std::string name, std::string text, std::vector<std::string> tags)
{
    this->name = name;
    this->text = text;
    this->tags = tags;
}

void Passage::addLine(std::string line)
{
    this->text += "\n" + line;
}

std::string Passage::getName()
{
    return this->name;
}

unsigned int Passage::getCharacterCount()
{
    return this->text.length();
}
