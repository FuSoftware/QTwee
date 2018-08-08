#include <QCoreApplication>
#include "tests.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("my-copy-program");
    QCoreApplication::setApplicationVersion("1.0");

    //Tests::tweeParsing("D:\\Prog\\Tweego\\Stories\\Test Story\\main.tw");
    //Tests::metadataParsing("D:\\Prog\\Tweego\\Stories\\Test Story\\main.tw");
    //Tests::testHTML("test.html");
    //Tests::format("D:\\Prog\\Tweego\\bin\\story-formats\\sugarcube-2\\format.js");
    //Tests::parser(QStringList() << "program.exe" << "-o" << "main.html" << "-s" << "src/twee" << "-f" << "sugarcube-2");
    Tests::projectScanner({"D:\\Prog\\Tweego\\Stories\\001 Blank Template"});

    return 0;
}
