#ifndef STORY_H
#define STORY_H

#include <string>
#include <vector>
#include <unordered_map>

class Passage;
class Story
{
public:
    Story();

    void addPassage(Passage* p);
    void addPassages(std::vector<Passage*> p);

    void refreshStoryData();
    void refreshMetaData();

    std::unordered_map<std::string, std::string> getMetaData();
    std::string getMetaDataItem(std::string key);

    int getPassagesCount();
    bool hasPassage(std::string name);
    Passage* getPassage(std::string name);

private:
    std::string name;
    std::string ifid;
    std::unordered_map<std::string, Passage*> passages;
    std::unordered_map<std::string, std::string> metadata;
};

#endif // STORY_H
