#ifndef HTMLNODE_H
#define HTMLNODE_H

#include <string>
#include <vector>
#include <map>
#include <unordered_map>

class HTMLNode
{
public:
    HTMLNode(std::string tag);

    void setAttribute(std::string name, std::string text);
    std::string getAttribute(std::string name);

    void setTag(std::string tag);
    void setText(std::string text);

    void addChild(HTMLNode* node);

    std::string toString();
    std::string printAttributes();

private:
    std::string tag;
    std::unordered_map<std::string, std::string> attributes;
    std::string text;

    std::vector<HTMLNode*> children;

};

#endif // HTMLNODE_H
