#include "passage.h"

Passage::Passage(QString name, QString text, QStringList tags)
{
    this->name = name;
    this->text = text;
    this->tags = tags;
}

void Passage::addLine(QString line)
{
    this->text.append("\n");
    this->text.append(line);
}

QString Passage::getName()
{
    return this->name;
}

QString Passage::getText() const
{
    return this->text.trimmed();
}

unsigned int Passage::getCharacterCount()
{
    return this->text.length();
}

QStringList Passage::getLines()
{
    return this->getText().split("\n");
}

bool Passage::hasTag(QString tag)
{
    return this->tags.contains(tag);
}
