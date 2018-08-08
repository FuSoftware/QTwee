#ifndef COMMANDLINEPARSER_H
#define COMMANDLINEPARSER_H

#include <QStringList>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QVector>

class CommandLineParser
{
public:
    CommandLineParser(QStringList argv = QStringList());
    void parse(QStringList argv);
    void parse(QCoreApplication app);

    bool hasHtmlOutput();
    bool hasSource();
    bool hasStoryFormat();

    QString getStoryFormat();
    QString getHtmlOutput();
    QString getSource();

private:
    QList<QCommandLineOption> buildOptions();
    QCommandLineParser parser;
};

#endif // COMMANDLINEPARSER_H
