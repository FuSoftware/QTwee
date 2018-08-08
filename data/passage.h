#ifndef PASSAGE_H
#define PASSAGE_H

#include <QVector>
#include <QString>

class Passage
{
public:
    Passage(QString name, QString text = "", QStringList tags = QStringList());
    QString getName();
    QString getText() const;
    QStringList getLines();
    unsigned int getCharacterCount();
    void addLine(QString line);


private:
    QVector<Passage*> linkedTo;
    QStringList tags;
    QString name;
    QString text;
};

#endif // PASSAGE_H
