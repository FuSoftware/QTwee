#include "tweeparser.h"
#include "data/passage.h"
#include <iostream>

TweeParser::TweeParser()
{
    this->reg_head.setPattern(this->pat_head);
    this->reg_head_tags.setPattern(this->pat_head_tags);
}

QVector<Passage*> TweeParser::parseFile(QFile &file)
{
    QTextStream in(&file);
    QVector<Passage*> passages;
    this->current_file = file.fileName();
    this->current_line = 1;

    while(!in.atEnd())
    {
        QString line = in.readLine();
        if(line.startsWith("::"))
        {
            //If the line is a header
            passages.push_back(passageFromHeader(line));
        }
        else if(passages.size() > 0)
        {
            //If the line is regular text
            passages[passages.size()-1]->addLine(line);
        }

        this->current_line++;
    }
    this->current_line = -1;
    this->current_file = "";
    return passages;
}

QVector<Passage*> TweeParser::parseFile(QString file)
{
    QFile f(file);
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        std::cerr << "Could not open file " << file.toStdString() << std::endl;
        return QVector<Passage*>();
    }
    QVector<Passage*> p = this->parseFile(f);
    f.close();
    return p;
}

QVector<Passage*> TweeParser::parseFiles(QStringList files)
{
    QVector<Passage*> p;
    for(QString f : files)
    {
        QVector<Passage*> p_temp = this->parseFile(f);
        for(Passage* pass : p_temp)
        {
            p.append(pass);
        }
    }
    return p;
}

Passage* TweeParser::passageFromHeader(QString line)
{
    QString name;
    QStringList tags;

    QRegularExpressionMatch m_head = this->reg_head.match(line);
    QRegularExpressionMatch m_head_tags = this->reg_head_tags.match(line);

    if(m_head_tags.hasMatch())
    {
        //If the header contains tags
        name = m_head_tags.captured(1);
        tags = m_head_tags.captured(2).split(" ");
    }
    else if(m_head.hasMatch())
    {
        //If the header does not contain tags
        name = m_head.captured(1);
    }
    else
    {
        //If the header failed parsing
        std::cerr << "Error parsing passage header on line " << this->current_line << " in file " << this->current_file.toStdString() << std::endl;
        return nullptr;
    }

    return new Passage(name, "", tags);
}
