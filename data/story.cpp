#include "story.h"
#include "passage.h"

Story::Story()
{

}

void Story::addPassage(Passage* p)
{

}

void Story::addPassages(std::vector<Passage*> p)
{

}


int Story::getPassagesCount()
{
    return this->passages.size();
}


bool Story::hasPassage(std::string name)
{
    return this->passages.find(name) != this->passages.end();
}

Passage* Story::getPassage(std::string name)
{
    if(this->hasPassage(name))
    {
        return nullptr;
    }
    else
    {
        return this->passages[name];
    }
}
