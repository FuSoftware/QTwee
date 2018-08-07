#include "tests.h"

Tests::Tests()
{

}

void Tests::tweeParsing(std::string file)
{
    TweeParser *p = new TweeParser();
    std::vector<Passage*> passages = p->parseFile(file);

    for(int i=0;i<passages.size();i++){
        std::cout << passages[i]->getName() << " : " << passages[i]->getCharacterCount() << std::endl;
    }
}

void Tests::testHTML(std::string file)
{
    HTMLNode *html = new HTMLNode("html");
    HTMLNode *head = new HTMLNode("head");
    HTMLNode *body = new HTMLNode("body");

    HTMLNode *title = new HTMLNode("title");
    title->setText("Test Page");

    HTMLNode *h1 = new HTMLNode("h1");
    h1->setText("I am a header");
    body->setText("I am some text");

    html->addChild(head);
    html->addChild(body);
    head->addChild(title);
    body->addChild(h1);

    std::string data = html->toString();
    std::ofstream out(file);
    out << data;
    out.close();
}
