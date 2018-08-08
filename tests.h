#ifndef TESTS_H
#define TESTS_H

#include <QString>
#include <QVector>
#include <QFile>
#include <QHash>
#include <QXmlStreamWriter>
#include <iostream>

#include "controllers/tweeparser.h"
#include "data/passage.h"
#include "html/htmlnode.h"
#include "data/format.h"

class Tests
{
public:
    Tests();

    static void tweeParsing(QString file);
    static void metadataParsing(QString file);
    static void testHTML(QString file);
    static void format(QString file);
};

#endif // TESTS_H
