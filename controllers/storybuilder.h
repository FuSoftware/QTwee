#ifndef STORYBUILDER_H
#define STORYBUILDER_H

#include <string>
#include <vector>

class Story;
class StoryBuilder
{
public:
    StoryBuilder(Story *story);

    void compile(std::string file);

private:

};

#endif // STORYBUILDER_H
