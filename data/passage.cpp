#include "passage.h"
#include "utils.h"

Passage::Passage(std::string name, std::string text, std::vector<std::string> tags)
{
    this->name = name;
    this->text = text;
    this->tags = tags;
}

void Passage::addLine(std::string line)
{
    this->text += line + "\n";
}

std::string Passage::getName()
{
    return this->name;
}

std::string Passage::getText()
{
    return this->text;
}

unsigned int Passage::getCharacterCount()
{
    return this->text.length();
}

std::vector<std::string> Passage::getLines()
{
    return Utils::split(this->text,'\n');
}
