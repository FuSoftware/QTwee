#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <fstream>

class Utils
{
public:
    Utils();
    static std::ifstream::pos_type filesize(const std::string& filename);
    static bool file_exists(const std::string& name);

};

#endif // UTILS_H
