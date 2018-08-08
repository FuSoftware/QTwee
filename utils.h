#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <sstream>

class Utils
{
public:
    Utils();
    static std::ifstream::pos_type filesize(const std::string& filename);
    static bool file_exists(const std::string& name);
    static std::vector<std::string> split(const std::string &s, char delim);
    static std::string trim(const std::string &s);

private:
    static const std::string WHITESPACE;

};

#endif // UTILS_H
