#ifndef STORYBUILDER_H
#define STORYBUILDER_H

#include <QString>
#include <QVector>

class HTMLNode;
class Story;
class StoryBuilder
{
public:
    StoryBuilder(Story *story);

    void compile(QString file);
    HTMLNode* getHtml();

private:
    Story* story;

    HTMLNode* buildBody();
    HTMLNode* buildHead();

};

#endif // STORYBUILDER_H
