#include "commandlineparser.h"

CommandLineParser::CommandLineParser(QStringList argv)
{
    this->parser.addOptions(this->buildOptions());
    this->parser.addHelpOption();
    this->parser.setApplicationDescription("Command line compile for Twee files, roughly inspired by the TWeeGo compiler.");
    this->parse(argv);
}

void CommandLineParser::parse(QStringList argv)
{
    if(!argv.empty())
    {
        this->parser.process(argv);
    }
}

void CommandLineParser::parse(QCoreApplication app)
{
    this->parser.process(app);
}

QList<QCommandLineOption> CommandLineParser::buildOptions()
{
    QList<QCommandLineOption> l =
    {
        {
            {"o", "output"},
            QCoreApplication::translate("main", "Outputs to file instead of terminal"),
            QCoreApplication::translate("main", "terminal")
        },{
            {"f", "format"},
            QCoreApplication::translate("main", "Story Format to use"),
            QCoreApplication::translate("main", "harlowe-2")
        },{
            {"s", "source"},
            QCoreApplication::translate("main", "Source folder or file"),
            QCoreApplication::translate("main", "./")
        }
    };

    return l;
}

bool CommandLineParser::hasHtmlOutput()
{
    return this->parser.isSet("o");
}

bool CommandLineParser::hasSource()
{
    return this->parser.isSet("s");
}

bool CommandLineParser::hasStoryFormat()
{
    return this->parser.isSet("f");
}

QString CommandLineParser::getStoryFormat()
{
    return this->parser.value("f");
}

QString CommandLineParser::getHtmlOutput()
{
    return this->parser.value("o");
}

QString CommandLineParser::getSource()
{
    return this->parser.value("s");
}
