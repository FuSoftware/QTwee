#ifndef STORY_H
#define STORY_H

#include <string>
#include <vector>
#include <map>

class Passage;
class Story
{
public:
    Story();

    int getPassagesCount();
    bool hasPassage(std::string name);
    Passage* getPassage(std::string name);

private:
    std::string name;
    std::map<std::string, Passage*> passages;
};

#endif // STORY_H
