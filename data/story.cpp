#include "story.h"
#include "passage.h"
#include "utils.h"

Story::Story()
{

}

void Story::addPassage(Passage* p)
{
    this->passages.emplace(p->getName(),p);
}

void Story::addPassages(std::vector<Passage*> p)
{
    for(int i=0;i<p.size();i++)
    {
        this->addPassage(p[i]);
    }
}


int Story::getPassagesCount()
{
    return this->passages.size();
}


bool Story::hasPassage(std::string name)
{
    return this->passages.count(name);
}

void Story::refreshStoryData()
{
    if(this->hasPassage("StoryTitle"))
    {
        this->name = this->getPassage("StoryTitle")->getText();
    }

    this->refreshMetaData();
}

void Story::refreshMetaData()
{
    if(this->hasPassage("StorySettings"))
    {
        this->metadata.clear();

        Passage *p = this->getPassage("StorySettings");
        std::vector<std::string> lines = p->getLines();

        for(auto line : lines)
        {
            int c = line.find(":");
            this->metadata.emplace(line.substr(0,c), line.substr(c+1, line.size()-c));
        }
    }
}

Passage* Story::getPassage(std::string name)
{
    if(this->hasPassage(name))
    {
        return this->passages[name];
    }
    else
    {
        return nullptr;
    }
}

std::unordered_map<std::string, std::string> Story::getMetaData()
{
    return this->metadata;
}

std::string Story::getMetaDataItem(std::string key)
{
    return this->metadata[key];
}
