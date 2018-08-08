#include "story.h"
#include "passage.h"

Story::Story()
{

}

void Story::addPassage(Passage* p)
{
    this->passages.insert(p->getName(),p);
}

void Story::addPassages(QVector<Passage*> p)
{
    for(int i=0;i<p.size();i++)
    {
        this->addPassage(p[i]);
    }
}

int Story::getPassagesCount() const
{
    return this->passages.size();
}

bool Story::hasPassage(QString name)
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
        QStringList lines = p->getLines();

        for(QString line : lines)
        {
            if(line.contains(":"))
            {
                QStringList l = line.split(":");
                this->metadata.insert(l[0],l[1]);
            }
        }
    }
}

Passage* Story::getPassage(QString name)
{
    return this->hasPassage(name) ? this->passages[name] : nullptr;
}

QHash<QString, QString> Story::getMetaData()
{
    return this->metadata;
}

QString Story::getMetaDataItem(QString key) const
{
    return this->metadata[key];
}

QString Story::getName() const
{
    return this->name;
}

QString Story::getIfid() const
{
    return this->ifid;
}
