#include "htmlnode.h"
#include <sstream>

HTMLNode::HTMLNode(QString tag)
{
    this->setTag(tag);
}

void HTMLNode::setAttribute(QString name, QString content)
{
    this->attributes.insert(name, content);
}

QString HTMLNode::getAttribute(QString name)
{
    return this->attributes[name];
}

void HTMLNode::setText(QString text)
{
    this->text = text;
}

void HTMLNode::setTag(QString tag)
{
    this->tag = tag;
}

void HTMLNode::addChild(HTMLNode* node)
{
    this->children.push_back(node);
}

QString HTMLNode::getXML(QXmlStreamWriter *writer)
{
    bool root = false;
    QString output;
    if(!writer)
    {
        root = true;
        writer = new QXmlStreamWriter(&output);
        writer->writeStartDocument();
    }

    if(this->children.empty() && this->text == "")
    {
        //Empty tag
        writer->writeEmptyElement(this->tag);
    }
    else
    {
        //Tag has text
        writer->writeStartElement(this->tag);

        for(QString k : this->attributes.keys())
        {
            writer->writeAttribute(k, this->attributes[k]);
        }

        for(HTMLNode* child : this->children)
        {
            child->getXML(writer);
        }

        writer->writeCharacters(this->text);
        writer->writeEndElement();
    }

    if(root)
    {
        writer->writeEndDocument();
    }

    return output;
}
