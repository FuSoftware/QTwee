#include "tweeparser.h"
#include "data/passage.h"
#include "utils.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

TweeParser::TweeParser()
{
    this->reg_head = std::regex(this->pat_head);
    this->reg_head_tags = std::regex(this->pat_head_tags);
}

std::vector<Passage*> TweeParser::parseFile(std::string file)
{
    if(!Utils::file_exists(file))
    {
        //If the file doesn't exist
        std::cerr << "File " << file << " not found." << std::endl;
        return std::vector<Passage*>();
    }

    std::ifstream ifs(file);
    std::vector<Passage*> passages;
    this->current_file = file;
    this->current_line = 1;
    std::string line;

    while(std::getline( ifs, line ))
    {
        if(line.find("::") == 0)
        {
            //If the line is a header
            passages.push_back(passageFromHeader(line));
        }
        else if(passages.size() > 0)
        {
            //If the line is regular text
            passages[passages.size()-1]->addLine(line);
        }

        this->current_line++;
    }

    ifs.close();
    this->current_line = -1;
    this->current_file = "";
    return passages;
}

std::vector<Passage*> TweeParser::parseFiles(std::vector<std::string> files)
{
    std::vector<Passage*> passages;

    for(int i=0;i<files.size();i++)
    {
        std::vector<Passage*> p = parseFile(files[i]);
        passages.reserve( passages.size() + p.size() );
        passages.insert( passages.end(), p.begin(), p.end() );
    }

    return passages;
}

Passage* TweeParser::passageFromHeader(std::string line)
{
    std::string name;
    std::vector<std::string> tags;
    std::smatch m;
    if(std::regex_search (line, m, reg_head_tags))
    {
        //If the header contains tags
        name = m[1];
        tags = parseTags(m[2]);
    }
    else if(std::regex_search (line, m, reg_head))
    {
        //If the header does not contain tags
        name = m[1];
    }
    else
    {
        //If the header failed parsing
        std::cerr << "Error parsing passage header on line " << this->current_line << " in file " << this->current_file << std::endl;
        return nullptr;
    }

    return new Passage(name, "", tags);
}

std::vector<std::string> TweeParser::parseTags(std::string taglist)
{
    std::istringstream iss(taglist);
    std::vector<std::string> tokens;
    std::copy(std::istream_iterator<std::string>(iss),
         std::istream_iterator<std::string>(),
         std::back_inserter(tokens));
    return tokens;
}
