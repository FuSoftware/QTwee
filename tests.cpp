#include "tests.h"
#include "data/story.h"

#include <QDebug>

Tests::Tests()
{

}

void Tests::tweeParsing(QString file)
{
    TweeParser *p = new TweeParser();
    QVector<Passage*> passages = p->parseFile(file);

    for(int i=0;i<passages.size();i++)
    {
        std::cout << passages[i]->getName().toStdString() << " : " << passages[i]->getCharacterCount() << std::endl;
    }
}

void Tests::metadataParsing(QString file)
{
    TweeParser *p = new TweeParser();
    QVector<Passage*> passages = p->parseFile(file);

    Story *s = new Story();
    s->addPassages(passages);
    s->refreshMetaData();

    QHash<QString, QString> metadata = s->getMetaData();

    for(auto k : metadata.keys())
    {
        std::cout << k.toStdString() << " : " << metadata[k].toStdString() << std::endl;
    }
}

void Tests::testHTML(QString file)
{

    HTMLNode *html = new HTMLNode("html");
    HTMLNode *head = new HTMLNode("head");
    HTMLNode *body = new HTMLNode("body");
    HTMLNode *meta = new HTMLNode("meta");
    meta->setAttribute("charset", "UTF-8");

    HTMLNode *title = new HTMLNode("title");
    title->setText("Test Page");

    HTMLNode *h1 = new HTMLNode("h1");
    h1->setText("I am a header");
    body->setText("I am some text");

    html->addChild(head);
    html->addChild(body);
    head->addChild(title);
    head->addChild(meta);
    body->addChild(h1);

    QFile f(file);
    if (!f.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        std::cerr << "Could not open file " << file.toStdString() << std::endl;
        return;
    }
    QXmlStreamWriter *w = new QXmlStreamWriter(&f);
    html->getXML(w);
    w->writeEndDocument();
    f.close();
}

void Tests::format(QString file)
{
    Format *f = new Format();
    f->loadFile(file);

    qInfo() << f->getName() << f->getVersion() << f->getAuthor();
}
