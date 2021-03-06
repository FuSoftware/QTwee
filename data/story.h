#ifndef STORY_H
#define STORY_H

#include <QString>
#include <QVector>
#include <QHash>

class Passage;
class Story
{
public:
    Story();

    void addPassage(Passage* p);
    void addPassages(QVector<Passage*> p);

    void refreshStoryData();
    void refreshMetaData();

    QHash<QString, QString> getMetaData();
    QString getMetaDataItem(QString key) const;

    int getPassagesCount() const;
    bool hasPassage(QString name);
    Passage* getPassage(QString name);

    QString getName() const;
    QString getIfid() const;

private:
    QString name;
    QString ifid;
    QHash<QString, Passage*> passages;
    QHash<QString, QString> metadata;
};

#endif // STORY_H
