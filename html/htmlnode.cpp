#include "htmlnode.h"
#include <sstream>

HTMLNode::HTMLNode(std::string tag)
{
    this->setTag(tag);
}

void HTMLNode::setAttribute(std::string name, std::string content)
{
    this->attributes.emplace(name, content);
}

std::string HTMLNode::getAttribute(std::string name)
{
    return this->attributes[name];
}

void HTMLNode::setText(std::string text)
{
    this->text = text;
}

void HTMLNode::setTag(std::string tag)
{
    this->tag = tag;
}

void HTMLNode::addChild(HTMLNode* node)
{
    this->children.push_back(node);
}

std::string HTMLNode::printAttributes()
{
    if(!this->attributes.empty())
    {
        std::ostringstream oss;
        oss << " ";
        for(auto kv : this->attributes)
        {
            oss << kv.first << "\"" << kv.second << "\" ";
        }
        return oss.str();
    }
    else
    {
        return "";
    }
}

std::string HTMLNode::toString()
{
    std::ostringstream oss;

    if(this->children.empty() && this->text == "")
    {
        //Empty tag
        oss << "<" << this->tag << "/>";
    }
    else
    {
        //Tag has some content
        oss << "<" << this->tag << this->printAttributes() << ">";

        for(auto child : this->children)
        {
            oss << child->toString();
        }

        oss << this->text;

        oss << "</" << this->tag << ">";
    }

    return oss.str();
}
