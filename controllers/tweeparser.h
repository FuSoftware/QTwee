#ifndef TWEEPARSER_H
#define TWEEPARSER_H

#include <QString>
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>

class Passage;
class TweeParser
{
public:
    TweeParser();

    QVector<Passage*> parseFile(QFile &file);
    QVector<Passage*> parseFile(QString file);
    QVector<Passage*> parseFiles(QStringList files);

    Passage* passageFromHeader(QString line);

private:
    int current_line = -1;
    QString current_file;

    QString pat_head_tags = "::(.+)\\[(.+)\\]";
    QString pat_head = "::(.+)";
    QRegularExpression reg_head;
    QRegularExpression reg_head_tags;
};

#endif // TWEEPARSER_H
