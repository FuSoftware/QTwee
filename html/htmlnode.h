#ifndef HTMLNODE_H
#define HTMLNODE_H

#include <QString>
#include <QVector>
#include <QHash>
#include <QXmlStreamWriter>

class HTMLNode
{
public:
    HTMLNode(QString tag);

    void setAttribute(QString name, QString text);
    QString getAttribute(QString name);

    void setTag(QString tag);
    void setText(QString text);

    void addChild(HTMLNode* node);

    QString getXML(QXmlStreamWriter *writer = 0);

private:
    QString tag;
    QHash<QString, QString> attributes;
    QString text;

    QVector<HTMLNode*> children;

};

#endif // HTMLNODE_H
