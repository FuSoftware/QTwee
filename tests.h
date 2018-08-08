#ifndef TESTS_H
#define TESTS_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "controllers/tweeparser.h"
#include "data/passage.h"
#include "html/htmlnode.h"

class Tests
{
public:
    Tests();

    static void tweeParsing(std::string file);
    static void metadataParsing(std::string file);
    static void testHTML(std::string file);
};

#endif // TESTS_H
