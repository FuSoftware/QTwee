#include "storybuilder.h"
#include "html/htmlnode.h"
#include "data/story.h"

#include <QFile>
#include <QXmlStreamWriter>

StoryBuilder::StoryBuilder(Story *story)
{
    this->story = story;
}

void StoryBuilder::compile(QString file)
{

}

HTMLNode* StoryBuilder::getHtml()
{

}
